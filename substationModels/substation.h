#ifndef SUBSTATION_H
#define SUBSTATION_H

#include <QObject>

#include "voltagelevel.h"
#include "function.h"
#include "transformer.h"

class Substation : public QObject
{
    Q_OBJECT

    Q_PROPERTY(Function* functionObj READ functionObj CONSTANT)

public:

    explicit Substation(QObject *parent = nullptr);

    explicit Substation(QString, int, int, int,
                        QObject *parent = nullptr);

    QString name() const            { return _name; }

    VoltageLevel* hvLevel() const   { return _hvLevel; }
    VoltageLevel* mvLevel() const   { return _mvLevel; }
    VoltageLevel* lvLevel() const   { return _lvLevel; }

    Function* functionObj() const      { return _function; }

signals:

public slots:
    void calculateProtectionParameters();

    void parseTransformer(QString line);
    void parseSystem(QString line);
    void parseWLine(QString line);
    void parseTerminal(QString line);

private:
    void connectTransformerToNodes(Transformer*);
    void connectSystemToNodes(System*);
    void connectWLineToNodes(WLine*);

private:
    QString _name;

    VoltageLevel* _hvLevel;
    VoltageLevel* _mvLevel;
    VoltageLevel* _lvLevel;

    Function* _function;

    QMap<QString,Transformer*> _transformersMap;
};

#endif // SUBSTATION_H
