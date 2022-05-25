#ifndef SYSTEM_H
#define SYSTEM_H

#include <QObject>

class System : public QObject
{
    Q_OBJECT

public:
    explicit System(QString name, QObject* parent = nullptr);

public slots:
    QString name() const {return _name;}

private:
    QString _name;

    double _powerS;
    double _resistX;
};

#endif // SYSTEM_H
