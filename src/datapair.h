#ifndef DATAPAIR_H
#define DATAPAIR_H
#include <QtGlobal>

class DataPair
{
public:
DataPair(quint64 startTime, quint64 endTime, quint16 height = -1);

void SetStartTime(quint64 start_time);
void SetEndTime(quint64 end_time);
void SetHeight(quint16 new_height);

quint64 GetStartTime();
quint64 GetEndTime();
quint64 GetLenght();
void    AddHeight();
void    LowerHeight();


private:
quint64 start_time_;
quint64 end_time_;
quint64 lenght_;
quint16 height_;

};

#endif // DATAPAIR_H
