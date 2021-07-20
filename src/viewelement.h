#ifndef VIEWELEMENT_H
#define VIEWELEMENT_H
#include <QtGlobal>
#include <QString>
#include <QList>
#include <QSharedPointer>

#include "datapair.h"



using namespace std;
class ViewElement
{
public:
    ViewElement(QString name);
    ViewElement(quint16 task_id, quint64 creation_time);
    ViewElement(QString name, quint16 task_id, quint64 creation_time);

    void SetName (QString new_name);


    const QString GetName();

    void ClearList();

    void AddToList(quint64 start_time, quint64 end_time);
    void AddToList(quint64 start_time, quint64 end_time, quint16 height);

    QList<DataPair>* GetList();

    void SetCreationTime(quint64 creation_time);
    quint64 GetCreationTime() const;

    void SetTaskId(quint64 taskId);
    quint16 GetTaskId() const;

private:
    QString name_;
    quint16 task_id_;
    QList<DataPair> entries_;
    quint64 creation_time_;
    bool int32_overflow = false;
};

#endif // VIEWELEMENT_H
