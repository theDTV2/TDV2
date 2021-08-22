#ifndef LINEMODELHELPER_H
#define LINEMODELHELPER_H
#include "linemodel.h"

class LineModelHelper
{
public:

static qreal GetExecutionTimeFromLineModel(LineModel* model, qreal start_time = 0, qreal end_time = std::numeric_limits<qreal>::max());
static qreal GetAverageExeutionLenght(LineModel* model, qreal start_time = 0, qreal end_time = std::numeric_limits<qreal>::max());
static quint32 GetAmountOfExecutions(LineModel* mode, qreal start_time = 0, qreal end_time = std::numeric_limits<qreal>::max());
//static qreal GetExecutionsFrequency

private:

};

#endif // LINEMODELHELPER_H
