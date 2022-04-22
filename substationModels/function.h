#ifndef FUNCTION_H
#define FUNCTION_H

#include <QObject>
#include "equipment.h"
#include "terminal.h"

class Function : public QObject
{
    Q_OBJECT

//    Q_PROPERTY(QList<Terminal*> terminalsList
//               READ getTerminals
//               CONSTANT)
public:
    explicit Function(QObject *parent = nullptr);

signals:

public slots:
//    QList<Terminal*> getTerminals() const;

private:
    Equipment* _equipment;
    QList<Terminal*> _terminalsList;
};

#endif // FUNCTION_H
