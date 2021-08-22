#include "linemodelhelper.h"





qreal LineModelHelper::GetExecutionTimeFromLineModel(LineModel *model, qreal start_time, qreal end_time)
{
    min_lenght_ = std::numeric_limits<qreal>::max();
    max_lenght_ = 0;

    qreal result = 0;
    for (auto e : model->GetDrawnElements())
    {
        if (e->rect().left() >= start_time && e->rect().right() <= end_time)
        {
            result += e->rect().width();

            //Populate min/max with values
            if (e->rect().width() < min_lenght_)
                min_lenght_ = e->rect().width();
            if (e->rect().width() > max_lenght_)
                max_lenght_ = e->rect().width();
        }



    }
    return result;
}

qreal LineModelHelper::GetAverageExecutionLenghtAndMinMax(LineModel *model, qreal start_time, qreal end_time)
{

    qreal counter = GetAmountOfExecutions(model,start_time, end_time);
    qreal result = GetExecutionTimeFromLineModel(model);
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

qreal LineModelHelper::GetLastMinLenght()
{
    return min_lenght_;
}

qreal LineModelHelper::GetLastMaxLenght()
{
    return max_lenght_;
}



