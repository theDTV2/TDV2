#include "axismodel.h"

AxisModel::AxisModel(qreal x1, qreal y1, qreal x2, qreal y2, QGraphicsView* used_view, QGraphicsItem* parent)
    :QGraphicsLineItem(x1,y1,x2,y2,parent)
{
    used_view_ = used_view;

    direction_vector_ = QVector2D(x2 - x1,y2 - y1);
}

void AxisModel::UpdateSpacing()
{
    //used_view_->viewport()
    //TODO: GET Viewport, calculate lines, place them accordingly on axis

    //Remove old lines
    for(auto e : spacer_list_)
    {
        //After removing the item from the view, we gain ownership of it, and can safely delete it
        used_view_->scene()->removeItem(e);
        delete e;
    }

    QVector2D source = QVector2D(this->line().x1(),this->line().x2());

   // used_view_->rect()

}

void AxisModel::SetDistance(qreal dist)
{
    distance_ = dist;
}

qreal AxisModel::GetDistance()
{
    return distance_;
}


