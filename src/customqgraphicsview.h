#ifndef CUSTOMQGRAPHICSVIEW_H
#define CUSTOMQGRAPHICSVIEW_H

#include <QGraphicsView>
#include <QWheelEvent>

class customQGraphicsView : public QGraphicsView
{
public:
    customQGraphicsView(QWidget * parent = nullptr);
    customQGraphicsView(QGraphicsScene * scene, QWidget * parent = nullptr);

protected:
    virtual void wheelEvent(QWheelEvent * event);
};

#endif // CUSTOMQGRAPHICSVIEW_H
