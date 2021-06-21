#ifndef DATAPAIR_H
#define DATAPAIR_H
#include <QtGlobal>

class DataPair
{
public:
DataPair(quint64 startTime, quint64 endTime);
void setStartTime(quint64 startTime);
void setEndTime(quint64 endtime);
void setHeight(quint16 newHeight);

quint64 getStartTime();
quint64 getEndTime();
quint64 getLenght();
void    addHeight();
void    lowerHeight();


private:
quint64 m_startTime;
quint64 m_endTime;
quint64 m_lenght;
quint16 m_height;

};

#endif // DATAPAIR_H
