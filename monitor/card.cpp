#include "card.h"

#include <QGridLayout>

Card::Card(Variable *variable, QWidget *parent)
    : QWidget(parent)
    , variable(variable)
{
    // 2x2 grid

    // label label
    // icon value

    auto layout = new QGridLayout(this);
    setLayout(layout);

    auto label = new QLabel(variable->getLabel(), this);
    layout->addWidget(label, 0, 0, 1, 2);

    icon = new QSvgWidget(variable->getIcon(), this);
    icon->setMinimumSize(40, 60);
    icon->setMaximumSize(40, 60);
    layout->addWidget(icon, 1, 0, 1, 1, Qt::AlignCenter);

    value_label = new QLabel(variable->getString(), this);
    layout->addWidget(value_label, 1, 1);

    //layout->setRowStretch(1, 1);
    layout->setColumnStretch(1, 1);

    connect(variable, &Variable::update, this, &Card::update);
}

void Card::update()
{
    icon->load(variable->getIcon());
    value_label->setText(variable->getString());
}
