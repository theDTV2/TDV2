#include "mousezoomhandler.h"


void MouseZoomHandler::ResetZoomToDefault()
{

    current_zoom_x = current_zoom_x * (1. / current_zoom_x);
    current_zoom_y = current_zoom_y * (1. / current_zoom_y);
    handled_view->scale(current_zoom_x,current_zoom_y);
    AddToZoomStep(current_zoom_x,current_zoom_y);
    //qDebug("Reset Zoom: %f  %f", current_zoom_x * (1. / current_zoom_x), current_zoom_y);


}

void MouseZoomHandler::ZoomIn()
{
   // qDebug("%f",zoom_speed_x);

    if (handled_view->transform().m11() > min_scale_)
    {
        //Prevent non-moveable items from breaking everything by continuing to adjust
        AddToZoomStep(1,1);
        return;
    }


    current_zoom_x *= 1 + zoom_speed_x;
    current_zoom_y *= 1 + zoom_speed_y;
    handled_view->scale(1 + zoom_speed_x, 1 + zoom_speed_y);
    AddToZoomStep(1 + zoom_speed_x, 1 + zoom_speed_y);

    zoom_speed_x *= 1 / (1 + zoom_speed_x);
    zoom_speed_y *= 1 / (1 + zoom_speed_y);

    AxisManager::UpdateSpacing();
}

void MouseZoomHandler::ZoomOut()
{

   auto width = qAbs(handled_view->mapToScene((handled_view->rect().topLeft())).x() - handled_view->mapToScene(handled_view->rect().topRight()).x());
   //qDebug("Width: %f",width);
   if (width >= max_viewport_width_)
   {
       //Prevent non-moveable items from breaking everything by continuing to adjust
       AddToZoomStep(1,1);
       return;
   }

    current_zoom_x *=  1 / (1 + zoom_speed_x);
    current_zoom_y *= 1 / (1 + zoom_speed_y);
    handled_view->scale(1 / (1 + zoom_speed_x),1 / (1 + zoom_speed_y));
    AddToZoomStep(1 / (1 + zoom_speed_x),1 / (1 + zoom_speed_y));

    zoom_speed_x = qMin(1.f,zoom_speed_x * (1 + zoom_speed_x));
    zoom_speed_y = qMin(1.f,zoom_speed_y * (1 + zoom_speed_y));


    AxisManager::UpdateSpacing();
}

void MouseZoomHandler::SetHandlerView(QGraphicsView* view_to_handle)
{

    handled_view = view_to_handle;
}

QVector2D MouseZoomHandler::GetLastZoomStep()
{
    QVector2D to_return = last_zoom_;


    return to_return;
}

void MouseZoomHandler::AddToZoomStep(qreal x, qreal y)
{
    last_zoom_.setX(1 / x);
    last_zoom_.setY(1 / y);
}


void MouseZoomHandler::RecenterView()
{
    //We recenter the view on the middle of the screen
    handled_view->centerOn(
                handled_view->mapToScene(
                    handled_view->viewport()->rect().center()
                    )
                );

}

void MouseZoomHandler::SetMinScale(qreal min)
{
    min_scale_ = min;
}

void MouseZoomHandler::SetMaxScale(qreal max)
{
    max_viewport_width_ = max;

    if (max == 0)
        max_viewport_width_ = std::numeric_limits<qreal>::max();
}

void MouseZoomHandler::SetCurrentZoomToMax()
{


    qDebug("%f sss",handled_view->rect().height());
    handled_view->fitInView(0,0,max_viewport_width_,handled_view->rect().height());
    zoom_speed_x = 1;
    AxisManager::UpdateSpacing();

}
