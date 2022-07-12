#ifndef TERMINAL_H
#define TERMINAL_H

#include <QObject>
#include <QAbstractListModel>

#include "connectivitynode.h"

class Terminal : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString name
               READ name
               CONSTANT)

public:
    explicit Terminal(QString,
//                      Function* func = nullptr,
                      QObject *parent = nullptr);
    explicit Terminal(QString,
                      ProtectedEquipment*,
//                      Function* func = nullptr,
                      QObject *parent = nullptr);

    virtual void calculateParameters() = 0;
    virtual void resetParameters() = 0;
    virtual QString getResults() = 0;

public slots:
    QString name() const                            { return _name; }
    ProtectedEquipment* protectedEquipment() const  { return _protectedEquipment; }

    void setProtectedEquipment(ProtectedEquipment*);

private:
    void registerQmlTypes();

protected:
    QString _protectedEquipmentName;

private:
    QString _name;
    ProtectedEquipment* _protectedEquipment;
};

//class TerminalsListModel : public QAbstractListModel
//{
//    Q_OBJECT
//public:
//    explicit TerminalsListModel(QObject* parent = nullptr);

//    enum Roles{
//        IndexRole = Qt::UserRole + 1,
//        NameRole,
//        OpANameRole,
//        OpBNameRole
//    };

//};


#endif // TERMINAL_H
