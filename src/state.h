#ifndef STATE_H
#define STATE_H

#include "variable.h"

class State : public Variable
{
    int value;

public:
    State(QString label, int index, QObject *parent = nullptr);

    void parse(const tData &data);

    virtual QString getString();
    virtual QString getIcon();
};

#endif // STATE_H
