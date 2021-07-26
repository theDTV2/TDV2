#include "linemodel.h"

LineModel::LineModel(qreal x, qreal y, qreal lenght)
    :origin_x_(x),origin_y_(y),lenght_(lenght)
{

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

void LineModel::SetLenght(qreal to_set)
{
    lenght_ = to_set;
}

qreal LineModel::GetLenght()
{
    return lenght_;
}

void LineModel::SetDisplayedElement(QList<ViewElement> to_set)
{
    displayed_elements_ = to_set;
}

QList<ViewElement> LineModel::GetDisplayedElement()
{
    return displayed_elements_;
}
