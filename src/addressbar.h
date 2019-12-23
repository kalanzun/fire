#ifndef ADDRESSBAR_H
#define ADDRESSBAR_H

#include "fire.h"

#include <QWidget>
#include <QLineEdit>

class AddressBar : public QWidget
{
    Q_OBJECT

    Fire *fire;
    QLineEdit *edit;

public:
    explicit AddressBar(Fire *fire, QWidget *parent = nullptr);

signals:

public slots:
    void clicked();
};

#endif // ADDRESSBAR_H
