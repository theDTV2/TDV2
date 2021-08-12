#ifndef GRAPHICDRAWER_H
#define GRAPHICDRAWER_H
#include <QtGlobal>
#include <QGraphicsItem>
#include <QList>

#include "linemodel.h"
#include "mousezoomhandler.h"
#include "axismanager.h"
#include "dataaccessor.h"
#include "customqgraphicsview.h"

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


private:

    static void DrawMarkers();
    static void DrawViewElementsList(QList<LineModel*> to_draw);


    inline static QList<QGraphicsItem*> non_resizable_elements_ = QList<QGraphicsItem*>();
    inline static QGraphicsView* view_ = nullptr;
    inline static QGraphicsView* label_view_ = nullptr;

    inline static QList<LineModel*> drawn_elements_  = QList<LineModel*>();
    inline static qreal current_y_ = 125;




    template <class T>
    static QList<LineModel*> DrawViewElementList(T list, QBrush brush = Qt::black)
    {
        LineModel* model;
        QList<LineModel*> return_list;

        for (auto &e : list)
        {
            model = new LineModel(0,current_y_,e.GetName(),e,view_, brush);
            return_list.append(model);
            current_y_ += 55;
        }
        return return_list;
    }









};

#endif // GRAPHICDRAWER_H
