#include "handlermodel.h"

/**
 * @brief HandlerModel Constructor
 * @param name name to use
 * @param irq irq value to use
 */
HandlerModel::HandlerModel(const QString& name, quint16 irq)
    :ViewElement(name, irq), last_time_(0)
{
}

/**
 * @brief Add enter
 * @param time time to set at
 */
void HandlerModel::AddEnter(quint64 time)
{
    last_time_ = time;
    return;
}

/**
 * @brief Add exit, using the previously set value
 * @param time time to set at
 */
void HandlerModel::AddExit(quint64 time)
{
    if (last_time_ == 0)
        return;

    AddToList(last_time_,time);

    last_time_ = 0;
    return;
}
