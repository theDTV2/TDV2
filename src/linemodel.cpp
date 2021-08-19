#include "linemodel.h"

LineModel::LineModel(qreal x, qreal y, QString label, ViewElement element, QGraphicsView* view,  QBrush brush, bool use_height)
    :origin_x_(x),origin_y_(y), label_(label),to_be_displayed_element_(element), used_view_(view), used_brush_(brush)
{
    RefreshDrawnItems(use_height);
}



void LineModel::SetOrigin(qreal x, qreal y)
{
    origin_x_ = x;
    origin_y_ = y;
}

qreal LineModel::GetOriginX() const
{
    return origin_x_;
}

qreal LineModel::GetOriginY() const
{
    return origin_y_;
}


void LineModel::SetDisplayedElement(ViewElement to_set)
{
    to_be_displayed_element_ = to_set;
}

ViewElement LineModel::GetDisplayedElement()
{
    return to_be_displayed_element_;
}

QString LineModel::GetLabel() const
{
    return label_;
}

void LineModel::SetType(QString type)
{
    type_ = type;
}

QString LineModel::GetType()
{
    return type_;
}

QBrush LineModel::GetBrush()
{
    return used_brush_;
}

void LineModel::SetBrush(QBrush new_brush)
{
    used_brush_ = new_brush;
}

void LineModel::RefreshDrawnItems(bool use_height)
{
    for(auto &e : drawn_elements_)
    {
        delete e;
    }

    QList<DataPair>* list = to_be_displayed_element_.GetList();

    quint16 max = 0;
    //If we draw height (for queues), we do that here, otherwise we skip to regular drawing
    //If we draw height, we must assume that we are dealing with an QueueModel,
    //otherwise height data won't be populated
    if (use_height)
    {
        //Get the max height value

        for (auto e : *list)
            if (e.GetHeight() > max)
                max = e.GetHeight();

        //draw steps with max + 1 as maximum step. This is to prevent clipping


    }


    for(auto e : *list)
    {
        QGraphicsRectItem* new_item = nullptr;
        //We either draw regular boxes, or height boxes
        if (max == 0)
            new_item = new QGraphicsRectItem(origin_x_ + e.GetStartTime(),
                                             origin_y_ - 25,
                                             e.GetLenght(),
                                             50);
        else
        {
            qreal offset = 50 - (50 * ((e.GetHeight()) / (double) max));
            new_item = new QGraphicsRectItem(origin_x_ + e.GetStartTime(),
                                             (origin_y_ - 25) + offset,
                                             e.GetLenght(),
                                             50 * ((e.GetHeight()) / (double) max)); //We need to cast here to use the double "/" Operator



            new_item->setToolTip("Amount of queue elements at this position: " + QString::number(e.GetHeight()));

        }

        new_item->setBrush(used_brush_);
        used_view_->scene()->addItem(new_item);

    }




}
