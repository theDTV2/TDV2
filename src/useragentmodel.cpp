#include "useragentmodel.h"

/**
 * @brief Constructor
 * @param name name to use
 */
UserAgentModel::UserAgentModel(const QString& name)
    :ViewElement(name), last_time_(0)
{
}

/**
 * @brief Constructor
 * @param name name to use
 * @param id id to use
 */
UserAgentModel::UserAgentModel(const QString& name, quint16 id)
    :ViewElement(name, id), last_time_(0)
{
}

/**
 * @brief Add enter
 * @param time start time to set
 */
void UserAgentModel::AddEnter(quint64 time)
{
    last_time_ = time;
    return;
}

/**
 * @brief Add exit
 * @param time start time to set
 */
void UserAgentModel::AddExit(quint64 time)
{
    if (last_time_ == 0)
        return;

    AddToList(last_time_,time);
    return;
}
