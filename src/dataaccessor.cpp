#include "dataaccessor.h"


QList<TaskModel> DataAccessor::GetTasks()
{
    return DataProcessor::GetTasks();
}

QList<QueueModel> DataAccessor::GetQueues()
{
    return DataProcessor::GetQueues();
}

QList<MarkerModel> DataAccessor::GetMarkers()
{
    return DataProcessor::GetMarkers();
}

QList<UserAgentModel> DataAccessor::GetUserAgents()
{
    return DataProcessor::GetUserAgents();
}

QList<HandlerModel> DataAccessor::GetHandlers()
{
    return DataProcessor::GetHandlers();
}

qreal DataAccessor::GetXAxisLenght()
{

    return GetMaxInList(GetTasks(),GetQueues(),GetUserAgents(),GetHandlers());

}

qreal DataAccessor::GetYAxisLenght()
{
    qreal value = 0;

    value += 100;
    value += GetTasks().count() * 125;

    value += 100;
    value += GetQueues().count() * 125;

    value += 100;
    value += GetUserAgents().count() * 125;

    value += 100;
    value += GetHandlers().count() * 125;

    return value;
}


