#include "dataprocessor.h"




void DataProcessor::SetDataToProcess(const QStringList& string)
{
    raw_data_ = string;
}

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

QList<TaskModel> DataProcessor::GetTasks()
{
    return task_list_;
}

QList<QueueModel> DataProcessor::GetQueues()
{
    return queue_list_;
}

QList<MarkerModel> DataProcessor::GetMarkers()
{
    return marker_list_;
}

QList<UserAgentModel> DataProcessor::GetUserAgents()
{
    return user_agent_list_;
}

QList<HandlerModel> DataProcessor::GetHandlers()
{
    return handler_list_;
}



void DataProcessor::ParseEntry()
{

    GetNextLine();


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



}

void DataProcessor::GetNextLine()
{
    current_string_ = raw_data_.takeFirst();
}


//Task Create : 			CRE 0 <task_number> <tick>
//                          NAM 0 <task_number> <task_name>
void DataProcessor::CreateNewTask()
{

    quint16 task_id = GetVariableAtPositionInCurrentEntry<quint16>(2);
    quint64 tick = ParseTick(GetVariableAtPositionInCurrentEntry<quint32>(3));
    GetNextLine();
    QString task_name = GetVariableAtPositionInCurrentEntry<QString>(3);

    TaskModel new_task = TaskModel(task_name,task_id,tick);

    task_list_.append(new_task);
}

//Queue Create:             CRE 3 <queue_number> <tick>
void DataProcessor::CreateNewQueue()
{
    quint16 queue_id = GetVariableAtPositionInCurrentEntry<quint64>(2);
    quint64 tick = ParseTick(GetVariableAtPositionInCurrentEntry<quint32>(3));

    QueueModel new_queue = QueueModel(queue_id,tick);

    queue_list_.append(new_queue);
}

//Queue Registry Add:       NAM 3 <queue_number> <queue_name>
void DataProcessor::AddQueueReg()
{
    quint16 queue_id = GetVariableAtPositionInCurrentEntry<quint16>(2);
    QString queue_name = GetVariableAtPositionInCurrentEntry<QString>(3);

    QueueModel* element = SearchHelper::FindInList(&queue_list_,queue_id);
    element->SetName(queue_name);
}

//Handler Create:           NAM 1 <irq> <name>
void DataProcessor::CreateNewHandler()
{
    quint16 irq = GetVariableAtPositionInCurrentEntry<quint16>(2);
    QString handler_name = GetVariableAtPositionInCurrentEntry<QString>(3);

    HandlerModel new_handler = HandlerModel(handler_name,irq);
    handler_list_.append(new_handler);

}

//User Agent Create:        NAM 8 <id> <name>
void DataProcessor::CreateNewUserAgent()
{
    quint16 id = GetVariableAtPositionInCurrentEntry<quint16>(2);
    QString name = GetVariableAtPositionInCurrentEntry<QString>(3);

    UserAgentModel new_agent = UserAgentModel(name,id);
    user_agent_list_.append(new_agent);
}

//Task Enter:          STA 0 <task_number> <tick>
void DataProcessor::AddTaskEnter()
{
    quint16 task_id = GetVariableAtPositionInCurrentEntry<quint16>(2);
    quint64 tick = ParseTick(GetVariableAtPositionInCurrentEntry<quint32>(3));

    TaskModel* element =  SearchHelper::FindInList(&task_list_,task_id);
    element->AddStart(tick);

}

//Task Stop:           STO 0 <task_number> <tick>
void DataProcessor::AddTaskStop()
{
    quint16 task_id = GetVariableAtPositionInCurrentEntry<quint16>(2);
    quint64 tick = ParseTick(GetVariableAtPositionInCurrentEntry<quint32>(3));

    TaskModel* element =  SearchHelper::FindInList(&task_list_,task_id);
    element->AddStop(tick);
}

//Queue Send (+ISR):   STA 3 <queue_id> <tick> <messages_amount (always 1)>
void DataProcessor::AddQueueSend()
{
    quint16 queue_id = GetVariableAtPositionInCurrentEntry<quint16>(2);
    quint64 tick = ParseTick(GetVariableAtPositionInCurrentEntry<quint32>(3));

    QueueModel* element =  SearchHelper::FindInList(&queue_list_,queue_id);
    element->AddQueueHeight(tick);
}

