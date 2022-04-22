#ifndef SYSTEM_H
#define SYSTEM_H

#include <QObject>

class System : public QObject
{
public:
    explicit System(QString name, QObject* parent = nullptr);

private:
    QString _name;

    double _powerS;
    double _resistX;
};

#endif // SYSTEM_H
