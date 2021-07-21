#include "datareader.h"

void DataReader::ReadFile()
{
    QFile inputFile("C:\\Cloud\\HTW Bachelorarbeit\\Traces\\trace5.tdi");

    if (inputFile.open(QIODevice::ReadOnly))
    {
       QTextStream in(&inputFile);
       while (!in.atEnd())
       {
          QString line = in.readLine();
          read_data_.append(line);
       }
       inputFile.close();
    }

    DataModeller::SetDataToProcess(read_data_);
    DataModeller::ProcessRawData();
}
