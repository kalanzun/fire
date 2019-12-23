#ifndef ERRORPAGE_H
#define ERRORPAGE_H

#include "model/fire.h"

#include <QObject>
#include <QWidget>
#include <QLabel>

class ErrorPage : public QWidget
{
    Q_OBJECT

    Fire *fire;
    QLabel *messageLabel;

public:
    explicit ErrorPage(Fire *fire, QWidget *parent = nullptr);

signals:

public slots:
    void message(const QString& text);
};

#endif // ERRORPAGE_H
