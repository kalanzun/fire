#ifndef CARD_H
#define CARD_H

#include "variable.h"

#include <QSvgWidget>
#include <QLabel>
#include <QWidget>

class Card : public QWidget
{
    Q_OBJECT

    Variable *variable;

    QLabel *value_label;
    QSvgWidget *icon;

public:
    explicit Card(Variable *variable, QWidget *parent = nullptr);

signals:

public slots:
    void update();
};

#endif // CARD_H
