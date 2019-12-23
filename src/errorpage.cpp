#include "errorpage.h"

#include <QGridLayout>

ErrorPage::ErrorPage(Fire *fire, QWidget *parent)
    : QWidget(parent)
    , fire(fire)
{
    auto layout = new QGridLayout(this);

    messageLabel = new QLabel(fire->getMessageText());
    layout->addWidget(messageLabel);

    connect(fire, &Fire::message, this, &ErrorPage::message);
}

void ErrorPage::message(const QString &text)
{
    messageLabel->setText(text);
}

