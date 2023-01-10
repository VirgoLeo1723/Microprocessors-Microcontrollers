/*
 * scheduler.h
 *
 *  Created on: Nov 25, 2022
 *      Author: This PC
 */

#ifndef INC_SCHEDULER_H_
#define INC_SCHEDULER_H_
#include <stdint.h>

typedef struct{
	void (*task)(void);
	uint32_t Delay;
	uint32_t Period;
	uint8_t RunMe;
	uint32_t TaskId;
}sTask;
#define SCH_MAX_TASKS 40
#define ERROR_SCH_TOO_MANY_TASKS 41
#define ERROR_SCH_CANNOT_DELETE_TASK 42
void SCH_Update_Tasks();
int SCH_Add_Task(void (*task), int delay, int period);
void SCH_Dispatch_Tasks(void);
int SCH_Delete_Task(int index);


#endif /* INC_SCHEDULER_H_ */
