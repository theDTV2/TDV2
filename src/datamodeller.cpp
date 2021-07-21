#include "datamodeller.h"




void DataModeller::SetDataToProcess(QStringList string)
{
    raw_data_ = string;
}

void DataModeller::ProcessRawData()
{
    bool done = false;

    while(!done)
    {
        ParseEntry();

        if (raw_data_.empty())
            done = true;

    }
//Maybe do some post stuff here
}
void DataModeller::ParseEntry()
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


    //If we arrive here, we have an disallowed input

}

void DataModeller::GetNextLine()
{
    current_string_ = raw_data_.takeFirst();
}


//Task Create : 			CRE 0 <task_number> <tick>
//                          NAM 0 <task_number> <task_name>
void DataModeller::CreateNewTask()
{

    quint16 task_id = GetVariableAtPositionInCurrentEntry<quint16>(2);
    quint64 tick = ParseTick(GetVariableAtPositionInCurrentEntry<quint32>(3));
    GetNextLine();
    QString task_name = GetVariableAtPositionInCurrentEntry<QString>(3);

    TaskModel new_task = TaskModel(task_name,task_id,tick);

    task_list_.append(new_task);
}

//Queue Create:             CRE 3 <queue_number> <tick>
void DataModeller::CreateNewQueue()
{
     quint16 queue_id = GetVariableAtPositionInCurrentEntry<quint64>(2);
     quint64 tick = ParseTick(GetVariableAtPositionInCurrentEntry<quint32>(3));

     QueueModel new_queue = QueueModel(queue_id,tick);

     queue_list_.append(new_queue);
}

//Queue Registry Add:       NAM 3 <queue_number> <queue_name>
void DataModeller::AddQueueReg()
{
    quint16 queue_id = GetVariableAtPositionInCurrentEntry<quint16>(2);
    QString queue_name = GetVariableAtPositionInCurrentEntry<QString>(3);

    QueueModel* element = SearchHelper::FindInList(&queue_list_,queue_id);
    element->SetName(queue_name);
}

//Handler Create:           NAM 1 <irq> <name>
void DataModeller::CreateNewHandler()
{
    quint16 irq = GetVariableAtPositionInCurrentEntry<quint16>(2);
    QString handler_name = GetVariableAtPositionInCurrentEntry<QString>(3);

    HandlerModel new_handler = HandlerModel(handler_name,irq);
    handler_list_.append(new_handler);

}

//User Agent Create:        NAM 8 <id> <name>
void DataModeller::CreateNewUserAgent()
{
    quint16 id = GetVariableAtPositionInCurrentEntry<quint16>(2);
    QString name = GetVariableAtPositionInCurrentEntry<QString>(3);

    UserAgentModel new_agent = UserAgentModel(name,id);
    userAgent_list_.append(new_agent);
}

//Task Enter:          STA 0 <task_number> <tick>
void DataModeller::AddTaskEnter()
{
    quint16 task_id = GetVariableAtPositionInCurrentEntry<quint16>(2);
    quint64 tick = ParseTick(GetVariableAtPositionInCurrentEntry<quint32>(3));

    TaskModel* element =  SearchHelper::FindInList(&task_list_,task_id);
    element->AddStart(tick);

}

//Task Stop:           STO 0 <task_number> <tick>
void DataModeller::AddTaskStop()
{
    quint16 task_id = GetVariableAtPositionInCurrentEntry<quint16>(2);
    quint64 tick = ParseTick(GetVariableAtPositionInCurrentEntry<quint32>(3));

    TaskModel* element =  SearchHelper::FindInList(&task_list_,task_id);
    element->AddStop(tick);
}

//Queue Send (+ISR):   STA 3 <queue_id> <tick> <messages_amount (always 1)>
void DataModeller::AddQueueSend()
{
    quint16 queue_id = GetVariableAtPositionInCurrentEntry<quint16>(2);
    quint64 tick = ParseTick(GetVariableAtPositionInCurrentEntry<quint32>(3));

    QueueModel* element =  SearchHelper::FindInList(&queue_list_,queue_id);
    element->AddQueueHeight(tick);
}

//Queue Receive(+ISR):	STO 3 <queue_id> <tick> <messages_amount (always 1)>
void DataModeller::AddQueueReceive()
{
    quint16 queue_id = GetVariableAtPositionInCurrentEntry<quint16>(2);
    quint64 tick = ParseTick(GetVariableAtPositionInCurrentEntry<quint32>(3));

    QueueModel* element =  SearchHelper::FindInList(&queue_list_,queue_id);
    element->RemoveQueueHeight(tick);
}

