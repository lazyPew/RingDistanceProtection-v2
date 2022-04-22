#ifndef TERMINAL_H
#define TERMINAL_H

#include <QObject>
#include <QAbstractListModel>

#include "connectivitynode.h"

class Terminal : public QObject
{
    Q_OBJECT
public:
    Terminal(QString, QObject *parent = nullptr);

    virtual void calculateParameters() = 0;

private:
    QString _name;
};

class TerminalsListModel : public QAbstractListModel
{
    Q_OBJECT
public:
    explicit TerminalsListModel(QObject* parent = nullptr);

    enum Roles{
        IndexRole = Qt::UserRole + 1,
        NameRole,
        OpANameRole,
        OpBNameRole
    };

};


#endif // TERMINAL_H
