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
    TaskModel(QString name);

    TaskModel(QString name, quint16 task_id, quint64 creation_time);

    void SetPriority(QString new_priority);
    QString GetPrority() const;

    void AddStart(quint64 start_time);
    void AddStop(quint64 stop_time);

private:
    QString priority_;
    quint64 lenght_;

    quint64 start_time_ = 0;
};

#endif // TASKMODEL_H
