#include "axismanager.h"


/**
 * @brief Simple setter
 * @param origin
 */
void AxisManager::SetOrigin(QVector2D origin)
{
    origin_point_ = origin;
}

/*
 * Creates a new AxisModel instance for the X-Axis using the given view & lenght and assigns
 * it's reference to the x_axis_line static variable
 * */
AxisModel* AxisManager::SetXAxis(qreal lenght, QGraphicsView* view, bool disable_spacing)
{

    x_axis_line_ = new AxisModel(origin_point_.x(),
                                 origin_point_.y(),
                                 origin_point_.x() + lenght,
                                 origin_point_.y(),
                                 view);

    x_axis_line_->setPen(pen_);

    view->scene()->addItem(x_axis_line_);

    if (disable_spacing)
        x_axis_line_->enable_spacing_ = false;

    return x_axis_line_;
}

/*
 * Creates a new AxisModel instance for the Y-Axis using the given view & lenght and assigns
 * it's reference to the y_axis_line static variable
 * */
AxisModel* AxisManager::SetYAxis(qreal lenght, QGraphicsView* view, bool disable_spacing)
{

    y_axis_line_ = new AxisModel(origin_point_.x(),
                                 origin_point_.y(),
                                 origin_point_.x(),
                                 origin_point_.y() + lenght,
                                 view);

    y_axis_line_->setPen(pen_);

    if (disable_spacing)
        y_axis_line_->enable_spacing_ = false;

    view->scene()->addItem(y_axis_line_);
    return y_axis_line_;
}

/*
 * Sets the pen used for Axis drawing to the given thickness
 * */
void AxisManager::SetPenThickness(qreal var)
{
    pen_ = QPen(Qt::black, var);
}

/*
 * Triggers the updating of the spacing displayed on the x-axis
 * */
void AxisManager::UpdateSpacing(bool ignore_check)
{
    if (x_axis_line_ != nullptr)
    {
        x_axis_line_->UpdateSpacing(ignore_check);
        y_axis_line_->UpdateSpacing(ignore_check);
    }
}

/*
 * Sets the distance between each spacer on the x/y axis.
 * Won't do anything on an axis, if spacing is not set
 * */
void AxisManager::SetLineDistance(qreal dist)
{
    x_axis_line_->SetDistance(dist);
    y_axis_line_->SetDistance(dist);


}

/*
 * returns the lenght of the x-axis, if has been already created
 * */
qreal AxisManager::GetXAxisLenght()
{
    if (x_axis_line_)
        return x_axis_line_->GetLenght();

    return 0;
}
