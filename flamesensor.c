/*
 * flamesensor.c
 *
 *  Created on: Oct 8, 2024
 *      Author: Tweety
 */

#include "GPIO.h"
#include "avr/io.h"


void FlameSensor_init(void) {
    GPIO_setupPinDirection(PORTD_ID, PIN2, PIN_INPUT);
}

uint8 FlameSensor_getValue(void) {
    return GPIO_readPin(PORTD_ID, PIN2);
}

