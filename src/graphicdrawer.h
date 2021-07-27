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

    inline static qreal text_spacing_left_ = 25;
    inline static qreal text_spacing_right_ = 25;
    inline static qreal text_label_width_ = 300;
};

#endif // GRAPHICDRAWER_H
