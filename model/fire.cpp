#include "fire.h"
#include "percentage.h"
#include "state.h"
#include "temperature.h"

Fire::Fire(QObject *parent)
    : QObject(parent)
    , settings()
{
    // threshold values 0, 10, 20, 30 °C
    variables.append(new Temperature(QString("Außentemperatur"), 7, 10, 1, this));
    // threshold values 40, 50, 60, 70
    variables.append(new Temperature(QString("Kessel"), 1, 10, -3, this));
    // threshold values 50, 100, 150, 200
    variables.append(new Temperature(QString("Abgas"), 2, 50, 0, this));

    variables.append(new Percentage(QString("Puffer"), 50, this));
    // threshold values 40, 45, 50, 55
    variables.append(new Temperature(QString("Boiler"), 12, 5, -7, this));
    variables.append(new Temperature(QString("Vorlauf"), 8, 5, -7, this));

    variables.append(new Temperature(QString("Puffer Oben"), 4, 5, -7, this));
    variables.append(new Temperature(QString("Puffer Mitte"), 5, 5, -7, this));
    variables.append(new Temperature(QString("Puffer Unten"), 6, 5, -7, this));

    //variables.append(new State(QString("Zustand"), 4, this));

    m_host = settings.value("host", "192.168.1.12").toString();
}

void Fire::parse(const tData &data)
{
    for (auto variable: variables)
        variable->parse(data);

    emit update();
}

const QString &Fire::getMessageText()
{
    return m_messageText;
}

void Fire::setMessageText(const QString &text)
{
    m_messageText = text;
    emit message(m_messageText);
}

const QString &Fire::getHost()
{
    return m_host;
}

void Fire::setHost(const QString &host)
{
    m_host = host;
    emit connectToHost(m_host);
}
