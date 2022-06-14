#ifndef TERMINAL_H
#define TERMINAL_H

#include <QObject>
#include <QAbstractListModel>

#include "connectivitynode.h"

class Terminal : public QObject
{
    Q_OBJECT
public:
    explicit Terminal(QString, QObject *parent = nullptr);
    explicit Terminal(QString, ProtectedEquipment*, QObject *parent = nullptr);

    virtual void calculateParameters() = 0;

public slots:
    QString name() const                           { return _name; }

    ProtectedEquipment* protectedEquipment() const { return _protectedEquipment; }

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
