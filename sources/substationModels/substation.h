#ifndef SUBSTATION_H
#define SUBSTATION_H

#include <QObject>

class Substation : public QObject
{
    Q_OBJECT
public:
    explicit Substation(QObject *parent = nullptr);

    QString name() const {return _name;}
signals:

public slots:

private:
    QString _name;
};

#endif // SUBSTATION_H
