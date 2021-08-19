#ifndef AXISMODEL_H
#define AXISMODEL_H

#include <QGraphicsLineItem>
#include <QGraphicsItem>
#include <QGraphicsView>
#include <QGraphicsLineItem>
#include <QGraphicsTextItem>
#include <QVector2D>
#include <QString>
#include <QObject>


#include "generaldata.h"

class AxisModel : public QGraphicsLineItem
{
public:
    AxisModel(qreal x1, qreal y1, qreal x2, qreal y2, QGraphicsView* used_view, QGraphicsItem* parent = nullptr);


    void UpdateSpacing(bool ignore_check = false);

    void SetDistance(qreal dist);
    qreal GetDistance();
    qreal GetLenght();

    bool enable_spacing_ = true;

private:
    QGraphicsView* used_view_;
    qreal distance_;
    QVector2D direction_vector_;

    QList<QGraphicsLineItem*> spacer_list_;

    qreal old_pos_;

};

#endif // AXISMODEL_H
