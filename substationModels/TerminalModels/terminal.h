#ifndef TERMINAL_H
#define TERMINAL_H

#include <QObject>
#include <QAbstractListModel>

#include "substationModels/connectivitynode.h"

class Terminal : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString index
               READ index
               CONSTANT)

    Q_PROPERTY(QString fullName
               READ fullName
               CONSTANT)

public:
    explicit Terminal(QString,
                      QObject *parent = nullptr);
    explicit Terminal(QString,
                      ProtectedEquipment*,
                      QObject *parent = nullptr);

    virtual void calculateParameters() = 0;
    virtual void resetParameters() = 0;
    virtual QString getResults() = 0;

public slots:
    QString index() const                           { return _index; }
    QString fullName() const                        { return _terminalFullName; }
    ProtectedEquipment* protectedEquipment() const  { return _protectedEquipment; }

protected:
    void setProtectedEquipment(ProtectedEquipment*);
    void setFullName(QString);

private:
    void registerQmlTypes();

protected:
    QString _protectedEquipmentName;
    QString _terminalFullName;

private:
    QString _index;
    ProtectedEquipment* _protectedEquipment;
};

#endif // TERMINAL_H
