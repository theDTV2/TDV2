#include "mousezoomhandler.h"


void MouseZoomHandler::ResetZoomToDefault()
{

    current_zoom_x = current_zoom_x * (1. / current_zoom_x);
    current_zoom_y = current_zoom_y * (1. / current_zoom_x);
    handled_view->scale(current_zoom_x,current_zoom_y);
    qDebug("Reset Zoom: %f  %f", current_zoom_x, current_zoom_y);
}

void MouseZoomHandler::ZoomIn()
{
    current_zoom_x += current_zoom_x * zoom_speed_x;
    current_zoom_y += current_zoom_y * zoom_speed_y;
    handled_view->scale(1 + zoom_speed_x,1 + zoom_speed_y);
    qDebug("Current Zoom: %f  %f",current_zoom_x, current_zoom_y);

}

void MouseZoomHandler::ZoomOut()
{
    current_zoom_x -= current_zoom_x * zoom_speed_x;
    current_zoom_y -= current_zoom_y * zoom_speed_y;
    handled_view->scale(1 - zoom_speed_x,1 - zoom_speed_y);
    qDebug("Current Zoom: %f %f",current_zoom_x, current_zoom_y);
}

void MouseZoomHandler::SetHandlerView(QGraphicsView* view_to_handle)
{
  // if (handled_view != nullptr)
   //    ResetZoomToDefault();

    handled_view = view_to_handle;
}
