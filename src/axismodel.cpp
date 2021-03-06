#include "axismodel.h"

/**
 * @brief Constructor for X/Y Axis
 * @param x1 origin x
 * @param y1 target y
 * @param x2 target x
 * @param y2 target y
 * @param used_view QGraphicsView to draw this Axis in
 * @param parent parent item
 */
AxisModel::AxisModel(qreal x1, qreal y1, qreal x2, qreal y2, QGraphicsView* used_view, QGraphicsItem* parent)
    :QGraphicsLineItem(x1,y1,x2,y2,parent), used_view_(used_view), distance_(0), direction_vector_( QVector2D(x2 - x1,y2 - y1)), old_pos_(0)
{


}
/**
 * @brief Updates the spacing using the current position in the viewport
 * @param ignore_check if true, the spacing will be updated regardless of passed distance
 */

void AxisModel::UpdateSpacing(bool ignore_check)
{

    if (!enable_spacing_)
        return;


    //Calculate left/right borders of viewport
    qreal left = used_view_->mapToScene(used_view_->rect().topLeft()).x();
    qreal right = used_view_->mapToScene(used_view_->rect().topRight()).x();



    //adjusted distance by scale
    qreal adjusted_distance = distance_ * (1 / used_view_->transform().m11());


    //If moved distance is too small, we cancel here, if the igore_check is not set
    if (qAbs((old_pos_ - right)) < adjusted_distance && !ignore_check)
        return;

    old_pos_ = right;


    for(auto e : spacer_list_)
    {
        //After removing the item from the view, we gain ownership of it, and can safely delete it
        used_view_->scene()->removeItem(e);
        delete e;
    }

    spacer_list_.clear();

    //QVector2D source = QVector2D(this->line().x1(),this->line().y1());


    //set Min/Max right and left of viewport. (Improves performance on large viewports)
    qreal current = qMax(0.f,left - adjusted_distance * 3);
    qreal right_max = qMin(right + adjusted_distance * 3, direction_vector_.length());

    current += adjusted_distance;

    //If a value for "speed" has been set, we use it to calculate the s from the current ticks
    quint64 divider = 0;
    QString label;

    if (DataAccessor::GetSpeed())
        divider = DataAccessor::GetSpeed();


    //While we have not reached the right end of the viewport
    while(current < right_max)
    {
        //create line
        auto item = new QGraphicsLineItem(this->line().x1() + current, this->line().y1() - 10, this->line().x1() + current, this->line().y1() + 10,this);
        spacer_list_.append(item);


        //generate label
        if (divider)
            label = QString::number((current / divider) * 1000,'f',0) + "ms";
        else
            label = QString::number(qFloor(current));


        auto text_item = new QGraphicsTextItem(label,item);

        //Set text position in the middle under the new spacer
        text_item->setPos((this->line().x1() + current) - (text_item->boundingRect().width() * (1/used_view_->transform().m11()) * 0.5) ,this->line().y1() + 15);

        text_item->setTransform(text_item->transform().scale(1/used_view_->transform().m11(),1));
        current += adjusted_distance;

    }


    //If we reached the end, we add one final spacer
    if (current > this->line().x2())
    {
        auto item = new QGraphicsLineItem(this->line().x1() + right_max,this->line().y1() - 10,this->line().x1() + right_max,this->line().y1() + 10,this);
        spacer_list_.append(item);

    }



}

/**
 * @brief Sets distance, and triggers the spacing update
 * @param dist
 */
void AxisModel::SetDistance(qreal dist)
{
    distance_ = dist;
    UpdateSpacing();
}

/**
 * @brief simple getter
 * @return distance
 */
qreal AxisModel::GetDistance()
{
    return distance_;
}

/**
 * @brief simple getter
 * @return lenght
 */

qreal AxisModel::GetLenght()
{
    return direction_vector_.length();
}


