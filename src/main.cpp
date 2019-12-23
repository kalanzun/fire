#include "fire.h"
#include "receiver.h"
#include "monitor.h"
#include <QApplication>
#include <QSettings>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QCoreApplication::setOrganizationName("Christoph Simon");
    QCoreApplication::setOrganizationDomain("christoph-simon.eu");
    QCoreApplication::setApplicationName("Fire");

    Fire fire;

    Receiver receiver(&fire);

    Monitor monitor(&fire);
    monitor.show();

    return app.exec();
}
