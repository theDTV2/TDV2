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

    void SetName (QString new_name);
    void GetTime(quint64 to_set);

    QString GetName();
    quint64 GetTime();

    void ClearList();

    void AddToList(quint64 start_time, quint64 end_time);
    void AddToList(quint64 start_time, quint64 end_time, quint16 height);

    QList<DataPair>* GetList();

    void SetCreationTime(quint64 creation_time);
    quint64 GetCreationTime();

    void SetTaskId(quint64 taskId);
    quint16 GetTaskId();

private:
    QString name_;
    quint16 task_id_;
    QList<DataPair> entries_;
    quint64 creation_time_;

};

#endif // VIEWELEMENT_H
