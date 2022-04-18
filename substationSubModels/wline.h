#ifndef WLINE_H
#define WLINE_H

#include <QObject>

class WLine : public QObject
{
public:
    WLine(QString name = "", QObject* parent = nullptr);

public slots:
    double lineImpedance() const;

private:
    QString _name;

    double _resistX;
    double _resistR;
    double _length;
};

#endif // WLINE_H
