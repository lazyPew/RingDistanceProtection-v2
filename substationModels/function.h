#ifndef FUNCTION_H
#define FUNCTION_H

#include <QObject>
#include "equipment.h"
#include "terminal.h"

class Function : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QList<Terminal*> terminalsList
               READ getTerminals
               CONSTANT)
    Q_PROPERTY(Equipment* equipment
               READ equipment
               CONSTANT)
public:
    explicit Function(QObject *parent = nullptr);

signals:

public slots:
    Equipment* equipment() { return _equipment; }

    void addTerminal(Terminal*);
    void addWLineToEquipment(WLine*);
    void addSystemToEquipment(System*);

    QList<Terminal*> getTerminals() const { return _terminalsList; }

    Terminal* getTerminalByIndex(int index) const { return _terminalsList.at(index); }

private:
    Equipment* _equipment;
    QList<Terminal*> _terminalsList;
};

#endif // FUNCTION_H
