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

void LineModel::RefreshDrawnItems()
{
    for(auto &e : drawn_elements_)
    {
        delete e;
    }

    QList<DataPair>* list = to_be_displayed_element_.GetList();

   // QGraphicsRectItem* new_item;

   // for(auto e : *list)
    {
        //new_item = new QGraphicsRectItem()




    }

}
