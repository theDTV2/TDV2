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

    quint16 task_id = GetVariableAtPositionInCurrentEntry<quint64>(2);
    quint64 tick = GetVariableAtPositionInCurrentEntry<quint64>(3);
    GetNextLine();
    QString task_name = GetVariableAtPositionInCurrentEntry<QString>(3);

    TaskModel new_task = TaskModel(task_name,task_id,tick);

    task_list_.append(new_task);
}

//Queue Create:             CRE 3 <queue_number> <tick>
void DataModeller::CreateNewQueue()
{
     quint16 queue_id = GetVariableAtPositionInCurrentEntry<quint64>(2);
     quint64 tick = GetVariableAtPositionInCurrentEntry<quint64>(3);

     QueueModel new_queue = QueueModel(queue_id,tick);

     queue_list_.append(new_queue);
}

//Queue Registry Add:       NAM 3 <queue_number> <queue_name>
void DataModeller::AddQueueReg()
{

}

//Handler Create:           NAM 1 <irq> <name>
void DataModeller::CreateNewHandler()
{

}

//User Agent Create:        NAM 8 <id> <name>
void DataModeller::CreateNewUserAgent()
{

}

//Task Enter:          STA 0 <task_number> <tick>
void DataModeller::AddTaskEnter()
{

}

//Task Stop:           STO 0 <task_number> <tick>
void DataModeller::AddTaskStop()
{

}

//Queue Send (+ISR):   STA 3 <queue_number> <tick> <messages_amount (always 1)>
void DataModeller::AddQueueSend()
{

}

//Queue Receive(+ISR):	STO 3 <queue_number> <tick> <messages_amount (always 1)>
void DataModeller::AddQueueReceive()
{

}

//Marker Create: 		NAM 7 <flag_number> <name>
void DataModeller::CreateMarker()
{

}

//Marker Occurence:	OCC 7 <flag_number> <tick>
void DataModeller::AddMarkerOccurance()
{

}

//Marker AddString			DSC 0 0 <string> //THIS REFERENCES THE LAST MARKER, THAT OCCURED
//Marker AddNumber	 		DSC 1 1 <number> //THIS REFERENCES THE LAST MARKER, THAT OCCURED
//Marker AddColor      		DSC 3 3 <color> //THIS REFERENCES THE LAST MARKER, THAT OCCURED
void DataModeller::AddMarkerProperty()
{

}

//Handler Enter: 		STA 1 <irq> <tick>
void DataModeller::AddHandlerEnter()
{

}

//Handler Exit:		STO 1 <irq> <tick>
void DataModeller::AddHandlerExit()
{

}

//User Agent Begin:  	STA 8 <id> <tick>
void DataModeller::AddUserAgentEnter()
{

}

//User Agent End:   	STO 8 <id> <tick>
void DataModeller::AddUserAgentExit()
{

}

/*
 * Call getVariableAtPositionInGivenEntry() with our current entry
 *
 */
template<class T>
T DataModeller::GetVariableAtPositionInCurrentEntry(quint8 position)
{
    return GetVariableAtPositionInGivenEntry<T>(current_string_,position);
}

/*
 * Get given Variable at position (stating at 0) from given entry
 * specialized for QString
 */
template<>
QString DataModeller::GetVariableAtPositionInGivenEntry<QString>(QString entry,quint8 position)
{

    return GetStringAtPosition(entry, position);
}

/*
 * Get given Variable at position (stating at 0) from given entry
 * specialized for quint64
 */
template<>
quint64 DataModeller::GetVariableAtPositionInGivenEntry<quint64>(QString entry,quint8 position)
{

    return GetStringAtPosition(entry, position).toULongLong();

}

/*
 * Get given Variable at position (stating at 0) from given entry
 * specialized for qint64
 */
template<>
qint64 DataModeller::GetVariableAtPositionInGivenEntry<qint64>(QString entry,quint8 position)
{

    return GetStringAtPosition(entry, position).toLongLong();

}

QString DataModeller::GetStringAtPosition(QString entry,quint8 position)
{
    //Iterate through Entry until we get to the desired variable
    int current_variable_position = 0;
    int current_position_In_Entry = 0;
    while(current_variable_position < position)
    {
        if (entry[current_position_In_Entry] == ' ')
            current_variable_position++;
        current_position_In_Entry ++;
    }

    QString read_var = "";

    while (current_variable_position != entry.length() || entry[current_variable_position] != ' ')
    {
        read_var.append(entry[current_variable_position]);
        current_variable_position++;
    }
    return read_var;
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
