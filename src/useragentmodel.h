#ifndef USERAGENTMODEL_H
#define USERAGENTMODEL_H
#include <QtGlobal>
#include <QString>
#include <QList>
#include <QSharedPointer>


#include "viewelement.h"


class UserAgentModel : public ViewElement
{
public:
    UserAgentModel(QString name);
    void addEnter(quint64 time);
    void addExit(quint64 time);


private:
    quint64 m_lastTime;
};



#endif // USERAGENTMODEL_H
