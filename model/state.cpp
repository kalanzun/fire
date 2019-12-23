#include "state.h"

State::State(QString label, int index, QObject *parent)
    : Variable(label, index, parent)
    , value(0)
{

}

void State::parse(const tData &data)
{
    if (data.size() > index) {
        value = data[index].toInt();
        emit update();
    }
}

QString State::getString()
{
    return QString("<big>%1</big>").arg(value);
}

QString State::getIcon()
{
    return QString(":/icons/temp3.svg");
}
