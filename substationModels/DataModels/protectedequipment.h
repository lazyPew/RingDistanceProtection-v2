#ifndef PROTECTEDEQUIPMENT_H
#define PROTECTEDEQUIPMENT_H

#include <QObject>

class ProtectedEquipment : public QObject
{
    Q_OBJECT

public:
    ProtectedEquipment(QString name, QObject* parent = nullptr);

    QString name() const { return _name; }
private:
    QString _name;
};

#endif // PROTECTEDEQUIPMENT_H
