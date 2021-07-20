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
     // quint64 startTick
    //TaskModel()



}

//Queue Create:             CRE 3 <queue_number> <tick>
void DataModeller::CreateNewQueue()
{

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

//DONE Task Enter:          STA 0 <task_number> <tick>
void DataModeller::AddTaskEnter()
{

}

//DONE Task Stop:           STO 0 <task_number> <tick>
void DataModeller::AddTaskStop()
{

}

//DONE Queue Send (+ISR):   STA 3 <queue_number> <tick> <messages_amount (always 1)>
void DataModeller::AddQueueSend()
{

}

//DONE Queue Receive(+ISR):	STO 3 <queue_number> <tick> <messages_amount (always 1)>
void DataModeller::AddQueueReceive()
{

}

//DONE Marker Create: 		NAM 7 <flag_number> <name>
void DataModeller::CreateMarker()
{

}

//DONE Marker Occurence:	OCC 7 <flag_number> <tick>
void DataModeller::AddMarkerOccurance()
{

}

//Marker AddString			DSC 0 0 <string> //THIS REFERENCES THE LAST MARKER, THAT OCCURED
//Marker AddNumber	 		DSC 1 1 <number> //THIS REFERENCES THE LAST MARKER, THAT OCCURED
//Marker AddColor      		DSC 3 3 <color> //THIS REFERENCES THE LAST MARKER, THAT OCCURED
void DataModeller::AddMarkerProperty()
{

}

//DONE Handler Enter: 		STA 1 <irq> <tick>
void DataModeller::AddHandlerEnter()
{

}

//DONE Handler Exit:		STO 1 <irq> <tick>
void DataModeller::AddHandlerExit()
{

}

//DONE User Agent Begin:  	STA 8 <id> <tick>
void DataModeller::AddUserAgentEnter()
{

}

//DONE User Agent End:   	STO 8 <id> <tick>
void DataModeller::AddUserAgentExit()
{

}

/*
 * Call getVariableAtPositionInGivenEntry() with our current entry
 *
 */
template<class T>
bool DataModeller::GetVariableAtPositionInCurrentEntry(quint8 position, T *read_variable)
{
    return GetVariableAtPositionInGivenEntry(current_string_,position,read_variable);
}

/*
 * Get given Variable at position from given entry
 * specialized for QString
 */
template<>
bool DataModeller::GetVariableAtPositionInGivenEntry<QString>(QString entry,quint8 position, QString *read_variable)
{

    *read_variable = GetStringAtPosition(entry, position);

    return true;
}

/*
 * Get given Variable at position from given entry
 * specialized for quint64
 */
template<>
bool DataModeller::GetVariableAtPositionInGivenEntry<quint64>(QString entry,quint8 position, quint64 *read_variable)
{

    *read_variable = GetStringAtPosition(entry, position).toULongLong();

    return true;
}

/*
 * Get given Variable at position from given entry
 * specialized for qint64
 */
template<>
bool DataModeller::GetVariableAtPositionInGivenEntry<qint64>(QString entry,quint8 position, qint64 *read_variable)
{

    *read_variable = GetStringAtPosition(entry, position).toLongLong();

    return true;
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

    QString readVar = "";

    while (current_variable_position != entry.length() || entry[current_variable_position] != ' ')
    {
        readVar.append(entry[current_variable_position]);
        current_variable_position++;
    }
    return readVar;
}
