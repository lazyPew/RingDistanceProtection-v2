#ifndef TRANSFORMER_H
#define TRANSFORMER_H

#include <QObject>

class Transformer : public QObject
{
    Q_OBJECT
public:
    explicit Transformer(QObject *parent = nullptr);

signals:

public slots:
};

#endif // TRANSFORMER_H