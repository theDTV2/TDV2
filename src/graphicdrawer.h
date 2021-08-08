#ifndef GRAPHICDRAWER_H
#define GRAPHICDRAWER_H
#include <QtGlobal>
#include <QGraphicsItem>
#include <QList>

#include "linemodel.h"
#include "mousezoomhandler.h"
#include "axismanager.h"
#include "dataaccessor.h"

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

private:

    static void DrawMarkers();

    inline static QList<QGraphicsItem*> non_resizable_elements_ = QList<QGraphicsItem*>();
    inline static QGraphicsView* view_ = nullptr;
    inline static QList<LineModel*> drawn_elements_  = QList<LineModel*>();
    inline static qreal current_y_ = 125;



    template <class T>
    static QList<LineModel*> DrawViewElementList(T list)
    {    LineModel* model;
         QList<LineModel*> return_list;

          for (auto &e : list)
          {
              model = new LineModel(0,current_y_,e.GetName(),e,view_);
              return_list.append(model);
              current_y_ += 55;
          }

           return return_list;

    }

};

#endif // GRAPHICDRAWER_H
