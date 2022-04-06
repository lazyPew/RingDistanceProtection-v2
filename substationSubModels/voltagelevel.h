#ifndef VOLTAGELEVEL_H
#define VOLTAGELEVEL_H

#include <QObject>

class VoltageLevel : public QObject
{
    Q_OBJECT
public:
    VoltageLevel(QString, int, QObject *parent = nullptr);

signals:

public slots:
    QString name() const   { return _name; }
    int levelValue() const { return _levelValue; }

private:
    QString _name;
    int _levelValue;
};

#endif // VOLTAGELEVEL_H
