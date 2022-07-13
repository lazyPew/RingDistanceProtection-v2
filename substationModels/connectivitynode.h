#ifndef CONNECTIVITYNODE_H
#define CONNECTIVITYNODE_H

#include <QObject>
#include <QMap>
#include "EquipmentModels/system.h"
#include "EquipmentModels/wline.h"
#include "EquipmentModels/transformer.h"

class ConnectivityNode : public QObject
{
    Q_OBJECT
public:
    explicit ConnectivityNode(QString name,
                              QObject *parent = nullptr);

    System* generationInNode();
    Transformer* chooseTransformer();

    void connectSystem(System*);
    void connectWLine(WLine*);
    void connectTransformer(Transformer*);

    int numbersOfSystems();
    int numbersOfWLines();
    int numbersOfTransformers();

    System* getSystemByName(QString name);
    WLine* getWLineByName(QString name);
    Transformer* getTransformerByName(QString name);

public slots:
    QString name() const {return _name;}
signals:

private:
    QString _name;

    QMap<QString,System*> _connectedSystems;
    QMap<QString,WLine*> _connectedWLines;
    QMap<QString,Transformer*> _connectedTransformers;
};

#endif // CONNECTIVITYNODE_H
