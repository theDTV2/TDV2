#ifndef GRAPHICDRAWER_H
#define GRAPHICDRAWER_H
#include <QtGlobal>
#include <QGraphicsItem>
#include <QList>

#include "linemodel.h"
#include "mousezoomhandler.h"

class GraphicDrawer
{
public:
    static void DrawTask(LineModel line_to_draw);
    static void DrawQueue(LineModel line_to_draw);
    static void DrawUserAgent(LineModel line_to_draw);
    static void DrawMarkers(LineModel line_to_draw);
    static void DrawHandlers(LineModel line_to_draw);

    static void DrawAxis();
    static void AdjustNonResizableElements();
    static void AddElementsToNonResizableList(QGraphicsItem* elements);

    static void ResetNonResizableElements();
    static void RemoveElementFromResizableElements(QGraphicsItem* element);


private:
    inline static QList<QGraphicsItem*> non_resizable_elements_ = QList<QGraphicsItem*>();

};

#endif // GRAPHICDRAWER_H
