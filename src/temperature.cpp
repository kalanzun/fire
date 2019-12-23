#include "temperature.h"

Temperature::Temperature(QString label, int index, double divider, int offset, QObject *parent)
    : Variable(label, index, parent)
    , value(0)
    , divider(divider)
    , offset(offset)
{

}

void Temperature::parse(const tData &data)
{
    if (data.size() > index) {
        value = data.at(index).toDouble();
        emit update();
    }
}

QString Temperature::getString()
{
    return QString("<big>%1 °C</big>").arg(value);
}

QString Temperature::getIcon()
{
    int index;

    // TODO negative values

    index = static_cast<int>(value / divider) + offset;
    index = index < 4 ? index : 4;
    index = index > 0 ? index : 0;
    return QString(":/icons/temp%1.svg").arg(index);
}
