/*
 * Scheduler.h
 *
 *  Created on: Nov 12, 2022
 *      Author: htn23
 */


#ifndef INC_SCHEDULER_H_
#define INC_SCHEDULER_H_

#include "main.h"
#include "global.h"

#define SCH_MAX_TASKS 				40
#define NO_TASK_ID 					0

#define	ERROR_SCH_TOO_MANY_TASKS						0
#define ERROR_SCH_WAITNG_FOR_SLAVE_TO_ACK				1
#define ERROR_SCH_WAITING_FOR_START_COMMAND_FROM_MASTER	2
#define ERROR_SCH_ONE_OR_MORE_SLAVES_DID_NOT_START		3
#define ERROR_SCH_LOST_SLAVE							4
#define ERROR_SCH_CAN_BUS_ERROR							5
#define ERROR_I2C_WRITE_BYTE_AT24C64					6
#define ERROR_SCH_CANNOT_DELETE_TASK					7

typedef struct{
	void (* task)(void);
	uint32_t Delay;
	uint32_t Period;
	uint8_t  RunMe;
	uint32_t TaskId;
} sTask;

extern sTask SCH_tasks_G [SCH_MAX_TASKS];
extern int 	Error_code_G;
extern int 	task_id;

void SCH_Init(void);
int SCH_Add_Task(void (*task), int delay, int period);
int SCH_Delete_Task(int index);

void SCH_Update_Tasks(void);
void SCH_Dispatch_Tasks(void);



#endif /* INC_SCHEDULER_H_ */
