#ifndef DATAACCESSOR_H
#define DATAACCESSOR_H
#include "datamodeller.h"

class DataAccessor
{

public:
static QList<TaskModel> GetTasks();

static QList<QueueModel> GetQueues();

static QList<MarkerModel> GetMarkers();

static QList<UserAgentModel> GetUserAgents();

static QList<HandlerModel> GetHandlers();

};

#endif // DATAACCESSOR_H
