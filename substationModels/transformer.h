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

private:
    QString _name;

    double _powerS;

    int _hvLevel;
    int _mvLevel;
    int _lvLevel;

    double _uKoefH_L;
    double _uKoefH_M;
    double _uKoefM_L;

    double _regulation;
};

#endif // TRANSFORMER_H
