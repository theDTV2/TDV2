#ifndef DATAREADER_H
#define DATAREADER_H
#include <QFile>
#include <QDir>
#include <QString>
#include <QList>
#include <QString>
#include <QFileDialog>

#include "dataprocessor.h"


class DataReader
{
public:
    static void SetPathOfFile(QString new_path);
    static void ReadTDVFile();


private:

    static bool CheckLine();

    inline static QString path_of_file_;
    inline static QList<QString> read_data_ = QList<QString>();
    inline static QFile file_;
};

#endif // DATAREADER_H
