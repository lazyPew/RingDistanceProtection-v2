#ifndef FUNCTION_H
#define FUNCTION_H

#include <QObject>
#include "equipment.h"
#include "terminal.h"

class Function : public QObject
{
    Q_OBJECT
public:
    explicit Function(QObject *parent = nullptr);

signals:

public slots:

private:
    Equipment* _equipment;
    QList<Terminal*> _terminalsList;
};

#endif // FUNCTION_H
