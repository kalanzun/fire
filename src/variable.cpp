#include "variable.h"

Variable::Variable(QString label, int index, QObject *parent)
    : QObject(parent)
    , label(label)
    , index(index)
{

}

QString Variable::getLabel()
{
    return QString("<big><b>%1</b></big>").arg(label);
}
