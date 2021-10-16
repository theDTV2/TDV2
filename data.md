Currently supported Data Types:





SPEED/MEMSPEED/TIME 		Zeit/Bitrate

-------------------------------------------------------------------------

Task Create : 			CRE 0 <task_number> <tick>
							NAM 0 <task_number> <task_name>
Task Enter:  			STA 0 <task_number> <tick>
Task Stop:				STO 0 <task_number> <tick>
Suspend:				STO 0 <task_number> <tick> //SAME AS TASK STOP
DONE Task Resume: 		STA 0 <task_number> <tick> //SAME AS TASK ENTER

Task Delete:			DEL 0 <task_number> <tick>
-------------------------------------------------------------------------


Queue Create:			CRE 3 <queue_number> <tick>
Queue Registry Add:		NAM 3 <queue_number> <queue_name>
Queue Send (+ISR):		STA 3 <queue_number> <tick> <messages_amount (always 1)>			
Queue Receive(+ISR):	STO 3 <queue_number> <tick> <messages_amount (always 1)>			
Queue Delete:			DEL 3 <queue_number> <tick>

-------------------------------------------------------------------------


User Agent Create: 	NAM 8 <id> <name>
User Agent Begin:  	STA 8 <id> <tick>
User Agent End:   	STO 8 <id> <tick>


-------------------------------------------------------------------------


Marker Create: 		NAM 7 <flag_number> <name>
Marker Occurence:	 	OCC 7 <flag_number> <tick>

Marker AddString			DSC 0 0 <string> //THIS REFERENCES THE LAST MARKER, THAT OCCURED
Marker AddNumber	 		DSC 1 1 <number> //THIS REFERENCES THE LAST MARKER, THAT OCCURED
Marker AddColor      		DSC 3 3 <color> //THIS REFERENCES THE LAST MARKER, THAT OCCURED



-------------------------------------------------------------------------


Handler Create: 		NAM 1 <irq> <name>
Handler Enter: 		STA 1 <irq> <tick>
Handler Exit:			STO 1 <irq> <tick>


-------------------------------------------------------------------------


