#include "mousezoomhelper.h"

MouseZoomHelper::MouseZoomHelper(QObject *parent) : QObject(parent)
{

}

bool MouseZoomHelper::eventFilter(QObject *obj, QEvent *event)
{
    if (event->type() == QEvent::Wheel)
    {
        QWheelEvent *mouse_event = static_cast<QWheelEvent*> (event);
        //qDebug("Ate key press %i %i", mouse_event->angleDelta().x(), mouse_event->angleDelta().y());

        if (mouse_event->angleDelta().y() > 0)
        {
            func_away_();
            func_resize_();
            return true;
        }

        func_towards_();
        func_resize_();
        return true;
    }
    else {
        // standard event processing
        return QObject::eventFilter(obj, event);
    }
}

void MouseZoomHelper::SetAwayFunction(void (*away_function)(void))
{
    func_away_ = away_function;
}
void MouseZoomHelper::SetTowardFunction(void (*toward_function)(void))
{
    func_towards_ = toward_function;
}

void MouseZoomHelper::SetResizeFunction(void (*resize_function)())
{
    func_resize_ = resize_function;
}
