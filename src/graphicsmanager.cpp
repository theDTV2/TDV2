#include "graphicsmanager.h"

void GraphicsManager::SetupScene(QGraphicsView *main_view, QGraphicsView *label_view)
{

    QGraphicsScene* scene = new QGraphicsScene(main_view);
    QBrush blueBrush(Qt::blue);
    QPen outlinePen(Qt::black);
    outlinePen.setWidth(2);
    auto test = scene->addText("Hello World!");
    test->setX(-300);
    test->setY(600);
    scene->addRect(50, 0, 80, 80, outlinePen, blueBrush);
    scene->addLine(0,0,0,-50,outlinePen);
    //scene->addRect(1000, 0, 80, 100, outlinePen, blueBrush);
    //scene->setSceneRect(0,0,0,0);
    main_view->setDragMode(QGraphicsView::DragMode::ScrollHandDrag);
    main_view->setResizeAnchor(QGraphicsView::ViewportAnchor::AnchorUnderMouse);
    main_view->setAlignment(Qt::AlignLeft | Qt::AlignTop);
    main_view->setScene(scene);
    MouseZoomHelper *e = new MouseZoomHelper(main_view);
    MouseZoomHandler::SetHandlerView(main_view);
    e->SetAwayFunction(&MouseZoomHandler::ZoomIn);
    e->SetTowardFunction(&MouseZoomHandler::ZoomOut);
    e->SetResizeFunction(&GraphicsManager::ResizeFunction);
    GraphicDrawer::AddElementsToNonResizableList(test);
    main_view->installEventFilter(e);




    QGraphicsScene* scene2 = new QGraphicsScene(label_view);

    scene2->addText("Hello Label!");

    label_view->setScene(scene2);



}

void GraphicsManager::DrawAxis()
{
    GraphicDrawer::DrawAxis();
}


void GraphicsManager::ResizeFunction()
{
    GraphicDrawer::AdjustNonResizableElements();
}

