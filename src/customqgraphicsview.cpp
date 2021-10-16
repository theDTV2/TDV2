#include "customqgraphicsview.h"

customQGraphicsView::customQGraphicsView(QWidget * parent)
    : QGraphicsView(parent) {
    enable_controls_ = false;

}

customQGraphicsView::customQGraphicsView(QGraphicsScene * scene, QWidget * parent)
    : QGraphicsView(scene, parent) {}

/*
 * Overriden Handler for the wheelEvent (called each time the mouse wheel is used)
 * if the customGraphicsView function pointers are not set, the function will not do anything
 * Otherwise it triggers the required functions to process zooming
 * */
void customQGraphicsView::wheelEvent(QWheelEvent * event)
{
    if (!func_away_)
        return;

    if (event->type() == QEvent::Wheel)
    {
        QWheelEvent *mouse_event = static_cast<QWheelEvent*> (event);

        if (mouse_event->angleDelta().y() > 0)
        {
            func_away_();
        }
        else
        {
            func_towards_();
        }
        func_resize_();

        GraphicDrawer::AdjustLabelViewPosition();

        //ignore_check is set to true, otherwise we would get ugly artifacts while zooming
        AxisManager::UpdateSpacing(true);

    }

}

/*
 * Overriden Handler for the mouseMoveEvent (called each time the mouse is moved)
 * */
void customQGraphicsView::mouseMoveEvent(QMouseEvent *event)
{
    QGraphicsView::mouseMoveEvent(event);

    AxisManager::UpdateSpacing();
    GraphicDrawer::AdjustLabelViewPosition();

}

/*
 * Overriden Handler for the resizeEvent (called each time the main window is resized)
 * */
void customQGraphicsView::resizeEvent(QResizeEvent *event)
{
    QGraphicsView::resizeEvent(event);

    AxisManager::UpdateSpacing();
    GraphicDrawer::AdjustLabelViewPosition();
}

/*
 * Overriden Handler for the resizeEvent (called each time a key is pressed)
 * Only if controls are enabled for a view, we handle the keyPressEvents
 * */
void customQGraphicsView::keyPressEvent(QKeyEvent *event)
{
    if (enable_controls_)
    {
        QGraphicsView::keyPressEvent(event);
        AxisManager::UpdateSpacing();
        GraphicDrawer::AdjustLabelViewPosition();
    }

}

/*
 * Overriden Handler for the scrollContentsBy (called each time the view is scrolled)
 * */
void customQGraphicsView::scrollContentsBy(int dx, int dy)
{
    AxisManager::UpdateSpacing();
    QGraphicsView::scrollContentsBy(dx,dy);
}

/*
 * Overriden Handler for the mousePressEvent (called each a mouse button is pressed)
 * */
void customQGraphicsView::mousePressEvent(QMouseEvent *event)
{
    if (enable_controls_)
    {
        //Selects view element at current height, this has been added for future extensions
        //Proper view element selection is not yet implemented
        GraphicDrawer::SetViewElementNameAtHeight(mapToScene(event->pos()).y());
        QGraphicsView::mousePressEvent(event);
    }
}

/**
 * @brief simple setter
 */
void customQGraphicsView::SetAwayFunction(void (*away_function)(void))
{
    func_away_ = away_function;
}

/**
 * @brief simple setter
 */
void customQGraphicsView::SetTowardFunction(void (*toward_function)(void))
{
    func_towards_ = toward_function;
}

/**
 * @brief simple setter
 */
void customQGraphicsView::SetResizeFunction(void (*resize_function)())
{
    func_resize_ = resize_function;
}

/**
 * @brief simple setter
 */
void customQGraphicsView::SetEnableControls(bool value)
{
    enable_controls_ = value;
}

/**
 * @brief simple getter
 * @return if controls are enabled
 */
bool customQGraphicsView::GetEnableControls()
{
    return enable_controls_;
}
