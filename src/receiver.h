#ifndef RECEIVER_H
#define RECEIVER_H

#include "fire.h"

#include <QObject>
#include <QTcpSocket>
#include <QTimer>

class Receiver : public QObject
{
    Q_OBJECT

    Fire *fire;
    QTcpSocket *tcpSocket;
    QTimer *timer;
    bool watchdog = false;
    bool connecting = false;

public:
    explicit Receiver(Fire *fire, QObject *parent = nullptr);

signals:

public slots:    
    void connectToHost(const QString &host);
    void read();
    void error(QAbstractSocket::SocketError socketError);

    void timeout();
};

#endif // RECEIVER_H
