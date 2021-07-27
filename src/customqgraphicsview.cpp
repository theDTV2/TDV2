#include "customqgraphicsview.h"

customQGraphicsView::customQGraphicsView(QWidget * parent)
: QGraphicsView(parent) {}

customQGraphicsView::customQGraphicsView(QGraphicsScene * scene, QWidget * parent)
: QGraphicsView(scene, parent) {}

void customQGraphicsView::wheelEvent(QWheelEvent * event)
{
    //event->;
    QGraphicsView::wheelEvent(event);
}
