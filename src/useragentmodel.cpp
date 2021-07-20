#include "useragentmodel.h"

UserAgentModel::UserAgentModel(QString name)
    :ViewElement(name)
{
}

UserAgentModel::UserAgentModel(QString name, quint16 id)
    :ViewElement(name, id)
{
}


void UserAgentModel::AddEnter(quint64 time)
{
    last_time_ = time;
    return;
}

void UserAgentModel::AddExit(quint64 time)
{
    if (last_time_ == 0)
        return;

    AddToList(last_time_,time);
    return;
}
