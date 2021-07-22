#include "graphicsviewdrawer.h"

void GraphicsViewDrawer::SetupScene(QGraphicsView *view_to_setup)
{

    QGraphicsScene* scene = new QGraphicsScene(view_to_setup);

    QBrush blueBrush(Qt::blue);
    QPen outlinePen(Qt::black);
    outlinePen.setWidth(2);



    scene->addText("Hello World!");

    scene->addRect(10000, 0, 80, 100, outlinePen, blueBrush);
    scene->addRect(1000, 0, 80, 100, outlinePen, blueBrush);


    scene->addRect(2000, 0, 80, 100, outlinePen, blueBrush);
    scene->setSceneRect(0,0,0,0);
    view_to_setup->setDragMode(QGraphicsView::DragMode::ScrollHandDrag);
    view_to_setup->setResizeAnchor(QGraphicsView::ViewportAnchor::AnchorUnderMouse);
    view_to_setup->setScene(scene);

    MouseZoomHelper *e = new MouseZoomHelper(view_to_setup);

    MouseZoomHandler::SetHandlerView(view_to_setup);
    e->SetAwayFunction(&MouseZoomHandler::ZoomIn);
    e->SetTowardFunction(&MouseZoomHandler::ZoomOut);

    view_to_setup->installEventFilter(e);



}
