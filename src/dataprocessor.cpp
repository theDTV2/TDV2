#include "dataprocessor.h"



/**
 * @brief Sets the data to be processed
 * @param string data to be processed
 */
void DataProcessor::SetDataToProcess(const QStringList& string)
{
    raw_data_ = string;
}

/**
 * @brief reads the data set in SetDataToProcess line by line
 * @param name of the file, that was read from
 */
void DataProcessor::ProcessRawData(const QString& file_name)
{  
    file_name_ = file_name;

    bool done = false;

    //If we have no raw data, we cancel here
    if (raw_data_.empty())
        done = true;;


    while(!done)
    {
        ParseEntry();

        if (raw_data_.empty())
            done = true;

    }

    //clean up
    Finalize();
}

/**
 * @brief getter
 * @return task list
 */
QList<TaskModel> DataProcessor::GetTasks()
{
    return task_list_;
}

/**
 * @brief getter
 * @return queue list
 */
QList<QueueModel> DataProcessor::GetQueues()
{
    return queue_list_;
}

/**
 * @brief getter
 * @return marker list
 */
QList<MarkerModel> DataProcessor::GetMarkers()
{
    return marker_list_;
}

/**
 * @brief getter
 * @return user agent list
 */
QList<UserAgentModel> DataProcessor::GetUserAgents()
{
    return user_agent_list_;
}

/**
 * @brief getter
 * @return handler list
 */
QList<HandlerModel> DataProcessor::GetHandlers()
{
    return handler_list_;
}


/**
 * @brief get a new line from the raw_data, and process it according the .tdi documentation
 */
void DataProcessor::ParseEntry()
{

    //load the next line to process to current_string_
    GetNextLine();

    amount_of_lines_parsed_successfully_++;

    //Handle new entry
    if (current_string_.startsWith("CRE 0"))
        return CreateNewTask();

    if (current_string_.startsWith("CRE 3"))
        return CreateNewQueue();

    if (current_string_.startsWith("NAM 3"))
        return AddQueueReg();

    if (current_string_.startsWith("CRE 3"))
        return CreateNewQueue();

    if (current_string_.startsWith("NAM 1"))
        return CreateNewHandler();

    if (current_string_.startsWith("NAM 8"))
        return CreateNewUserAgent();

    if (current_string_.startsWith("STA 0"))
        return AddTaskEnter();

    if (current_string_.startsWith("STO 0"))
        return AddTaskStop();

    if (current_string_.startsWith("STA 3"))
        return AddQueueSend();

    if (current_string_.startsWith("STO 3"))
        return AddQueueReceive();

    if (current_string_.startsWith("NAM 7"))
        return CreateMarker();

    if (current_string_.startsWith("OCC 7"))
        return AddMarkerOccurance();

    if (current_string_.startsWith("DSC"))
        return AddMarkerProperty();

    if (current_string_.startsWith("STA 1"))
        return AddHandlerEnter();

    if (current_string_.startsWith("STO 1"))
        return AddHandlerExit();

    if (current_string_.startsWith("STA 8"))
        return AddUserAgentEnter();

    if (current_string_.startsWith("STO 8"))
        return AddUserAgentExit();

    if (current_string_.startsWith("SPEED"))
        return LoadSpeed();

    if (current_string_.startsWith("MEMSPEED"))
        return LoadMemorySpeed();

    if (current_string_.startsWith("TIME"))
        return LoadTime();

    amount_of_lines_parsed_successfully_--;
}

/**
 * @brief Move new entry to current string
 */
void DataProcessor::GetNextLine()
{
    current_string_ = raw_data_.takeFirst();
}

/**
 * @brief Create new task using the given data
 * NAM 0 <task_number> <task_name>
 * CRE 0 <task_number> <tick>
 */
void DataProcessor::CreateNewTask()
{

    quint16 task_id = GetVariableAtPositionInCurrentEntry<quint16>(2);
    quint64 tick = ParseTick(GetVariableAtPositionInCurrentEntry<quint32>(3));
    GetNextLine();
    QString task_name = GetVariableAtPositionInCurrentEntry<QString>(3);

    TaskModel new_task = TaskModel(task_name,task_id,tick);

    task_list_.append(new_task);
}

/**
 * @brief Create new queue task using the given data
 * CRE 3 <queue_number> <tick>
 */
void DataProcessor::CreateNewQueue()
{
    quint16 queue_id = GetVariableAtPositionInCurrentEntry<quint64>(2);
    quint64 tick = ParseTick(GetVariableAtPositionInCurrentEntry<quint32>(3));

    QueueModel new_queue = QueueModel(queue_id,tick);

    queue_list_.append(new_queue);
}

/**
 * @brief Set queue name
 * NAM 3 <queue_number> <queue_name>
 */
