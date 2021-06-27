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

    void setName (QString newName);
    void setTime(quint64 toSet);

    QString getName();
    quint64 getTime();

    void clearList();

    void addToList(quint64 startTime, quint64 endTime);
    void addToList(quint64 startTime, quint64 endTime, quint16 height);

    QList<DataPair>* getList();


private:
    QString m_name;
    QList<DataPair> m_entries;

};

#endif // VIEWELEMENT_H
