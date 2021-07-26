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

void GraphicDrawer::DrawAxis()
{

}

void GraphicDrawer::AdjustNonResizableElements()
{

}

void GraphicDrawer::AddElementsToNonResizableList(QGraphicsItem *element)
{
    non_resizable_elements_.append(element);
}

void GraphicDrawer::ResetNonResizableElements()
{
    non_resizable_elements_.clear();
}

void GraphicDrawer::RemoveElementFromResizableElements(QGraphicsItem *elements)
{
//TODO
    return;
}
