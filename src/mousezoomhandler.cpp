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
    current_zoom_x *= 1 + zoom_speed_x;
    current_zoom_y *= 1 + zoom_speed_y;
    handled_view->scale(1 + zoom_speed_x, 1 + zoom_speed_y);
    AddToZoomStep(1 + zoom_speed_x, 1 + zoom_speed_y);


    //RecenterView();
}

void MouseZoomHandler::ZoomOut()
{
    current_zoom_x *=  1 / (1 + zoom_speed_x);
    current_zoom_y *= 1 / (1 + zoom_speed_y);
    handled_view->scale(1 / (1 + zoom_speed_x),1 / (1 + zoom_speed_y));
    AddToZoomStep(1 / (1 + zoom_speed_x),1 / (1 + zoom_speed_y));

    //qDebug("Reset Zoom: %f  %f", current_zoom_x ,current_zoom_y);

    //RecenterView();
}

void MouseZoomHandler::SetHandlerView(QGraphicsView* view_to_handle)
{

   // if (handled_view != nullptr)
   //    ResetZoomToDefault();

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
