#ifndef LINEMODELHELPER_H
#define LINEMODELHELPER_H
#include "linemodel.h"

class LineModelHelper
{
public:

static qreal GetExecutionTimeFromLineModel(LineModel* model, qreal start_time = 0, qreal end_time = std::numeric_limits<qreal>::max());
static qreal GetAverageExecutionLenghtAndMinMax(LineModel* model, qreal start_time = 0, qreal end_time = std::numeric_limits<qreal>::max());
static quint32 GetAmountOfExecutions(LineModel* model, qreal start_time = 0, qreal end_time = std::numeric_limits<qreal>::max());


static qreal GetLastMinLenght();
static qreal GetLastMaxLenght();

private:
    static inline qreal min_lenght_;
    static inline qreal max_lenght_;

};

#endif // LINEMODELHELPER_H
