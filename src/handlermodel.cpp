#include "handlermodel.h"

HandlerModel::HandlerModel(QString name)
    :ViewElement(name), m_lastTime(0)
{
}


void HandlerModel::addEnter(quint64 time)
{
    m_lastTime = time;
    return;
}

void HandlerModel::addExit(quint64 time)
{
    if (m_lastTime == 0)
        return;

    m_lastTime = 0;
    return;
}