void DataProcessor::AddQueueReg()
{
    quint16 queue_id = GetVariableAtPositionInCurrentEntry<quint16>(2);
    QString queue_name = GetVariableAtPositionInCurrentEntry<QString>(3);

    QueueModel* element = SearchHelper::FindInList(&queue_list_,queue_id);
    element->SetName(queue_name);
}


/**
 * @brief Create new handler task using the given data
 * Handler Create:           NAM 1 <irq> <name>
 */
void DataProcessor::CreateNewHandler()
{
    quint16 irq = GetVariableAtPositionInCurrentEntry<quint16>(2);
    QString handler_name = GetVariableAtPositionInCurrentEntry<QString>(3);

    HandlerModel new_handler = HandlerModel(handler_name,irq);
    handler_list_.append(new_handler);

}

/**
* @brief Create new user agent task using the given data
* NAM 8 <id> <name>
*/
void DataProcessor::CreateNewUserAgent()
{
    quint16 id = GetVariableAtPositionInCurrentEntry<quint16>(2);
    QString name = GetVariableAtPositionInCurrentEntry<QString>(3);

    UserAgentModel new_agent = UserAgentModel(name,id);
    user_agent_list_.append(new_agent);
}

/**
* @brief Add new task start
* STA 0 <task_number> <tick>
*/
void DataProcessor::AddTaskEnter()
{
    quint16 task_id = GetVariableAtPositionInCurrentEntry<quint16>(2);
    quint64 tick = ParseTick(GetVariableAtPositionInCurrentEntry<quint32>(3));

    TaskModel* element =  SearchHelper::FindInList(&task_list_,task_id);
    element->AddStart(tick);

}

/**
* @brief Add new task stop
* STO 0 <task_number> <tick>
*/
void DataProcessor::AddTaskStop()
{
    quint16 task_id = GetVariableAtPositionInCurrentEntry<quint16>(2);
    quint64 tick = ParseTick(GetVariableAtPositionInCurrentEntry<quint32>(3));

    TaskModel* element =  SearchHelper::FindInList(&task_list_,task_id);
    element->AddStop(tick);
}

/**
 * @brief Add Queue entry
 * STA 3 <queue_id> <tick> <messages_amount (always 1)>
 */
void DataProcessor::AddQueueSend()
{
    quint16 queue_id = GetVariableAtPositionInCurrentEntry<quint16>(2);
    quint64 tick = ParseTick(GetVariableAtPositionInCurrentEntry<quint32>(3));

    QueueModel* element =  SearchHelper::FindInList(&queue_list_,queue_id);
    element->AddQueueHeight(tick);
}

/**
 * Lower Queue entry
 * STO 3 <queue_id> <tick> <messages_amount (always 1)>
 */
void DataProcessor::AddQueueReceive()
{
    quint16 queue_id = GetVariableAtPositionInCurrentEntry<quint16>(2);
    quint64 tick = ParseTick(GetVariableAtPositionInCurrentEntry<quint32>(3));

    QueueModel* element =  SearchHelper::FindInList(&queue_list_,queue_id);
    element->RemoveQueueHeight(tick);
}

/**
 * @brief Create new marker with given values
 * NAM 7 <flag_id> <name>
 */
void DataProcessor::CreateMarker()
{
    quint16 flag_id = GetVariableAtPositionInCurrentEntry<quint16>(2);
    QString name = GetVariableAtPositionInCurrentEntry<QString>(3);

    MarkerModel* element = new MarkerModel(name, flag_id);
    marker_list_.append(*element);

    //Needed for DSC 0 0, 1 1 and 3 3
    last_marker_ = element;
}

/**
 * @brief Add marker occurence
 * OCC 7 <flag_number> <tick>
 */
void DataProcessor::AddMarkerOccurance()
{
    quint16 flag_id = GetVariableAtPositionInCurrentEntry<quint16>(2);
    quint64 tick = ParseTick(GetVariableAtPositionInCurrentEntry<quint32>(3));

    last_marker_ =  SearchHelper::FindInList(&marker_list_,flag_id);
    last_marker_->AddEntry(tick);

}

/**
 * @brief Add marker property. THIS REFERENCES THE LAST MARKER, THAT OCCURED
 * Marker AddString			DSC 0 0 <string>
 * Marker AddNumber	 		DSC 1 1 <number>
 * Marker AddColor      	DSC 3 3 <color>
 */
void DataProcessor::AddMarkerProperty()
{
    //No need to check both values (for now)
    quint16 ident = GetVariableAtPositionInCurrentEntry<quint16>(1);
    QString var;
    qint32 num;

    switch (ident) {
    case 0:
        var = GetVariableAtPositionInCurrentEntry<QString>(3);

        last_marker_->AddStringToLast(var);
        break;
    case 1:
        num = GetVariableAtPositionInCurrentEntry<qint32>(3);
        last_marker_->SetNumberOfLast(num);
        break;

    case 2:
        num = GetVariableAtPositionInCurrentEntry<qint32>(3);
        last_marker_->SetColorOfLast(QColor(num));
        break;

    }
}

