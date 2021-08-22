#include "linemodelhelper.h"





qreal LineModelHelper::GetExecutionTimeFromLineModel(LineModel *model, qreal start_time, qreal end_time)
{


    qreal result = 0;
    for (auto e : model->GetDrawnElements())
    {
        if (e->rect().left() >= start_time && e->rect().right() <= end_time)
            result += e->rect().width();

    }
    return result;
}

qreal LineModelHelper::GetAverageExeutionLenght(LineModel *model, qreal start_time, qreal end_time)
{

    qreal counter = GetAmountOfExecutions(model, start_time, end_time);
    qreal result = GetExecutionTimeFromLineModel(model, start_time, end_time);

    return result / counter;

}

quint32 LineModelHelper::GetAmountOfExecutions(LineModel *model, qreal start_time, qreal end_time)
{
    qreal counter = 0;
    for (auto e : model->GetDrawnElements())
    {
        if (e->rect().left() >= start_time && e->rect().right() <= end_time)
            counter++;
    }
    return counter;

}



