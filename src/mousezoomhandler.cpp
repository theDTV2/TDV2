#include "mousezoomhandler.h"


/**
 * @brief Resets zooming values to default
 */
void MouseZoomHandler::ResetZoomToDefault()
{
    current_zoom_x = current_zoom_x * (1. / current_zoom_x);
    current_zoom_y = current_zoom_y * (1. / current_zoom_y);
    main_view->scale(current_zoom_x,current_zoom_y);
    AddToZoomStep(current_zoom_x,current_zoom_y);

}

/**
 * @brief Zoom in using the given zoom_speed_x and zoom_speed_y values
 */
void MouseZoomHandler::ZoomIn()
{
    if (main_view->transform().m11() > min_scale_)
    {
        //Prevent non-moveable items from breaking everything by continuing to adjust
        AddToZoomStep(1,1);
        return;
    }


    current_zoom_x *= 1 + zoom_speed_x;
    current_zoom_y *= 1 + zoom_speed_y;

    //scale main view using calculated values
    main_view->scale(1 + zoom_speed_x, 1 + zoom_speed_y);
    AddToZoomStep(1 + zoom_speed_x, 1 + zoom_speed_y);

    //Adjust zoom speed to improve sensitivity
    zoom_speed_x *= 1 / (1 + zoom_speed_x);
    zoom_speed_y *= 1 / (1 + zoom_speed_y);

    AxisManager::UpdateSpacing();
}

/**
 * @brief Zoom out using the given zoom_speed_x and zoom_speed_y values
 */
void MouseZoomHandler::ZoomOut()
{

   auto width = qAbs(main_view->mapToScene((main_view->rect().topLeft())).x() - main_view->mapToScene(main_view->rect().topRight()).x());
   if (width >= max_viewport_width_)
   {
       //Prevent non-moveable items from breaking everything by continuing to adjust
       AddToZoomStep(1,1);
       return;
   }

    current_zoom_x *=  1 / (1 + zoom_speed_x);
    current_zoom_y *= 1 / (1 + zoom_speed_y);
    main_view->scale(1 / (1 + zoom_speed_x),1 / (1 + zoom_speed_y));
    AddToZoomStep(1 / (1 + zoom_speed_x),1 / (1 + zoom_speed_y));

    zoom_speed_x = qMin(1.f,zoom_speed_x * (1 + zoom_speed_x));
    zoom_speed_y = qMin(1.f,zoom_speed_y * (1 + zoom_speed_y));

    AxisManager::UpdateSpacing();
}

/**
 * @brief setter
 * @param view_to_handle view to handle
 */
void MouseZoomHandler::SetHandlerView(QGraphicsView* view_to_handle)
{

    main_view = view_to_handle;

}

/**
 * @brief getter
 * @return last zoom step
 */
QVector2D MouseZoomHandler::GetLastZoomStep()
{
    QVector2D to_return = last_zoom_;


    return to_return;
}

/**
 * @brief Add values to zoom step
 * @param x x to set
 * @param y y to set
 */
void MouseZoomHandler::AddToZoomStep(qreal x, qreal y)
{
    last_zoom_.setX(1 / x);
    last_zoom_.setY(1 / y);
}

/**
 * @brief We recenter the view in the middle of the view to prevent zooming from freaking out
 */
void MouseZoomHandler::RecenterView()
{
    //We recenter the view on the middle of the screen
    main_view->centerOn(
                main_view->mapToScene(
                    main_view->viewport()->rect().center()
                    )
                );

    //adjust labelview position to fit


}

/**
 * @brief Set minimum value we can zoom in to
 * @param min min value to scale to
 */
void MouseZoomHandler::SetMinScale(qreal min)
{
    min_scale_ = min;
}

/**
 * @brief Set max value we can zoom out to
 * @param max max value to scale to
 */
void MouseZoomHandler::SetMaxScale(qreal max)
{
    max_viewport_width_ = max;

    if (max == 0)
        max_viewport_width_ = std::numeric_limits<qreal>::max();
}

/**
 * @brief Zooms out view to maximum value set in SetMaxScale
 */
void MouseZoomHandler::SetCurrentZoomToMax()
{
    main_view->fitInView(0,0,max_viewport_width_,main_view->rect().height());
    zoom_speed_x = 1;
    AxisManager::UpdateSpacing();

}
