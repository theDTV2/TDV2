#ifndef GRAPHICSMANAGER_H
#define GRAPHICSMANAGER_H

#include <QGraphicsTextItem>

#include "graphicdrawer.h"


class GraphicsManager
{
public:

static void SetupScene(QGraphicsView *view_to_setup);

static void ResizeFunction();

private:

static void DrawAxis();

};

#endif // GRAPHICSMANAGER_H