//Queue Receive(+ISR):	STO 3 <queue_id> <tick> <messages_amount (always 1)>
void DataProcessor::AddQueueReceive()
{
    quint16 queue_id = GetVariableAtPositionInCurrentEntry<quint16>(2);
    quint64 tick = ParseTick(GetVariableAtPositionInCurrentEntry<quint32>(3));

    QueueModel* element =  SearchHelper::FindInList(&queue_list_,queue_id);
    element->RemoveQueueHeight(tick);
}

//Marker Create: 		NAM 7 <flag_id> <name>
void DataProcessor::CreateMarker()
{
    quint16 flag_id = GetVariableAtPositionInCurrentEntry<quint16>(2);
    QString name = GetVariableAtPositionInCurrentEntry<QString>(3);

    MarkerModel* element = new MarkerModel(name, flag_id);
    marker_list_.append(*element);

    //Needed for DSC 0 0, 1 1 and 3 3
    last_marker_ = element;
}

//Marker Occurence:	OCC 7 <flag_number> <tick>
void DataProcessor::AddMarkerOccurance()
{
    quint16 flag_id = GetVariableAtPositionInCurrentEntry<quint16>(2);
    quint64 tick = ParseTick(GetVariableAtPositionInCurrentEntry<quint32>(3));

    last_marker_ =  SearchHelper::FindInList(&marker_list_,flag_id);
    last_marker_->AddEntry(tick);

}

//Marker AddString			DSC 0 0 <string> //THIS REFERENCES THE LAST MARKER, THAT OCCURED
//Marker AddNumber	 		DSC 1 1 <number> //THIS REFERENCES THE LAST MARKER, THAT OCCURED
//Marker AddColor      		DSC 3 3 <color> //THIS REFERENCES THE LAST MARKER, THAT OCCURED
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

//Handler Enter: 		STA 1 <irq> <tick>
void DataProcessor::AddHandlerEnter()
{
    quint16 irq = GetVariableAtPositionInCurrentEntry<quint16>(2);
    quint64 tick = ParseTick(GetVariableAtPositionInCurrentEntry<quint32>(3));

    HandlerModel* element =  SearchHelper::FindInList(&handler_list_,irq);
    element->AddEnter(tick);

}

//Handler Exit:		STO 1 <irq> <tick>
void DataProcessor::AddHandlerExit()
{
    quint16 irq = GetVariableAtPositionInCurrentEntry<quint16>(2);
    quint64 tick = ParseTick(GetVariableAtPositionInCurrentEntry<quint32>(3));

    HandlerModel* element =  SearchHelper::FindInList(&handler_list_,irq);
    element->AddExit(tick);
}

//User Agent Begin:  	STA 8 <id> <tick>
void DataProcessor::AddUserAgentEnter()
{
    quint16 id = GetVariableAtPositionInCurrentEntry<quint16>(2);
    quint64 tick = ParseTick(GetVariableAtPositionInCurrentEntry<quint32>(3));

    UserAgentModel* element =  SearchHelper::FindInList(&user_agent_list_,id);
    element->AddEnter(tick);
}

//User Agent End:   	STO 8 <id> <tick>
void DataProcessor::AddUserAgentExit()
{
    quint16 id = GetVariableAtPositionInCurrentEntry<quint16>(2);
    quint64 tick = ParseTick(GetVariableAtPositionInCurrentEntry<quint32>(3));

    UserAgentModel* element =  SearchHelper::FindInList(&user_agent_list_,id);
    element->AddExit(tick);
}

void DataProcessor::LoadSpeed()
{
    speed_ = GetVariableAtPositionInCurrentEntry<quint32>(1);

}

void DataProcessor::LoadMemorySpeed()
{
    memory_speed_ = GetVariableAtPositionInCurrentEntry<quint32>(1);
}

void DataProcessor::LoadTime()
{
    time_= GetVariableAtPositionInCurrentEntry<quint32>(1);
}

void DataProcessor::Finalize()
{

    DataModel* new_model = new DataModel("File: " + file_name_,task_list_,
                                    queue_list_,
                                    marker_list_,
                                    user_agent_list_,
                                    handler_list_,
                                    speed_,
                                    memory_speed_,
                                    time_);

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
