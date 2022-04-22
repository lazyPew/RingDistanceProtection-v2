#ifndef SUBSTATION_H
#define SUBSTATION_H

#include <QObject>

#include "voltagelevel.h"
#include "function.h"
#include "transformer.h"

class Substation : public QObject
{
    Q_OBJECT
public:
    explicit Substation(QObject *parent = nullptr);

    explicit Substation(QString, int, int, int,
                        QObject *parent = nullptr);

    QString name() const            { return _name; }

    VoltageLevel* hvLevel() const   { return _hvLevel; }
    VoltageLevel* mvLevel() const   { return _mvLevel; }
    VoltageLevel* lvLevel() const   { return _lvLevel; }

    Function* function() const      { return _function; }

signals:

public slots:


private:
    QString _name;

    VoltageLevel* _hvLevel;
    VoltageLevel* _mvLevel;
    VoltageLevel* _lvLevel;

    Function* _function;

    QList<Transformer*> _transformersList;
};

#endif // SUBSTATION_H
