#ifndef LINEMODEL_H
#define LINEMODEL_H
#include <QtGlobal>
#include <QGraphicsView>
#include <QGraphicsItem>
#include <QGraphicsRectItem>

#include "viewelement.h"


class LineModel
{
public:
    LineModel(qreal x, qreal y, QString label, ViewElement element, QGraphicsView* view);

    void SetOrigin(qreal x, qreal y);

    qreal GetOriginX();
    qreal GetOriginY();

    void SetDisplayedElement(ViewElement to_set);
    ViewElement GetDisplayedElement();

    QString GetLabel();

    void SetBrush(QBrush new_brush);

    void RefreshDrawnItems();

private:

    qreal origin_x_;
    qreal origin_y_;
    QString label_;
    ViewElement to_be_displayed_element_;
    QList<QGraphicsItem*> drawn_elements_;
    QBrush used_brush_ = Qt::blue;
    QGraphicsView* used_view_;

};



#endif // LINEMODEL_H
