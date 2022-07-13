#ifndef PROTECTEDEQUIPMENT_H
#define PROTECTEDEQUIPMENT_H

#include <QObject>

class ProtectedEquipment : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString index
               READ index
               CONSTANT)

public:
    ProtectedEquipment(QString index, QObject* parent = nullptr);

    QString index() const { return _index; }

private:
    void registerQmlTypes();

private:
    QString _index;
};

#endif // PROTECTEDEQUIPMENT_H
