#include "axismodel.h"

AxisModel::AxisModel(qreal x1, qreal y1, qreal x2, qreal y2, QGraphicsView* used_view, QGraphicsItem* parent)
    :QGraphicsLineItem(x1,y1,x2,y2,parent)
{
    used_view_ = used_view;
}

void AxisModel::UpdateSpacing()
{
    //used_view_->viewport()
    //TODO: GET Viewport, calculate lines, place them accordingly on lines

    for(auto &e : spacer_list_)
    {
        //After removing the item from the view, we gain ownership of it, and can safely delete it
        used_view_->scene()->removeItem(e);
        delete e;
    }





}

void AxisModel::SetDistance(qreal dist)
{
    distance_ = dist;
}

qreal AxisModel::GetDistance()
{
    return distance_;
}


