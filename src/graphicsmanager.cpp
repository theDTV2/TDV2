#include "graphicsmanager.h"

void GraphicsManager::SetupScene(customQGraphicsView *main_view, customQGraphicsView *label_view)
{



    QGraphicsScene* scene = new QGraphicsScene(main_view);
    main_view->setDragMode(QGraphicsView::DragMode::ScrollHandDrag);
    main_view->setResizeAnchor(QGraphicsView::ViewportAnchor::AnchorUnderMouse);
    main_view->setAlignment(Qt::AlignLeft | Qt::AlignTop);
    main_view->setScene(scene);




    //Setting movement handlers
    GraphicDrawer::SetView(main_view);
    MouseZoomHandler::SetHandlerView(main_view);
    main_view->SetAwayFunction(&MouseZoomHandler::ZoomIn);
    main_view->SetTowardFunction(&MouseZoomHandler::ZoomOut);
    main_view->SetResizeFunction(&GraphicsManager::ResizeFunction);



    GraphicDrawer::DrawAxis();

    GraphicDrawer::DrawData();

    GraphicDrawer::DrawLabels(label_view);

}



void GraphicsManager::ResizeFunction()
{
    GraphicDrawer::AdjustNonResizableElements();
}