//Marker Create: 		NAM 7 <flag_id> <name>
void DataModeller::CreateMarker()
{
    quint16 flag_id = GetVariableAtPositionInCurrentEntry<quint16>(2);
    QString name = GetVariableAtPositionInCurrentEntry<QString>(3);

    MarkerModel* element = new MarkerModel(name, flag_id);
    marker_list_.append(*element);

    //Needed for DSC 0 0, 1 1 and 3 3
    last_marker_ = element;
}

//Marker Occurence:	OCC 7 <flag_number> <tick>
void DataModeller::AddMarkerOccurance()
{
    quint16 flag_id = GetVariableAtPositionInCurrentEntry<quint16>(2);
    quint64 tick = ParseTick(GetVariableAtPositionInCurrentEntry<quint32>(3));

    MarkerModel* element =  SearchHelper::FindInList(&marker_list_,flag_id);
    element->AddPosition(tick);
}

//Marker AddString			DSC 0 0 <string> //THIS REFERENCES THE LAST MARKER, THAT OCCURED
//Marker AddNumber	 		DSC 1 1 <number> //THIS REFERENCES THE LAST MARKER, THAT OCCURED
//Marker AddColor      		DSC 3 3 <color> //THIS REFERENCES THE LAST MARKER, THAT OCCURED
void DataModeller::AddMarkerProperty()
{
    //No need to check both values (for now)
    quint16 ident = GetVariableAtPositionInCurrentEntry<quint16>(1);
    QString var;
    qint32 num;

    switch (ident) {
    case 0:
        var = GetVariableAtPositionInCurrentEntry<quint16>(3);

        last_marker_->AddString(var);
        break;
    case 1:
        num = GetVariableAtPositionInCurrentEntry<qint32>(3);
        last_marker_->SetNumber(num);
        break;

    case 2:
        num = GetVariableAtPositionInCurrentEntry<qint32>(3);
        last_marker_->SetColor(QColor(num));
        break;

    }
}

//Handler Enter: 		STA 1 <irq> <tick>
void DataModeller::AddHandlerEnter()
{
    quint16 irq = GetVariableAtPositionInCurrentEntry<quint16>(2);
    quint64 tick = ParseTick(GetVariableAtPositionInCurrentEntry<quint32>(3));

    HandlerModel* element =  SearchHelper::FindInList(&handler_list_,irq);
    element->AddEnter(tick);

}

//Handler Exit:		STO 1 <irq> <tick>
void DataModeller::AddHandlerExit()
{
    quint16 irq = GetVariableAtPositionInCurrentEntry<quint16>(2);
    quint64 tick = ParseTick(GetVariableAtPositionInCurrentEntry<quint32>(3));

    HandlerModel* element =  SearchHelper::FindInList(&handler_list_,irq);
    element->AddExit(tick);
}

//User Agent Begin:  	STA 8 <id> <tick>
void DataModeller::AddUserAgentEnter()
{
    quint16 id = GetVariableAtPositionInCurrentEntry<quint16>(2);
    quint64 tick = ParseTick(GetVariableAtPositionInCurrentEntry<quint32>(3));

    UserAgentModel* element =  SearchHelper::FindInList(&userAgent_list_,id);
    element->AddEnter(tick);
}

//User Agent End:   	STO 8 <id> <tick>
void DataModeller::AddUserAgentExit()
{
    quint16 id = GetVariableAtPositionInCurrentEntry<quint16>(2);
    quint64 tick = ParseTick(GetVariableAtPositionInCurrentEntry<quint32>(3));

    UserAgentModel* element =  SearchHelper::FindInList(&userAgent_list_,id);
    element->AddExit(tick);
}


/*
 * Call getVariableAtPositionInGivenEntry() with our current entry
 *
 */
template<class T>
T DataModeller::GetVariableAtPositionInCurrentEntry(quint8 position)
{
    return EntryHelper::GetVariableAtPositionInGivenEntry<T>(current_string_,position);
}


quint64 DataModeller::ParseTick(quint64 tick)
{
    //If we already had a overflow, return the adjusted value here
    if (tick_overflow_)
        return numeric_limits<quint32>::max()+ tick;

    //Detect overflow here
    if (tick < last_tick_read_)
    {
        tick_overflow_ = true;
        return numeric_limits<quint32>::max()+ tick;
    }

    //If we arrive here, everything is fine, and we just return the normal tick
    last_tick_read_ = tick;
    return tick;
}
