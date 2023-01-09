/*
 * scheduler.c
 *
 *  Created on: Nov 12, 2022
 *      Author: htn23
 */
#include "scheduler.h"
sTask SCH_tasks_G [SCH_MAX_TASKS];
int 	Error_code_G = 0 ;
int 	task_id = 0;

void SCH_Init(void){
	unsigned char i ;
	for (i=0; i<SCH_MAX_TASKS; i++) SCH_Delete_Task(i);
	Error_code_G = 8;
	//Timer_Init();
	//Watchdog_Init();
}
void SCH_Update_Tasks(){
	unsigned char index;
	for (index = 0; index <SCH_MAX_TASKS; index ++){
		if (SCH_tasks_G[index].task != 0){
			if (SCH_tasks_G[index].Delay == 0){
				SCH_tasks_G[index].RunMe = 1;
				SCH_tasks_G[index].Delay = SCH_tasks_G[index].Period;
			} else SCH_tasks_G[index].Delay -= 1;
		}
	}
}
int SCH_Add_Task(void (*task), int delay, int period){
	unsigned char index=0;
	while ((SCH_tasks_G[index].task!=0) && (index < SCH_MAX_TASKS))
		index ++;

	if (index== SCH_MAX_TASKS){
		Error_code_G = ERROR_SCH_TOO_MANY_TASKS;
		return SCH_MAX_TASKS;
	}
	SCH_tasks_G[index].task 	= task;
	SCH_tasks_G[index].Delay 	= delay;
	SCH_tasks_G[index].Period 	= period;
	SCH_tasks_G[index].RunMe 	= 0;
	SCH_tasks_G[index].TaskId 	= task_id++;

	return index;
}
void SCH_Dispatch_Tasks(void){
	unsigned char index;
	for (index = 0; index < SCH_MAX_TASKS; index++){
		if (SCH_tasks_G[index].RunMe == 1){
			(*SCH_tasks_G[index].task)();
			SCH_tasks_G[index].RunMe = 0;
			if (SCH_tasks_G[index].Period == 0)
				SCH_Delete_Task(index);
		}

	}

}
int SCH_Delete_Task(int index){
	//TODO
	if (SCH_tasks_G[index].task == 0){
		Error_code_G = ERROR_SCH_CANNOT_DELETE_TASK;
		return 0;
	}
	else {
		SCH_tasks_G[index].task = 0x0000;
		SCH_tasks_G[index].Delay = 0;
		SCH_tasks_G[index].Period = 0;
		SCH_tasks_G[index].RunMe = 0;
		return 1;
	}
}

