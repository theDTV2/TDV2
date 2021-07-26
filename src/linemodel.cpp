#include "linemodel.h"

LineModel::LineModel(qreal left_point, qreal lenght)
    :left_point_(left_point), lenght_(lenght)
{

}

void LineModel::SetLeftPoint(qreal to_set)
{
    left_point_ = to_set;
}

qreal LineModel::GetLeftPoint()
{
    return left_point_;
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
