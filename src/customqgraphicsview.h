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


    void SetAwayFunction(void (*away_function)(void));
    void SetTowardFunction(void (*toward_function)(void));
    void SetResizeFunction(void (*resize_function)(void));


protected:
    virtual void wheelEvent(QWheelEvent * event) override;
    virtual void mouseMoveEvent(QMouseEvent *event) override;

    virtual void resizeEvent(QResizeEvent *event) override;

private:
    void (*func_away_)(void);
    void (*func_towards_)(void);
    void (*func_resize_)(void);


};

#endif // CUSTOMQGRAPHICSVIEW_H
