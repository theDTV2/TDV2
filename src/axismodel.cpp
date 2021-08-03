#include "axismodel.h"

AxisModel::AxisModel(qreal x1, qreal y1, qreal x2, qreal y2, QGraphicsView* used_view, QGraphicsItem* parent)
    :QGraphicsLineItem(x1,y1,x2,y2,parent)
{
    used_view_ = used_view;

    direction_vector_ = QVector2D(x2 - x1,y2 - y1);
}

void AxisModel::UpdateSpacing()
{

    if (!enable_spacing)
        return;


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
    qDebug("Amount: %f", spacer_list_.count());
    QVector2D source = QVector2D(this->line().x1(),this->line().y1());

    int current = 0;

    while(current < direction_vector_.length())
    {
        auto item = new QGraphicsLineItem(this->line().x1() + current,this->line().y1() - 10,this->line().x1() + current,this->line().y1() + 10);
        used_view_->scene()->addItem(item);
        spacer_list_.append(item);

        current += distance_ * used_view_->transform().m11();


        //auto text_item = new QGraphicsTextItem(QString::number(current));
       // text_item->setPos(this->line().x1() + current,this->line().y1() + 15);
       // used_view_->scene()->addItem(text_item);
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


