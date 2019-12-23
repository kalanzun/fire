#include "addressbar.h"

#include <QBoxLayout>
#include <QLabel>
#include <QPushButton>

AddressBar::AddressBar(Fire *fire, QWidget *parent)
    : QWidget(parent)
    , fire(fire)
{
    auto layout = new QHBoxLayout(this);

    auto label = new QLabel("Adresse", this);
    layout->addWidget(label);

    edit = new QLineEdit(fire->getHost(), this);
    layout->addWidget(edit);
    connect(edit, &QLineEdit::returnPressed, this, &AddressBar::clicked);

    auto button = new QPushButton("Verbinden", this);
    layout->addWidget(button);
    connect(button, &QPushButton::clicked, this, &AddressBar::clicked);
}

void AddressBar::clicked()
{
    fire->setHost(edit->text());
}
