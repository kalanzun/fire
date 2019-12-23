#include "receiver.h"

Receiver::Receiver(Fire *fire, QObject *parent)
    : QObject(parent)
    , fire(fire)
    , tcpSocket(new QTcpSocket(this))
    , timer(new QTimer(this))
{
    connect(timer, &QTimer::timeout, this, &Receiver::timeout);

    connect(tcpSocket, &QIODevice::readyRead, this, &Receiver::read);
    connect(tcpSocket, static_cast<void (QTcpSocket::*)(QAbstractSocket::SocketError)>(&QAbstractSocket::error), this, &Receiver::error);
    //Only Qt >= 5.7 (Ubuntu Xenial on Travis is Qt 5.5)
    //connect(tcpSocket, QOverload<QAbstractSocket::SocketError>::of(&QAbstractSocket::error), this, &Receiver::error);

    connect(fire, &Fire::connectToHost, this, &Receiver::connectToHost);

    connectToHost(fire->getHost());
}

void Receiver::connectToHost(const QString &host)
{
    qDebug() << "connectToHost";
    tcpSocket->abort();
    fire->setMessageText(QString("Verbinde zu %1").arg(host));
    watchdog = false;
    connecting = true;
    tcpSocket->connectToHost(host, 23);
    timer->start(3000);
}

void Receiver::read()
{
    QString raw_data = tcpSocket->readAll();

    qDebug() << raw_data;

    QVector<QStringRef> data = raw_data.splitRef(" ");

    fire->parse(data);

    watchdog = true;
    connecting = false;
}

void Receiver::error(QAbstractSocket::SocketError socketError)
{
    Q_UNUSED(socketError)

    qDebug() << "Error: " << tcpSocket->errorString() << "\n";
    timer->stop();
    fire->setMessageText(tcpSocket->errorString());
}

void Receiver::timeout()
{
    if (watchdog) {
        watchdog = false;
    }
    else {
        tcpSocket->abort();
        timer->stop();
        if (connecting) {
            fire->setMessageText("Keine Verbindung.");
        }
        else {
            fire->setMessageText("Keine Daten empfangen.");
        }
    }

    /*
    QVector<QString> values(50, QString("0"));
    QStringList list("pm");
    for (int i = 0; i < 50; i++)
        list.append("57");

    QString raw_data = list.join(" ") + QString("\n");

    tData data = raw_data.splitRef(" ");

    fire->parse(data);
    */
}
