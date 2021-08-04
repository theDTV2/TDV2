#include "graphicsmanager.h"

void GraphicsManager::SetupScene(QGraphicsView *main_view, QGraphicsView *label_view)
{

    QGraphicsScene* scene = new QGraphicsScene(main_view);
    main_view->setDragMode(QGraphicsView::DragMode::ScrollHandDrag);
    main_view->setResizeAnchor(QGraphicsView::ViewportAnchor::AnchorUnderMouse);
    main_view->setAlignment(Qt::AlignLeft | Qt::AlignTop);
    main_view->setScene(scene);
    scene->addText("Hello World");

    GraphicDrawer::SetView(main_view);
    GraphicDrawer::DrawAxis();



    //TODO refactor & place somewhere else
    MouseZoomHelper *e = new MouseZoomHelper(main_view);
    MouseZoomHandler::SetHandlerView(main_view);
    e->SetAwayFunction(&MouseZoomHandler::ZoomIn);
    e->SetTowardFunction(&MouseZoomHandler::ZoomOut);
    e->SetResizeFunction(&GraphicsManager::ResizeFunction);

    main_view->installEventFilter(e);



    //LabelView Placeholder
    QGraphicsScene* scene2 = new QGraphicsScene(label_view);

    scene2->addText("Hello Label!");
    label_view->setScene(scene2);



}




void GraphicsManager::ResizeFunction()
{
    GraphicDrawer::AdjustNonResizableElements();
}

