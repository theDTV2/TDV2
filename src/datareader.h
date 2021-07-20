#ifndef DATAREADER_H
#define DATAREADER_H
#include <QFile>
#include <QDir>
#include <QString>
#include <QList>
#include <QString>

#include "datamodeller.h"


class DataReader
{
public:

static void ReadFile();


private:
inline static QDir path_of_file_;
inline static QList<QString> read_data_;
inline static QFile file_;
};

#endif // DATAREADER_H
