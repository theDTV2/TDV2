#include "customqgraphicsview.h"

customQGraphicsView::customQGraphicsView(QWidget * parent)
: QGraphicsView(parent) {}

customQGraphicsView::customQGraphicsView(QGraphicsScene * scene, QWidget * parent)
: QGraphicsView(scene, parent) {}

void customQGraphicsView::wheelEvent(QWheelEvent * event)
{
    AxisManager::UpdateSpacing(true);
    QGraphicsView::wheelEvent(event);
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

