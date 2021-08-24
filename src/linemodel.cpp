#include "linemodel.h"

/**
 * @brief Line Model used to draw viewelements. It contains a list of drawn rectangles
 * @param x start position x
 * @param y start position y
 * @param label label value
 * @param element ViewElement to display on this line
 * @param view view to display it on
 * @param brush brush to draw on
 * @param use_height toggle if height is shown. (used in queues)
 */
LineModel::LineModel(qreal x, qreal y,const QString& label,const ViewElement& element, QGraphicsView* view,  QBrush brush, bool use_height)
    :origin_x_(x),origin_y_(y), label_(label),to_be_displayed_element_(element), used_view_(view), used_brush_(brush)
{
    RefreshDrawnItems(use_height);
}


/**
 * @brief setter
 * @param x x to set
 * @param y y to set
 */
void LineModel::SetOrigin(qreal x, qreal y)
{
    origin_x_ = x;
    origin_y_ = y;
}

/**
 * @brief getter
 * @return x
 */
qreal LineModel::GetOriginX() const
{
    return origin_x_;
}

/**
 * @brief getter
 * @return y
 */
qreal LineModel::GetOriginY() const
{
    return origin_y_;
}

/**
 * @brief Set ViewElement to be drawn
 * @param to_set ViewElement to draw
 */
void LineModel::SetDisplayedElement(const ViewElement& to_set)
{
    to_be_displayed_element_ = to_set;
}

/**
 * @brief getter
 * @return view element
 */
ViewElement LineModel::GetDisplayedElement()
{
    return to_be_displayed_element_;
}

/**
 * @brief getter
 * @return label used for View Element
 */
QString LineModel::GetLabel() const
{
    return label_;
}

/**
 * @brief getter
 * @return drawn elements
 */
QList<QGraphicsRectItem*> LineModel::GetDrawnElements() const
{
    return drawn_elements_;
}

/**
 * @brief setter
 * @param type type to set
 */
void LineModel::SetType(const QString& type)
{
    type_ = type;
}

/**
 * @brief getter
 * @return type
 */
QString LineModel::GetType()
{
    return type_;
}

/**
 * @brief getter
 * @return brush
 */
QBrush LineModel::GetBrush()
{
    return used_brush_;
}

/**
 * @brief setter
 * @param new_brush brush to set
 */
void LineModel::SetBrush(QBrush new_brush)
{
    used_brush_ = new_brush;
}

/**
 * @brief Uses the DataPairs in to_be_displayed_element_ to draw the elements on the y-axis
 * @param use_height should height values be displayed?
 */
void LineModel::RefreshDrawnItems(bool use_height)
{
    for(auto &e : drawn_elements_)
    {
        delete e;
    }

    QList<DataPair>* list = to_be_displayed_element_.GetList();

    quint16 max = 0;
    //If we draw height (for queues), we do that here, otherwise we skip to regular drawing
    //If we draw height, we must assume that we are dealing with an QueueModel,
    //otherwise height data won't be populated
    if (use_height)
    {
        //Get the max height value


      /*  for (auto e : *list)
            if (e.GetHeight() > max)
                max = e.GetHeight();

*/

        if (!list->isEmpty())
            max =  std::max_element(list->begin(),
                                    list->end(),
                                    [](const DataPair& a,const DataPair& b){return (a.GetHeight() < b.GetHeight());})->GetHeight();



        //draw steps with max + 1 as maximum step. This is to prevent clipping
    }


    for(auto e : *list)
    {
        QGraphicsRectItem* new_item = nullptr;
        //We either draw regular boxes, or height boxes
        if (max == 0)
            new_item = new QGraphicsRectItem(origin_x_ + e.GetStartTime(),
                                             origin_y_ - 25,
                                             e.GetLenght(),
                                             50);
        else
        {
            qreal offset = 50 - (50 * ((e.GetHeight()) / (double) max));
            new_item = new QGraphicsRectItem(origin_x_ + e.GetStartTime(),
                                             (origin_y_ - 25) + offset,
                                             e.GetLenght(),
                                             50 * ((e.GetHeight()) / (double) max)); //We need to cast here to use the double "/" Operator



            new_item->setToolTip("Amount of queue elements at this position: " + QString::number(e.GetHeight()));

        }

        new_item->setBrush(used_brush_);
        drawn_elements_.append(new_item);
        used_view_->scene()->addItem(new_item);

    }




}
