#ifndef LINEMODEL_H
#define LINEMODEL_H
#include <QtGlobal>
#include <QGraphicsView>
#include <QGraphicsItem>
#include <QGraphicsRectItem>

#include "dataaccessor.h"


class LineModel
{
public:
    LineModel(qreal x, qreal y,const QString& label,const ViewElement& element, QGraphicsView* view, QBrush brush = Qt::black, bool use_height = false);

    void SetOrigin(qreal x, qreal y);

    qreal GetOriginX() const;
    qreal GetOriginY() const;

    void SetDisplayedElement(const ViewElement& to_set);
    ViewElement GetDisplayedElement();

    QString GetLabel() const;

    QList<QGraphicsRectItem*> GetDrawnElements() const;

    void SetType(const QString& type);
    QString GetType();
    QBrush GetBrush();
    void SetBrush(QBrush new_brush);

    void RefreshDrawnItems(bool use_height);

private:

    qreal origin_x_;
    qreal origin_y_;
    QString label_;
    ViewElement to_be_displayed_element_;
    QList<QGraphicsRectItem*> drawn_elements_;
    QGraphicsView* used_view_;
    QBrush used_brush_ = Qt::blue;

    QString type_;
};



#endif // LINEMODEL_H
