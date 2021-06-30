#include "datamodeller.h"




void DataModeller::setDataToProcess(QStringList string)
{
    s_rawData = string;
}

void DataModeller::processRawData()
{
    bool done = false;

    while(!done)
    {
        parseEntry();

        if (s_rawData.empty())
            done = true;

    }

}
void DataModeller::parseEntry()
{
    getNextLine();


    if (s_currentString.startsWith("CRE 0"))
        return createNewTask();

    if (s_currentString.startsWith("CRE 3"))
        return createNewQueue();

    if (s_currentString.startsWith("NAM 3"))
        return addQueueReg();

    if (s_currentString.startsWith("CRE 3"))
        return createNewQueue();

    if (s_currentString.startsWith("NAM 1"))
        return createNewHandler();

    if (s_currentString.startsWith("NAM 8"))
        return createNewUserAgent();

    if (s_currentString.startsWith("STA 0"))
        return addTaskEnter();

    if (s_currentString.startsWith("STO 0"))
        return addTaskStop();

    if (s_currentString.startsWith("STA 3"))
        return addQueueSend();

    if (s_currentString.startsWith("STO 3"))
        return addQueueReceive();

    if (s_currentString.startsWith("NAM 7"))
        return createMarker();

    if (s_currentString.startsWith("OCC 7"))
        return addMarkerOccurance();

    if (s_currentString.startsWith("DSC"))
        return addMarkerProperty();

    if (s_currentString.startsWith("STA 1"))
        return addHandlerEnter();

    if (s_currentString.startsWith("STO 1"))
        return addHandlerExit();

    if (s_currentString.startsWith("STA 8"))
        return addUserAgentEnter();

    if (s_currentString.startsWith("STO 8"))
        return addUserAgentExit();


    //If we arrive here, we have an disallowed input

}

void DataModeller::getNextLine()
{
    s_currentString = s_rawData.takeFirst();
}


//Task Create : 			CRE 0 <task_number> <tick>
//                          NAM 0 <task_number> <task_name>
void DataModeller::createNewTask()
{
  //  quint64 startTick
    //TaskModel()

}

//Queue Create:             CRE 3 <queue_number> <tick>
void DataModeller::createNewQueue()
{

}

//Queue Registry Add:       NAM 3 <queue_number> <queue_name>
void DataModeller::addQueueReg()
{

}

//Handler Create:           NAM 1 <irq> <name>
void DataModeller::createNewHandler()
{

}

//User Agent Create:        NAM 8 <id> <name>
void DataModeller::createNewUserAgent()
{

}

//DONE Task Enter:          STA 0 <task_number> <tick>
void DataModeller::addTaskEnter()
{

}

//DONE Task Stop:           STO 0 <task_number> <tick>
void DataModeller::addTaskStop()
{

}

//DONE Queue Send (+ISR):   STA 3 <queue_number> <tick> <messages_amount (always 1)>
void DataModeller::addQueueSend()
{

}

//DONE Queue Receive(+ISR):	STO 3 <queue_number> <tick> <messages_amount (always 1)>
void DataModeller::addQueueReceive()
{

}

//DONE Marker Create: 		NAM 7 <flag_number> <name>
void DataModeller::createMarker()
{

}

//DONE Marker Occurence:	OCC 7 <flag_number> <tick>
void DataModeller::addMarkerOccurance()
{

}

//Marker AddString			DSC 0 0 <string> //THIS REFERENCES THE LAST MARKER, THAT OCCURED
//Marker AddNumber	 		DSC 1 1 <number> //THIS REFERENCES THE LAST MARKER, THAT OCCURED
//Marker AddColor      		DSC 3 3 <color> //THIS REFERENCES THE LAST MARKER, THAT OCCURED
void DataModeller::addMarkerProperty()
{

}

//DONE Handler Enter: 		STA 1 <irq> <tick>
void DataModeller::addHandlerEnter()
{

}

//DONE Handler Exit:		STO 1 <irq> <tick>
void DataModeller::addHandlerExit()
{

}

//DONE User Agent Begin:  	STA 8 <id> <tick>
void DataModeller::addUserAgentEnter()
{

}

//DONE User Agent End:   	STO 8 <id> <tick>
void DataModeller::addUserAgentExit()
{

}
