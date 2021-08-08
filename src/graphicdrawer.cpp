#include "graphicdrawer.h"



void GraphicDrawer::DrawMarkers()
{
    current_y_ += 150;
}

void GraphicDrawer::DrawViewElementsList(QList<LineModel *> to_draw)
{
    for (auto &e : to_draw)
    {
        auto text_item = label_view_->scene()->addText(e->GetLabel());
        text_item->setPos(-500 + label_view_->rect().width()/2,e->GetOriginY());
    }

}


void GraphicDrawer::SetView(QGraphicsView *view)
{
    view_ = view;
}

void GraphicDrawer::DrawAxis()
{
    AxisManager::SetOrigin(QVector2D(0,0));


    AxisManager::SetXAxis(DataAccessor::GetXAxisLenght(),view_);
    AddElementsToNonResizableList(AxisManager::SetYAxis(500,view_,true));
    AxisManager::SetLineDistance(100);
    MouseZoomHandler::SetMaxScale(DataAccessor::GetXAxisLenght() / 5);
    MouseZoomHandler::SetCurrentZoomToMax();
}

void GraphicDrawer::DrawData()
{
    drawn_elements_.append(DrawViewElementList(DataAccessor::GetTasks()));
    current_y_ += 55;
    drawn_elements_.append(DrawViewElementList(DataAccessor::GetHandlers()));
    current_y_ += 55;
    drawn_elements_.append(DrawViewElementList(DataAccessor::GetQueues()));
    current_y_ += 55;
    drawn_elements_.append(DrawViewElementList(DataAccessor::GetUserAgents()));

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

void GraphicDrawer::DrawLabels(QGraphicsView *label_view)
{

    label_view->setScene(view_->scene());
    label_view->setInteractive(false);
    label_view->setAlignment(Qt::AlignTop);
    label_view_ = label_view;

    DrawViewElementsList(drawn_elements_);
    label_view_->fitInView(-500,0,100,500);
}

void GraphicDrawer::AdjustLabelViewPosition()
{
    if (label_view_ == nullptr)
        return;

   /*//main_view->mapToScene((main_view->rect().topLeft())).x() - main_view->mapToScene(main_view->rect().topRight()).x();

    qDebug("%f",view_->mapToScene(view_->rect().topLeft()).y());

    auto rect = view_->sceneRect();
    rect.setWidth(100);
    rect.setX(-500);
    label_view_->setSceneRect(rect);
    label_view_->centerOn(rect.center());
*/
}

