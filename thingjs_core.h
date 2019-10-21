/*
 * core.h
 *
 *  Created on: 8 июл. 2019 г.
 *      Author: rpiontik
 */

#ifndef MAIN_CORE_CORE_H_
#define MAIN_CORE_CORE_H_

#include "mjs.h"
#include "cJSON.h"

//Pin combinations cases
typedef int * thingjs_pin_cases;

//Constructor of ThingsJS interface
typedef mjs_val_t (*thingjs_interface_constructor)(struct mjs * mjs, cJSON * params);

//Interface manifest
struct st_thingjs_interface_manifest {
    char *	type;							    //Name of interface type
    thingjs_interface_constructor constructor;	//JS interface
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

#endif /* MAIN_CORE_CORE_H_ */
