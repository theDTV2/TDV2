#include "customqgraphicsview.h"

customQGraphicsView::customQGraphicsView(QWidget * parent)
: QGraphicsView(parent) {}

customQGraphicsView::customQGraphicsView(QGraphicsScene * scene, QWidget * parent)
: QGraphicsView(scene, parent) {}

void customQGraphicsView::wheelEvent(QWheelEvent * event)
{

    if (event->type() == QEvent::Wheel)
    {
        if (!func_away_)
            return;

        QWheelEvent *mouse_event = static_cast<QWheelEvent*> (event);

        if (mouse_event->angleDelta().y() > 0)
        {
            func_away_();
            func_resize_();

        }

        func_towards_();
        func_resize_();
    }

    GraphicDrawer::AdjustLabelViewPosition();
    AxisManager::UpdateSpacing(true);


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




    if (enable_keyboard_controls_)
    {
        QGraphicsView::keyPressEvent(event);
        AxisManager::UpdateSpacing();
        GraphicDrawer::AdjustLabelViewPosition();
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

void customQGraphicsView::SetEnableKeyboardControls(bool value)
{
    enable_keyboard_controls_ = value;
}

bool customQGraphicsView::GetEnableKeyboardControls()
{
    return enable_keyboard_controls_;
}
