/*
 * core.h
 *
 *  Created on: 8 июл. 2019 г.
 *      Author: rpiontik
 */

#ifndef MAIN_CORE_CORE_H_
#define MAIN_CORE_CORE_H_

//Initialization and start all core services
void thingjsInit(void);

//Inform core that system is ready
void thingjsStart(void);

//Main runtime function
void thingjsHandle(void);

#endif /* MAIN_CORE_CORE_H_ */
