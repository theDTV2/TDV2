#ifndef LINEMODELHELPER_H
#define LINEMODELHELPER_H
#include "linemodel.h"

class LineModelHelper
{
public:
static qreal GetExecutionTimeFromLineModel(LineModel* model);
static qreal GetExecutionTimeFromLineModel(LineModel* model, qreal start_time, qreal end_time);

private:

};

#endif // LINEMODELHELPER_H
