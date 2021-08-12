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
    current_y_ = 125;


    drawn_elements_.append(DrawViewElementList(DataAccessor::GetTasks()));
    current_y_ += 50;
    drawn_elements_.append(DrawViewElementList(DataAccessor::GetHandlers(),Qt::blue));
    current_y_ += 50;
    drawn_elements_.append(DrawViewElementList(DataAccessor::GetQueues(), Qt::green,true));
    current_y_ += 50;
    drawn_elements_.append(DrawViewElementList(DataAccessor::GetUserAgents(), Qt::yellow));

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
    if (label_view->scene() != nullptr)
        label_view->scene()->clear();

    if (drawn_elements_.empty())
        drawn_elements_.clear();

    label_view->setScene(new QGraphicsScene());
    label_view->setInteractive(false);
    label_view->setAlignment(Qt::AlignTop);
    label_view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    label_view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    ((customQGraphicsView*)label_view)->SetEnableKeyboardControls(false);

    label_view_ = label_view;

    label_view->scene()->addLine(-700,-1000,-700,1000);
    label_view->scene()->addLine(700,-1000,700,1000);
    label_view_->fitInView(-500,view_->mapToScene(view_->rect().topLeft()).y() + 20,200,view_->rect().height(),Qt::KeepAspectRatioByExpanding);

    DrawViewElementsList(drawn_elements_);

}

void GraphicDrawer::AdjustLabelViewPosition()
{
    if (label_view_ == nullptr)
        return;

    label_view_->fitInView(-500,view_->mapToScene(view_->rect().topLeft()).y() + 20,200,view_->rect().height(),Qt::KeepAspectRatioByExpanding);




}

