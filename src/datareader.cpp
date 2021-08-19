#include "datareader.h"


void DataReader::SetPathOfFile(QString new_path)
{
    path_of_file_ = new_path;
}

void DataReader::ReadTDVFile()
{
    QFile file_(path_of_file_);

    if (file_.open(QIODevice::ReadOnly))
    {
       QTextStream in(&file_);
       while (!in.atEnd())
       {
          QString line = in.readLine();

          read_data_.append(line);
       }
       file_.close();
    }

    DataProcessor::SetDataToProcess(read_data_);
    DataProcessor::ProcessRawData();
}


//Check each line for consistency... later maybe
bool DataReader::CheckLine()
{
    return true;
}


