#include "customqgraphicsview.h"

customQGraphicsView::customQGraphicsView(QWidget * parent)
: QGraphicsView(parent) {}

customQGraphicsView::customQGraphicsView(QGraphicsScene * scene, QWidget * parent)
: QGraphicsView(scene, parent) {}

void customQGraphicsView::wheelEvent(QWheelEvent * event)
{

    if (event->type() == QEvent::Wheel)
    {
        QWheelEvent *mouse_event = static_cast<QWheelEvent*> (event);

        if (mouse_event->angleDelta().y() > 0)
        {
            func_away_();
            func_resize_();

        }

        func_towards_();
        func_resize_();

    }
    AxisManager::UpdateSpacing(true);


}

void customQGraphicsView::mouseMoveEvent(QMouseEvent *event)
{

    AxisManager::UpdateSpacing();
    QGraphicsView::mouseMoveEvent(event);

}

void customQGraphicsView::resizeEvent(QResizeEvent *event)
{
    AxisManager::UpdateSpacing();
    QGraphicsView::resizeEvent(event);
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
