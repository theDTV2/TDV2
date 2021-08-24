#include "handlermodel.h"

HandlerModel::HandlerModel(const QString& name, quint16 irq)
    :ViewElement(name, irq), last_time_(0)
{
}


void HandlerModel::AddEnter(quint64 time)
{
    last_time_ = time;
    return;
}

void HandlerModel::AddExit(quint64 time)
{
    if (last_time_ == 0)
        return;

    AddToList(last_time_,time);

    last_time_ = 0;
    return;
}
