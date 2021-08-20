#include "graphicdrawer.h"




void GraphicDrawer::DrawViewElementsList(QList<LineModel *> to_draw)
{
    QString last_type =  "";
    qreal start_position = 0;
    QBrush last_brush;

    for (auto &e : to_draw)
    {
        auto text_item = label_view_->scene()->addText(e->GetLabel());
        text_item->setPos(-500 + label_view_->rect().width()/2,e->GetOriginY());


        //Everytime we switch types, we draw a label, and create a type line
        if (e->GetType() != last_type)
        {
            //If start_position has been set before, we draw a label line
            if (start_position || (start_position && e == to_draw.last()))
            {


                label_view_->scene()->addLine(-500 + label_view_->rect().width()/3,
                                              start_position,
                                              -500 + label_view_->rect().width()/3,
                                              e->GetOriginY()-45,
                                              QPen(last_brush,10));
            }

            //Create new Type Label & set it
            auto label_item = label_view_->scene()->addText(e->GetType());
            label_item->setPos(-500 + label_view_->rect().width()/2.5,e->GetOriginY() - 30);

            //Make it's font bold
            QFont new_font = label_item->font();
            new_font.setBold(true);
            label_item->setFont(new_font);


            last_type = e->GetType();
            start_position = e->GetOriginY() - 15;
            last_brush = e->GetBrush();

        }

    }

    //We draw the last missing line
    if (start_position)
    {


        label_view_->scene()->addLine(-500 + label_view_->rect().width()/3,
                                      start_position,
                                      -500 + label_view_->rect().width()/3,
                                      start_position + 90,
                                      QPen(last_brush,10));
    }


    //Adding the Markers Label manually, as it is a seperate class of item
    auto text_item = label_view_->scene()->addText("Markers");
    text_item->setPos(-500 + label_view_->rect().width()/2,current_y_-35);


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


    if (DataAccessor::GetTasks().count() > 0)
    {
        drawn_view_elements_.append(DrawViewElementList(DataAccessor::GetTasks(),Qt::red,false,"Tasks"));
        current_y_ += 50;
    }

    if (DataAccessor::GetHandlers().count() > 0)
    {
        drawn_view_elements_.append(DrawViewElementList(DataAccessor::GetHandlers(),Qt::blue,false,"Handlers"));
        current_y_ += 50;
    }

    if (DataAccessor::GetQueues().count() > 0)
    {
        drawn_view_elements_.append(DrawViewElementList(DataAccessor::GetQueues(), Qt::green,true,"Queues"));
        current_y_ += 50;
    }

    if (DataAccessor::GetUserAgents().count() > 0)
    {
        drawn_view_elements_.append(DrawViewElementList(DataAccessor::GetUserAgents(), Qt::cyan,false,"User Agents"));
        current_y_ += 50;
    }


    DrawMarkers();


    AxisManager::SetYAxis(current_y_,view_,true);


}

void GraphicDrawer::AdjustNonResizableElements()
{

    QTransform i_transform;
    for (auto i : non_resizable_elements_)
    {
        i_transform = i->transform();
        i->setTransform(i_transform);
    }
    ResizeMarkerWidth();
}

void GraphicDrawer::ResizeMarkerWidth()
{

    QTransform i_transform;
    for (auto i : drawn_markers_)
    {

        i->setRect(i->rect().x(),
                   i->rect().y(),
                   i->rect().width() * MouseZoomHandler::GetLastZoomStep().x(),
                   i->rect().height() * MouseZoomHandler::GetLastZoomStep().y()
                   );
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
    if (non_resizable_elements_.contains(element))
        non_resizable_elements_.removeAll(element);

    return;
}

void GraphicDrawer::DrawLabels(QGraphicsView *label_view)
{

    //If the scene has not been prepared yet, we do that
    if (!label_view->scene())
    {
        label_view->setScene(new QGraphicsScene());
        label_view->setInteractive(false);
        label_view->setAlignment(Qt::AlignTop);
        label_view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        label_view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

        label_view_ = label_view;
    }

    label_view->scene()->addLine(-700,-1000,-700,1000);
    label_view->scene()->addLine(700,-1000,700,1000);
    label_view_->fitInView(-500,view_->mapToScene(view_->rect().topLeft()).y() + 20,200,view_->rect().height(),Qt::KeepAspectRatioByExpanding);

    if (!drawn_view_elements_.empty())
        DrawViewElementsList(drawn_view_elements_);


}

void GraphicDrawer::AdjustLabelViewPosition()
{
    if (label_view_ == nullptr)
        return;

    label_view_->fitInView(-500,view_->mapToScene(view_->rect().topLeft()).y() + 20,200,view_->rect().height(),Qt::KeepAspectRatioByExpanding);

}

QList<LineModel *> GraphicDrawer::GetDrawnElements()
{
    return drawn_view_elements_;
}

void GraphicDrawer::Reset()
{
    //The main view is always passed at this point
    view_->scene()->clear();

    //The label_view is only passed after the first runthrough
    if (label_view_)
        label_view_->scene()->clear();


    //cleanup
    for (auto e : drawn_markers_)
        delete(e);
    drawn_markers_.clear();
    for (auto e : drawn_view_elements_)
        delete(e);
    drawn_view_elements_.clear();
    for (auto e : non_resizable_elements_)
        delete(e);
    non_resizable_elements_.clear();

    current_y_ = 0;



}

qreal GraphicDrawer::GetViewPortLeft()
{
    return view_->mapToScene(view_->rect().topLeft()).x();
}

qreal GraphicDrawer::GetViewPortRight()
{
    return view_->mapToScene(view_->rect().topRight()).x();
}


void GraphicDrawer::DrawMarkers()
{

    auto markers_to_draw = DataAccessor::GetMarkers();
    QGraphicsRectItem* new_item = nullptr;

    //Offset to draw multiple lines of markers. We support
    qreal offset = 0;
    QString tooltip = "";

    for(auto e : markers_to_draw)
    {

        for (auto m : e.GetEntries())
        {
            new_item = new QGraphicsRectItem(m.GetPosition() - 15,
                                             current_y_ + offset,
                                             AxisManager::GetXAxisLenght() / 1500,
                                             30);
            new_item->setBrush(m.GetColor());
            view_->scene()->addItem(new_item);

            //Generate Tooltip
            tooltip = "Marker: " + e.GetName() + '\n';
            //Only if we have a number, we add it to the tooltip
            if(m.GetNumber() != 0)
                tooltip += "Number: " + QString::number(m.GetNumber()) + '\n';


            //Add all strings in the list to the tooltip
            if (!m.GetStrings()->isEmpty())
            {
                int i = 0;
                for (const auto &s : *m.GetStrings())
                {
                    tooltip += "String " + QString::number(i) + " :" + s + '\n';
                    i++;
                }

                new_item->setToolTip(tooltip);

            }

            drawn_markers_.append(new_item);
        }

        //Draw all positions for the current marker

        //advance offset
        offset += 35;
    }

    current_y_+=offset;

}

