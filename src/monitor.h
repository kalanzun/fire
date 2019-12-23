#ifndef MONITOR_H
#define MONITOR_H

#include "card.h"
#include "fire.h"

#include <QMainWindow>
#include <QStackedWidget>

class Monitor : public QMainWindow
{
    Q_OBJECT

    Fire *fire;
    QStackedWidget *stackedWidget;

public:
    explicit Monitor(Fire *fire, QWidget *parent = nullptr);

public slots:
    void update();
    void message(const QString& text);
};

#endif // MONITOR_H
