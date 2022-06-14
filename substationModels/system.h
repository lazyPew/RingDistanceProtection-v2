#ifndef SYSTEM_H
#define SYSTEM_H

#include <QObject>

class System : public QObject
{
    Q_OBJECT

public:
    explicit System(QString csvLine, QObject* parent = nullptr);

    explicit System(QString name, double power, double resist, QObject* parent = nullptr);

public slots:
    QString name() const    {return _name;}
    double powerS() const   {return _powerS;}
    double resistX() const  {return _resistX;}
    QString node() const    {return _node;}

private:
    QString _name;

    double _powerS;
    double _resistX;
    QString _node;
};

#endif // SYSTEM_H
