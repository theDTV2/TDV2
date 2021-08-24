#ifndef GRAPHICDRAWER_H
#define GRAPHICDRAWER_H
#include <QtGlobal>
#include <QGraphicsItem>
#include <QList>

#include "linemodel.h"
#include "mousezoomhandler.h"

#include "dataaccessor.h"

#define LINE_HEIGHT 50

class GraphicDrawer
{
public:

    static void SetView(QGraphicsView* view);
    static void DrawAxis();
    static void DrawData();
    static void AdjustNonResizableElements();
    static void AddElementsToNonResizableList(QGraphicsItem* elements);

    static void ResetNonResizableElements();
    static void RemoveElementFromResizableElements(QGraphicsItem* element);

    static void DrawLabels(QGraphicsView* label_view);
    static void AdjustLabelViewPosition();
    static QList<LineModel*> GetDrawnElements();

    static void Reset();

    static qreal  GetViewPortLeft();
    static qreal  GetViewPortRight();
    static void SetViewElementNameAtHeight(qreal y);
    static QString GetSelectedViewElement();

private:

    static void ResizeMarkerWidth();
    static void DrawMarkers();
    static void DrawViewElementsList(QList<LineModel*> to_draw);


    inline static QList<QGraphicsItem*> non_resizable_elements_ = QList<QGraphicsItem*>();
    inline static QGraphicsView* view_ = nullptr;
    inline static QGraphicsView* label_view_ = nullptr;
    inline static QList<QGraphicsRectItem*> drawn_markers_ = QList<QGraphicsRectItem*>();
    inline static QList<LineModel*> drawn_view_elements_  = QList<LineModel*>();
    inline static qreal current_y_ = 125;
    inline static QString selected_view_element_ = "";


    template <class T>
    static QList<LineModel*> DrawViewElementList(T list, QBrush brush = Qt::black, bool use_height = false, QString type = "No Type")
    {
        LineModel* model;
        QList<LineModel*> return_list;

        for (auto &e : list)
        {
            model = new LineModel(0,current_y_,e.GetName(),e,view_, brush,use_height);
            model->SetType(type);
            return_list.append(model);
            current_y_ += LINE_HEIGHT + LINE_SPACER;
        }
        return return_list;
    }

};

#endif // GRAPHICDRAWER_H
