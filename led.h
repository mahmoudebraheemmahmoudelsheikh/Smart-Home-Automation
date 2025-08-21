/*
 *led.h
 *
 *  Created on: Oct 6, 2024
 *      Author: Tweety
 */

#ifndef LED_H_
#define LED_H_

#include "std_types.h"

typedef enum {
    LED_RED = 5,
    LED_GREEN = 6,
    LED_BLUE = 7
} LED_ID;


void LED_on(LED_ID id);

void LED_off(LED_ID id);

void LEDS_init(void);


#endif /* LED_H_ */
