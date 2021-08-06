#include "customqgraphicsview.h"

customQGraphicsView::customQGraphicsView(QWidget * parent)
: QGraphicsView(parent) {}

customQGraphicsView::customQGraphicsView(QGraphicsScene * scene, QWidget * parent)
: QGraphicsView(scene, parent) {}

void customQGraphicsView::wheelEvent(QWheelEvent * event)
{

    QGraphicsView::wheelEvent(event);
}

void customQGraphicsView::mouseMoveEvent(QMouseEvent *event)
{

    if (event->buttons() & Qt::LeftButton)
    {
        AxisManager::UpdateSpacing();
    }

    QGraphicsView::mouseMoveEvent(event);

}
