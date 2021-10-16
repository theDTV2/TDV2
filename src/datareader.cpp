#include "datareader.h"

/**
 * @brief Set the path of file to read
 * @param new_path new path to set
 */
void DataReader::SetPathOfFile(const QString& new_path)
{
    path_of_file_ = new_path;
}

/**
 * @brief Reads the file provided by SetPathOfFile, and then processes the data
 *
 */
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
    DataProcessor::ProcessRawData(file_.fileName().section("/",-1,-1));

    ClearReadData();
}

void DataReader::ClearReadData()
{
    read_data_.clear();
}


//Check each line for consistency...
//Not needed for now
bool DataReader::CheckLine()
{
    return true;
}


