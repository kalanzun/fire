#ifndef TEMPERATURE_H
#define TEMPERATURE_H

#include "variable.h"

class Temperature : public Variable
{
    double value;
    double divider;
    int offset;

public:
    Temperature(QString label, int index, double divider, int offset, QObject *parent = nullptr);

    void parse(const tData &data);

    virtual QString getString();
    virtual QString getIcon();
};

#endif // TEMPERATURE_H
