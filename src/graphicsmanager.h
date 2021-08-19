#ifndef GRAPHICSMANAGER_H
#define GRAPHICSMANAGER_H

#include <QGraphicsTextItem>

#include "graphicdrawer.h"

#include "customqgraphicsview.h"

class GraphicsManager
{
public:

static void SetupScene(customQGraphicsView *main_view, customQGraphicsView *label_view);

static void ResizeFunction();

private:



};

#endif // GRAPHICSMANAGER_H
