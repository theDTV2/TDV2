#include "useragentmodel.h"

UserAgentModel::UserAgentModel(QString name)
    :ViewElement(name), m_lastTime(0)
{
}


void UserAgentModel::addEnter(quint64 time)
{
    m_lastTime = time;
    return;
}

void UserAgentModel::addExit(quint64 time)
{
    if (m_lastTime == 0)
        return;

    m_lastTime = 0;
    return;
}
