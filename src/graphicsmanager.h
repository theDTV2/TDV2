#ifndef GRAPHICSMANAGER_H
#define GRAPHICSMANAGER_H

#include <QGraphicsTextItem>

#include "graphicdrawer.h"
#include "axismanager.h"


class GraphicsManager
{
public:

static void SetupScene(QGraphicsView *main_view, QGraphicsView *label_view);

static void ResizeFunction();

private:



};

#endif // GRAPHICSMANAGER_H
