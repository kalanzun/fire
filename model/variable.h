#ifndef VARIABLE_H
#define VARIABLE_H

#include <QString>
#include <QVector>
#include <QObject>

typedef QVector<QStringRef> tData;

class Variable : public QObject
{
    Q_OBJECT

protected:
    QString label;
    int index;

public:
    explicit Variable(QString label, int index, QObject *parent = nullptr);

    virtual void parse(const tData &data) = 0;

    virtual QString getLabel();
    virtual QString getString() = 0;
    virtual QString getIcon() = 0;

signals:
    void update();

public slots:
};

#endif // VARIABLE_H
