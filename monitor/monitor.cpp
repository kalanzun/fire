#include "monitor.h"
#include "addressbar.h"
#include "errorpage.h"

#include <QBoxLayout>
#include <QGridLayout>

#define ROWS 3

Monitor::Monitor(Fire *fire, QWidget *parent)
    : QMainWindow(parent)
    , fire(fire)
{
    setCentralWidget(new QWidget());
    auto centralLayout = new QVBoxLayout(centralWidget());

    auto addressBar = new AddressBar(fire);
    centralLayout->addWidget(addressBar);

    stackedWidget = new QStackedWidget();
    centralLayout->addWidget(stackedWidget);

    auto errorPage = new ErrorPage(fire);
    stackedWidget->addWidget(errorPage);

    auto cardGrid = new QWidget();
    stackedWidget->addWidget(cardGrid);

    auto layout = new QGridLayout(cardGrid);
    unsigned int i = 0;
    for (auto variable : fire->variables) {
        layout->addWidget(new Card(variable), i%ROWS, i/ROWS);
        i++;
    }

    connect(fire, &Fire::update, this, &Monitor::update);
    connect(fire, &Fire::message, this, &Monitor::message);
}

void Monitor::update()
{
    stackedWidget->setCurrentIndex(1);
}

void Monitor::message(const QString &text)
{
    Q_UNUSED(text)

    stackedWidget->setCurrentIndex(0);
}