/**
 * @brief Add handler entry
 * Enter: 		STA 1 <irq> <tick>
 */
void DataProcessor::AddHandlerEnter()
{
    quint16 irq = GetVariableAtPositionInCurrentEntry<quint16>(2);
    quint64 tick = ParseTick(GetVariableAtPositionInCurrentEntry<quint32>(3));

    HandlerModel* element =  SearchHelper::FindInList(&handler_list_,irq);
    element->AddEnter(tick);

}

/**
 * @brief Add handler stop
 * Enter: 		STO 1 <irq> <tick>
 */
void DataProcessor::AddHandlerExit()
{
    quint16 irq = GetVariableAtPositionInCurrentEntry<quint16>(2);
    quint64 tick = ParseTick(GetVariableAtPositionInCurrentEntry<quint32>(3));

    HandlerModel* element =  SearchHelper::FindInList(&handler_list_,irq);
    element->AddExit(tick);
}

/**
 * @brief Add User agent start
 * STA 8 <id> <tick>
 */
void DataProcessor::AddUserAgentEnter()
{
    quint16 id = GetVariableAtPositionInCurrentEntry<quint16>(2);
    quint64 tick = ParseTick(GetVariableAtPositionInCurrentEntry<quint32>(3));

    UserAgentModel* element =  SearchHelper::FindInList(&user_agent_list_,id);
    element->AddEnter(tick);
}

/**
 * @brief Add User agent stop
 * STO 8 <id> <tick>
 */
void DataProcessor::AddUserAgentExit()
{
    quint16 id = GetVariableAtPositionInCurrentEntry<quint16>(2);
    quint64 tick = ParseTick(GetVariableAtPositionInCurrentEntry<quint32>(3));

    UserAgentModel* element =  SearchHelper::FindInList(&user_agent_list_,id);
    element->AddExit(tick);
}

/**
 * @brief Loads speed
 */
void DataProcessor::LoadSpeed()
{
    speed_ = GetVariableAtPositionInCurrentEntry<quint32>(1);

}

/**
 * @brief Loads Memory speed
 */
void DataProcessor::LoadMemorySpeed()
{
    memory_speed_ = GetVariableAtPositionInCurrentEntry<quint32>(1);
}

/**
 * @brief Load Time
 */
void DataProcessor::LoadTime()
{
    time_= GetVariableAtPositionInCurrentEntry<quint32>(1);
}

/**
 * @brief Takes the processed data, and creates a new DataModel using it.
 * It is then passed to the DataFactory to be added to the model list
 */
void DataProcessor::Finalize()
{

    DataModel* new_model = new DataModel("File: " + file_name_,task_list_,
                                    queue_list_,
                                    marker_list_,
                                    user_agent_list_,
                                    handler_list_,
                                    speed_,
                                    memory_speed_,
                                    time_,
                                    amount_of_lines_parsed_successfully_);

    DataFactory::AddDataModel("File: " + file_name_, new_model, true);


    ClearData();

}


/*
 * Call getVariableAtPositionInGivenEntry() with our current entry
 *
 */
template<class T>
T DataProcessor::GetVariableAtPositionInCurrentEntry(quint8 position)
{
    return EntryHelper::GetVariableAtPositionInGivenEntry<T>(current_string_,position);
}

/**
 * @brief In case a buffer overflow occurs in the .tdi file, we fix it by adding the quint32 value
 * @param tick tick to set
 * @return new tick value
 */
quint64 DataProcessor::ParseTick(quint64 tick)
{
    //If we already had a overflow, return the adjusted value here
    if (tick_overflow_)
        return std::numeric_limits<quint32>::max()+ tick;

    //Detect overflow here
    if (tick < last_tick_read_)
    {
        tick_overflow_ = true;
        return std::numeric_limits<quint32>::max()+ tick;
    }

    //If we arrive here, everything is fine, and we just return the normal tick
    last_tick_read_ = tick;
    return tick;
}

/**
 * @brief Resets all used variables, so that another file can be read
 */
void DataProcessor::ClearData()
{
    task_list_.clear();
    queue_list_.clear();
    marker_list_.clear();
    user_agent_list_.clear();
    handler_list_.clear();

    speed_ = 0;
    memory_speed_ = 0;
    time_ = 0;
    last_tick_read_ = 0;
    tick_overflow_ = 0;
    raw_data_ = QStringList();
    last_marker_ = nullptr;

}

quint32 DataProcessor::GetAmountOfLinesParsed()
{
    return amount_of_lines_parsed_successfully_;
}

