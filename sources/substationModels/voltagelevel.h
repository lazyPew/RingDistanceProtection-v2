#ifndef VOLTAGELEVEL_H
#define VOLTAGELEVEL_H

#include <QObject>

class VoltageLevel : public QObject
{
    Q_OBJECT
public:
    explicit VoltageLevel(QObject *parent = nullptr);

signals:

public slots:
};

#endif // VOLTAGELEVEL_H