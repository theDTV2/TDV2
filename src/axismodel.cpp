#include "axismodel.h"

AxisModel::AxisModel(qreal x1, qreal y1, qreal x2, qreal y2, QGraphicsView* used_view, QGraphicsItem* parent)
    :QGraphicsLineItem(x1,y1,x2,y2,parent)
{
    used_view_ = used_view;

    direction_vector_ = QVector2D(x2 - x1,y2 - y1);
}

void AxisModel::UpdateSpacing()
{

    if (!enable_spacing_)
        return;


    //Calculate left/right borders of viewport
    qreal left = used_view_->mapToScene(used_view_->rect().topLeft()).x();
    qreal right = used_view_->mapToScene(used_view_->rect().topRight()).x();


    //adjusted distance by scale
    qreal adjusted_distance = distance_ * (1 / used_view_->transform().m11());

    //If moved distance is too small, we cancel here
    if (qAbs((old_pos_ - right)) < adjusted_distance)
        return;
    old_pos_ = right;



    //used_view_->viewport()
    //TODO: GET Viewport, calculate lines, place them accordingly on axis

    //Remove old lines
    for(auto e : spacer_list_)
    {
        //After removing the item from the view, we gain ownership of it, and can safely delete it
        used_view_->scene()->removeItem(e);
        delete e;
    }

    spacer_list_.clear();

    QVector2D source = QVector2D(this->line().x1(),this->line().y1());


    //set Min/Max right and left of viewport. (Improves performance on large viewports)
    qreal current = qMax(0.f,left - adjusted_distance);
    qreal right_max = qMin(right + adjusted_distance, direction_vector_.length());



    while(current < right_max)
    {
        auto item = new QGraphicsLineItem(this->line().x1() + current,this->line().y1() - 10,this->line().x1() + current,this->line().y1() + 10,this);

        spacer_list_.append(item);
        current += adjusted_distance;


        auto text_item = new QGraphicsTextItem(QString::number(qFloor(current)),item);
        text_item->setPos(this->line().x1() + current,this->line().y1() + 15);


        text_item->setTransform(text_item->transform().scale(1/used_view_->transform().m11(),1));

    }

}

void AxisModel::SetDistance(qreal dist)
{
    distance_ = dist;
    UpdateSpacing();
}

qreal AxisModel::GetDistance()
{
    return distance_;
}


