#ifndef GRAPHICSVIEWDRAWER_H
#define GRAPHICSVIEWDRAWER_H
#include "mousezoomhandler.h"
#include <QGraphicsTextItem>

class GraphicsViewDrawer
{
public:

static void SetupScene(QGraphicsView *view_to_setup);

private:

static void DrawAxis();

};

#endif // GRAPHICSVIEWDRAWER_H
