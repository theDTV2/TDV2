#include "customqgraphicsview.h"

customQGraphicsView::customQGraphicsView(QWidget * parent)
: QGraphicsView(parent) {
    enable_controls_ = false;
}

customQGraphicsView::customQGraphicsView(QGraphicsScene * scene, QWidget * parent)
: QGraphicsView(scene, parent) {}

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
        AxisManager::UpdateSpacing(true);

    }

}

void customQGraphicsView::mouseMoveEvent(QMouseEvent *event)
{
    QGraphicsView::mouseMoveEvent(event);

    AxisManager::UpdateSpacing();
    GraphicDrawer::AdjustLabelViewPosition();

}

void customQGraphicsView::resizeEvent(QResizeEvent *event)
{
    QGraphicsView::resizeEvent(event);

    AxisManager::UpdateSpacing();
    GraphicDrawer::AdjustLabelViewPosition();

}

void customQGraphicsView::keyPressEvent(QKeyEvent *event)
{

    if (enable_controls_)
    {

        QGraphicsView::keyPressEvent(event);
        AxisManager::UpdateSpacing();
        GraphicDrawer::AdjustLabelViewPosition();
    }

}

void customQGraphicsView::scrollContentsBy(int dx, int dy)
{

    AxisManager::UpdateSpacing();

    QGraphicsView::scrollContentsBy(dx,dy);
}

void customQGraphicsView::mousePressEvent(QMouseEvent *event)
{
    if (enable_controls_)
    {
        GraphicDrawer::SetViewElementNameAtHeight(mapToScene(event->pos()).y());

        QGraphicsView::mousePressEvent(event);
    }
}


void customQGraphicsView::SetAwayFunction(void (*away_function)(void))
{
    func_away_ = away_function;
}

void customQGraphicsView::SetTowardFunction(void (*toward_function)(void))
{
    func_towards_ = toward_function;
}

void customQGraphicsView::SetResizeFunction(void (*resize_function)())
{
    func_resize_ = resize_function;
}

void customQGraphicsView::SetEnableControls(bool value)
{
    enable_controls_ = value;
}

bool customQGraphicsView::GetEnableControls()
{
    return enable_controls_;
}
