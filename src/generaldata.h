#ifndef GENERALDATA_H
#define GENERALDATA_H
#include <QtGlobal>


class GeneralData
{
public:
    static void SetSpeed(quint64 value);
    static quint64 GetSpeed();
    static void SetMemorySpeed(quint64 value);
    static quint64 GetMemorySpeed();
    static void SetTime(quint64 value);
    static quint64 GetTime();

private:
    inline static quint64 speed_ = 0;
    inline static quint64 memory_speed_ = 0;
    inline static quint64 time_ = 0;

};



#endif // GENERALDATA_H
