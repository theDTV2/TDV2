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


class AxisModel : public QGraphicsLineItem
{
public:
    AxisModel(qreal x1, qreal y1, qreal x2, qreal y2, QGraphicsView* used_view, QGraphicsItem* parent = nullptr);


    void UpdateSpacing();

    void SetDistance(qreal dist);
    qreal GetDistance();

    bool enable_spacing_ = true;

private:
    QGraphicsView* used_view_;
    qreal distance_;
    QVector2D direction_vector_;

    QList<QGraphicsLineItem*> spacer_list_;

    inline static qreal old_pos;

};

#endif // AXISMODEL_H
