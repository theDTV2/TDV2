#ifndef AXISMANAGER_H
#define AXISMANAGER_H

#include <QVector2D>
#include <QGraphicsView>


#include "axismodel.h"



class AxisManager
{
public:



    static void SetOrigin(QVector2D origin);
    static AxisModel* SetXAxis(qreal lenght, QGraphicsView* view, bool disable_spacing = false);
    static AxisModel* SetYAxis(qreal lenght, QGraphicsView* view, bool disable_spacing = false);
    static void SetPenThickness(qreal var);
    static void UpdateSpacing();
    static void SetLineDistance(qreal dist);

private:
    inline static AxisModel* x_axis_line_ = nullptr;
    inline static AxisModel* y_axis_line_ = nullptr;
    inline static QVector2D origin_point_ = QVector2D(0,0);
    inline static QPen pen_;


};

#endif // AXISMANAGER_H
