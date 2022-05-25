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
public:
    explicit Function(QObject *parent = nullptr);

signals:

public slots:
    void calculateProtectionParameters();

    QList<Terminal*> getTerminals() const { return _terminalsList; }

private:
    Equipment* _equipment;
    QList<Terminal*> _terminalsList;
};

#endif // FUNCTION_H
