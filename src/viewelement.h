#ifndef VIEWELEMENT_H
#define VIEWELEMENT_H
#include <QtGlobal>
#include <QString>
#include <QList>
#include <QSharedPointer>

#include "datapair.h"




class ViewElement
{
public:
    ViewElement(const QString& name);
    ViewElement(const QString& name, quint16 task_id);
    ViewElement(quint16 task_id, quint64 creation_time);
    ViewElement(const QString& name, quint16 task_id, quint64 creation_time);

    void SetName (const QString& new_name);
    const QString GetName();

    void ClearList();

    void AddToList(quint64 start_time, quint64 end_time);
    void AddToList(quint64 start_time, quint64 end_time, quint16 height);

    QList<DataPair>* GetList();

    void SetCreationTime(quint64 creation_time);
    quint64 GetCreationTime() const;

    void SetElementId(quint64 taskId);
    quint16 GetElementId() const;

    quint64 GetLargestEndTime();
private:
    QString name_;
    quint16 task_id_;
    QList<DataPair> entries_;
    quint64 creation_time_;
    bool int32_overflow = false;
};

#endif // VIEWELEMENT_H
