#include "dataaccessor.h"


QList<TaskModel> DataAccessor::GetTasks()
{
    return DataModeller::GetTasks();
}

QList<QueueModel> DataAccessor::GetQueues()
{
    return DataModeller::GetQueues();
}

QList<MarkerModel> DataAccessor::GetMarkers()
{
    return DataModeller::GetMarkers();
}

QList<UserAgentModel> DataAccessor::GetUserAgents()
{
    return DataModeller::GetUserAgents();
}

QList<HandlerModel> DataAccessor::GetHandlers()
{
    return DataModeller::GetHandlers();
}

qreal DataAccessor::GetXAxisLenght()
{
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
