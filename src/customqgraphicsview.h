#ifndef CUSTOMQGRAPHICSVIEW_H
#define CUSTOMQGRAPHICSVIEW_H

#include <QGraphicsView>
#include <QWheelEvent>
#include "axismanager.h"


class customQGraphicsView : public QGraphicsView
{
public:
    customQGraphicsView(QWidget * parent = nullptr);
    customQGraphicsView(QGraphicsScene * scene, QWidget * parent = nullptr);

protected:
    virtual void wheelEvent(QWheelEvent * event) override;
    virtual void mouseMoveEvent(QMouseEvent *event) override;

   // virtual void move
};

#endif // CUSTOMQGRAPHICSVIEW_H
