#include "linemodel.h"

LineModel::LineModel(qreal x, qreal y, QString label, ViewElement element, QGraphicsView* view)
    :origin_x_(x),origin_y_(y), label_(label),to_be_displayed_element_(element), used_view_(view)
{
    RefreshDrawnItems();
}

void LineModel::SetOrigin(qreal x, qreal y)
{
    origin_x_ = x;
    origin_y_ = y;
}

qreal LineModel::GetOriginX()
{
    return origin_x_;
}

qreal LineModel::GetOriginY()
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

QString LineModel::GetLabel()
{
    return label_;
}

void LineModel::SetBrush(QBrush new_brush)
{
    used_brush_ = new_brush;
}

void LineModel::RefreshDrawnItems()
{
    for(auto &e : drawn_elements_)
    {
        delete e;
    }

    QList<DataPair>* list = to_be_displayed_element_.GetList();

    for(auto e : *list)
    {
        auto new_item = new QGraphicsRectItem(origin_x_ + e.GetStartTime(),
                                              origin_y_ - 25,
                                              e.GetLenght(),
                                              50);

        new_item->setBrush(used_brush_);
        used_view_->scene()->addItem(new_item);


    //qDebug("%f %f",e.GetStartTime(),e.GetLenght() );
    }




}
