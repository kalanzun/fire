#include "percentage.h"

Percentage::Percentage(QString label, int index, QObject *parent)
    : Variable(label, index, parent)
    , value(0)
{

}

void Percentage::parse(const tData &data)
{
    if (data.size() > index) {
        value = data.at(index).toUInt();
        emit update();
    }
}

QString Percentage::getString()
{
    return QString("<big>%1 %</big>").arg(value);
}

QString Percentage::getIcon()
{
    unsigned int index;

    index = value < 99 ? value : 99;
    index = index / 20;
    return QString(":/icons/level%1.svg").arg(index);
}
