#include "linemodelhelper.h"


/**
 * @brief Uses a given LineModel to calculate execution time. Only calculate values between start/end time. Also saves max/min value in static values
 * @param model model to calculate for
 * @param start_time start_time to calculate on
 * @param end_time end_time to calculate on
 * @return total execution time in time frame
 */
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

    //If no min is set, we need to reset it.
    if ( min_lenght_ == std::numeric_limits<qreal>::max())
        min_lenght_ = 0;

    return result;
}

/**
 * @brief Calculates average execution time for given model
 * @param model model to calculate for
 * @param start_time start_time to calculate on
 * @param end_time end_time to calculate on
 * @return average execution time in time frame
 */
qreal LineModelHelper::GetAverageExecutionLenghtAndMinMax(LineModel *model, qreal start_time, qreal end_time)
{

    qreal counter = GetAmountOfExecutions(model,start_time, end_time);
    qreal result = GetExecutionTimeFromLineModel(model);

    //Prevent div by 0 when no items are in view
    if (result == 0)
        return 0;

    return result / counter;

}

/**
 * @brief Counts the amount of executions in time frame.
 * @param model model to calculate for
 * @param start_time start_time to calculate on
 * @param end_time end_time to calculate on
 * @return total amount of executions in time frame
 */
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

/**
 * @brief getter for min lenght. Value is calculated at last execution of GetAverageExecutionLenghtAndMinMax
 * @return min
 */
qreal LineModelHelper::GetLastMinLenght()
{
    return min_lenght_;
}

/**
 * @brief getter for min lenght. Value is calculated at last execution of GetAverageExecutionLenghtAndMinMax
 * @return max
 */
qreal LineModelHelper::GetLastMaxLenght()
{
    return max_lenght_;
}



