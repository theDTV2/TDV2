#include "axismanager.h"


void AxisManager::SetOrigin(QVector2D origin)
{
    origin_point_ = origin;
}

 AxisModel* AxisManager::SetXAxis(qreal lenght, QGraphicsView* view)
{
    x_axis_line_ = new AxisModel(origin_point_.x(),
                                 origin_point_.y(),
                                 origin_point_.x() + lenght,
                                 origin_point_.y(),
                                 view);

    x_axis_line_->setPen(pen_);

    view->scene()->addItem(x_axis_line_);
    return x_axis_line_;
}

 AxisModel* AxisManager::SetYAxis(qreal lenght, QGraphicsView* view)
{
    y_axis_line_ = new AxisModel(origin_point_.x(),
                                 origin_point_.y(),
                                 origin_point_.x(),
                                 origin_point_.y() + lenght,
                                 view);

    y_axis_line_->setPen(pen_);

    view->scene()->addItem(y_axis_line_);
    return y_axis_line_;
}

void AxisManager::SetPenThickness(qreal var)
{
    pen_ = QPen(Qt::black, var);
}

void AxisManager::UpdateSpacing()
{
    if (x_axis_line_ != nullptr)
    {
        x_axis_line_->UpdateSpacing();
        y_axis_line_->UpdateSpacing();
    }
}

void AxisManager::SetLineDistance(qreal dist)
{
    x_axis_line_->SetDistance(dist);
    y_axis_line_->SetDistance(dist);


}
