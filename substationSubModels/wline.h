#ifndef WLINE_H
#define WLINE_H

#include <QObject>

class WLine : public QObject
{
public:
    WLine(QObject* parent = nullptr);

private:
    QString _name;

    double _resistX;
    double _resistR;
    double _length;

};

#endif // WLINE_H
