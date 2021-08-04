#include "graphicdrawer.h"

void GraphicDrawer::DrawTask(LineModel line_to_draw)
{

}

void GraphicDrawer::DrawQueue(LineModel line_to_draw)
{

}

void GraphicDrawer::DrawUserAgent(LineModel line_to_draw)
{

}

void GraphicDrawer::DrawMarkers(LineModel line_to_draw)
{

}

void GraphicDrawer::DrawHandlers(LineModel line_to_draw)
{

}

void GraphicDrawer::SetView(QGraphicsView *view)
{
    view_ = view;
}

void GraphicDrawer::DrawAxis()
{
    AxisManager::SetOrigin(QVector2D(0,0));


    AxisManager::SetXAxis(5000,view_);
    AddElementsToNonResizableList(AxisManager::SetYAxis(500,view_,true));
    AxisManager::SetLineDistance(100);
}

void GraphicDrawer::AdjustNonResizableElements()
{
    QVector2D last_zoom_step = MouseZoomHandler::GetLastZoomStep();

    QTransform i_transform;
            for (auto i : non_resizable_elements_)
    {
        i_transform = i->transform();
        i_transform.scale(last_zoom_step.x(),last_zoom_step.y());
        i->setTransform(i_transform);

    }


}

void GraphicDrawer::AddElementsToNonResizableList(QGraphicsItem *element)
{
    non_resizable_elements_.append(element);
}

void GraphicDrawer::ResetNonResizableElements()
{
    non_resizable_elements_.clear();
}

void GraphicDrawer::RemoveElementFromResizableElements(QGraphicsItem *element)
{

    //TODO: Test if this works properly (e.g. operator==()- Overload is correct)
    if (non_resizable_elements_.contains(element))
            non_resizable_elements_.removeAll(element);

    return;
}
