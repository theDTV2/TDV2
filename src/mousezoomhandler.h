#ifndef MOUSEZOOMHANDLER_H
#define MOUSEZOOMHANDLER_

#include <QGraphicsView>
#include <QDebug>
#include "axismanager.h"

class MouseZoomHandler
{
public:

    static void ResetZoomToDefault();
    static void ZoomIn();
    static void ZoomOut();
    static void SetHandlerView(QGraphicsView* view_to_handle);
    static QVector2D GetLastZoomStep();
    static void RecenterView();
    static void SetMinScale(qreal min);
    static void SetMaxScale(qreal max = 0);


private:
    static void AddToZoomStep(qreal x, qreal y);


    inline static qreal current_zoom_x = 1;
    inline static qreal current_zoom_y = 1;

    inline static qreal zoom_speed_x = 0.05;
    inline static qreal zoom_speed_y = 0;

    inline static QVector2D last_zoom_ = QVector2D(1,1);

    inline static qreal min_scale_ = 2;
    inline static qreal max_viewport_width_ = std::numeric_limits<qreal>::max();


    inline static QGraphicsView *handled_view;
};

#endif // MOUSEZOOMHANDLER_H
