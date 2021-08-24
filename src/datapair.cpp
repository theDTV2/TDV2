#include "datapair.h"

/**
 * @brief Constructor for pair of Start/Endtime. Used in construction of ViewElements
 * @param startTime startTime
 * @param endTime endTime
 * @param height height to be used for queues
 */
DataPair::DataPair(quint64 startTime, quint64 endTime, quint16 height):
    start_time_(startTime),end_time_(endTime), lenght_(endTime - startTime),height_(height)
{


}


/**
 * @brief setter
 * @param start_time time to set
 */
void DataPair::SetStartTime(quint64 start_time)
{
    start_time_ = start_time;
}

/**
 * @brief setter for the end time. Calculates lenght using the start time, if possible
 * @param end_time
 */
void DataPair::SetEndTime(quint64 end_time)
{
    end_time_ = end_time;

    //Set the lenght according to the previously set start time.
    if (start_time_ > 0)
         lenght_ = end_time - start_time_;
}

/**
* @brief setter
* @param new_height
*/
void DataPair::SetHeight(quint16 new_height)
{
    height_ = new_height;
}

/**
* @brief setter
* @param start time
*/
quint64 DataPair::GetStartTime() const
{
    return start_time_;
}

/**
 * @brief getter
 * @return  end time
 */
quint64 DataPair::GetEndTime() const
{
    return end_time_;
}

/**
 * @brief getter
 * @return  lenght
 */
quint64 DataPair::GetLenght() const
{
    return lenght_;
}

/**
 * @brief setter
 * @return height
 */
quint16 DataPair::GetHeight() const
{
    return height_;
}

/**
* @brief increases height by 1
*/
void DataPair::AddHeight()
{
    height_++;
}

/**
* @brief Lowers height by 1. Doesnt go negative
*/
void DataPair::LowerHeight()
{
    if (height_ > 0)
      --height_;
}


