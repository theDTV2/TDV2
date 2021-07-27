#ifndef MOUSEZOOMHANDLER_H
#define MOUSEZOOMHANDLER_

#include <QGraphicsView>
#include <QDebug>
#include "mousezoomhelper.h"

class MouseZoomHandler
{
public:

    static void ResetZoomToDefault();
    static void ZoomIn();
    static void ZoomOut();
    static void SetHandlerView(QGraphicsView* view_to_handle);
    static QVector2D GetLastZoomStep();
    static void RecenterView();

private:
    static void AddToZoomStep(qreal x, qreal y);


    inline static qreal current_zoom_x = 1;
    inline static qreal current_zoom_y = 1;

    inline static qreal zoom_speed_x = 0.05;
    inline static qreal zoom_speed_y = 0;

    inline static QVector2D last_zoom_ = QVector2D(1,1);



    inline static QGraphicsView *handled_view;
};

#endif // MOUSEZOOMHANDLER_H
