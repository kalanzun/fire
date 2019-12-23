#ifndef PERCENTAGE_H
#define PERCENTAGE_H

#include "variable.h"

class Percentage : public Variable
{
    unsigned int value;

public:
    Percentage(QString label, int index, QObject *parent = nullptr);

    void parse(const tData &data);

    virtual QString getString();
    virtual QString getIcon();
};

#endif // PERCENTAGE_H
