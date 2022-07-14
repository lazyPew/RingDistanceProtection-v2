#ifndef PROTECTEDEQUIPMENT_H
#define PROTECTEDEQUIPMENT_H

#include <QObject>

class ProtectedEquipment : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString index
               READ index
               CONSTANT)
    Q_PROPERTY(QString fullName
               READ fullName
               CONSTANT)

public:
    ProtectedEquipment(QString index, QObject* parent = nullptr);

    QString index() const       { return _index; }
    QString fullName() const    { return _fullName; }

protected:
    void setFullName(QString);

private:
    void registerQmlTypes();

private:
    QString _index;
    QString _fullName;
};

#endif // PROTECTEDEQUIPMENT_H
