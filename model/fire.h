#ifndef FIRE_H
#define FIRE_H

#include "variable.h"

#include <QObject>
#include <QSettings>

class Fire : public QObject
{
    Q_OBJECT

    QSettings settings;

    QString m_messageText;
    QString m_host;

public:
    explicit Fire(QObject *parent = nullptr);

    void parse(const tData &data);

    const QString &getMessageText();
    void setMessageText(const QString &text);

    const QString &getHost();
    void setHost(const QString &host);

signals:
    void update();
    void message(const QString &text);
    void connectToHost(const QString &host);

public slots:

public:
    QVector<Variable *> variables;
};

#endif // FIRE_H
