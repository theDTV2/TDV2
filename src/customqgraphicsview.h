#ifndef CUSTOMQGRAPHICSVIEW_H
#define CUSTOMQGRAPHICSVIEW_H

#include <QGraphicsView>
#include <QWheelEvent>
#include "graphicdrawer.h"


class customQGraphicsView : public QGraphicsView
{
public:
    customQGraphicsView(QWidget * parent = nullptr);
    customQGraphicsView(QGraphicsScene * scene, QWidget * parent = nullptr);


    void SetAwayFunction(void (*away_function)(void));
    void SetTowardFunction(void (*toward_function)(void));
    void SetResizeFunction(void (*resize_function)(void));

    void SetEnableControls(bool value);
    bool GetEnableControls();

protected:
    virtual void wheelEvent(QWheelEvent * event) override;
    virtual void mouseMoveEvent(QMouseEvent *event) override;
    virtual void resizeEvent(QResizeEvent *event) override;
    virtual void keyPressEvent(QKeyEvent *event) override;
    virtual void scrollContentsBy(int dx, int dy) override;
    virtual void mousePressEvent(QMouseEvent *event) override;

private:
    void (*func_away_)(void) = NULL;
    void (*func_towards_)(void) = NULL;
    void (*func_resize_)(void) = NULL;

    bool enable_controls_ = true;

    QString selected_view_element_;

};

#endif // CUSTOMQGRAPHICSVIEW_H
