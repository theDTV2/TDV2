#include "datamodeller.h"




void DataModeller::setDataToProcess(QStringList string)
{
    s_rawData = string;
}

void DataModeller::processRawData()
{}
void DataModeller::parseEntry()
{}

//Task Create : 			CRE 0 <task_number> <tick>
//                              NAM 0 <task_number> <task_name>
void DataModeller::createNewTask()
{

}

//Queue Create:             CRE 3 <queue_number> <tick>
//Queue Registry Add:       NAM 3 <queue_number> <queue_name>
void DataModeller::createNewQueue()
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
//DONE Task Stop:           STO 0 <task_number> <tick>
void DataModeller::addTaskEntry()
{

}

//DONE Queue Send (+ISR):   STA 3 <queue_number> <tick> <messages_amount (always 1)>
//DONE Queue Receive(+ISR):	STA 3 <queue_number> <tick> <messages_amount (always 1)>
void DataModeller::addQueueEntry()
{

}

//DONE Marker Create: 		NAM 7 <flag_number> <name>
//DONE Marker Occurence:	 	OCC 7 <flag_number> <tick>
void DataModeller::addMarker()
{

}


void DataModeller::addHandlerEntry()
{

}


void DataModeller::addUserAgentEntry()
{

}
