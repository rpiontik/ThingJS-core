/*
 * core.h
 *
 *  Created on: 8 июл. 2019 г.
 *      Author: rpiontik
 */

#ifndef MAIN_CORE_CORE_H_
#define MAIN_CORE_CORE_H_

#include "freertos/FreeRTOSConfig.h"
#include "freertos/FreeRTOS.h"
#include <freertos/task.h>
#include "mjs.h"
#include "cJSON.h"

//Pin combinations cases
typedef int * thingjs_pin_cases;

//Constructor of ThingsJS interface
typedef mjs_val_t (*thingjs_interface_constructor)(struct mjs * mjs, cJSON * params);

//Destructor of ThingsJS interface
typedef void (*thingjs_interface_destructor)(struct mjs * mjs, mjs_val_t subject);

//Interface manifest
struct st_thingjs_interface_manifest {
    char *	type;							    //Name of interface type
    thingjs_interface_constructor constructor;	//JS interface creator
    thingjs_interface_destructor destructor;    //JS interface destroyer
    thingjs_pin_cases cases; 				    //Configurations cases
};

//Initialization and start all core services
void thingjsInit(void);

//Inform core that system is ready
void thingjsStart(void);

//Main runtime function
void thingjsHandle(void);

//Register ThingJS interface
void thingjsRegisterInterface(const struct st_thingjs_interface_manifest * interface);

typedef mjs_val_t (*SyncCallbackFunction)(struct mjs * context, void * data);

//Send request to mJS process for run callback function in sync mode
BaseType_t thingjsSendCallbackRequest(TaskHandle_t process, SyncCallbackFunction func, void * data);

//Return true is time is actual else false
//Result = actual time with offset
bool currentTime(time_t *result);

//Set time as current system time
//	time		- current time
void setCurrentTime(time_t time);

#endif /* MAIN_CORE_CORE_H_ */
