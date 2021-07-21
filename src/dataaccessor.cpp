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
