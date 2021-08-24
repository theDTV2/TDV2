#ifndef TASKMODEL_H
#define TASKMODEL_H
#include <QtGlobal>
#include <QString>
#include <QList>
#include <QSharedPointer>

#include "viewelement.h"


class TaskModel : public ViewElement
{
public:
    TaskModel(const QString& name);

    TaskModel(const QString& name, quint16 task_id, quint64 creation_time);

    void SetPriority(const QString& new_priority);
    QString GetPrority() const;

    void AddStart(quint64 start_time);
    void AddStop(quint64 stop_time);

private:
    QString priority_;
    quint64 lenght_ = 0;

    quint64 start_time_ = 0;
};

#endif // TASKMODEL_H
