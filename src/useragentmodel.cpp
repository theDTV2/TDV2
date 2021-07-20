#include "useragentmodel.h"

UserAgentModel::UserAgentModel(QString name)
    :ViewElement(name), last_time_(0)
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
