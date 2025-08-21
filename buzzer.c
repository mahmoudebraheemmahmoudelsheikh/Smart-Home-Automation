/*
 * buzzer.c
 *
 *  Created on: Oct 7, 2024
 *      Author: Tweety
 */

#include "GPIO.h"
#include "avr/io.h"
#include "buzzer.h"



void Buzzer_on(void) {
    GPIO_writePin(PORTD_ID, PIN3_ID, LOGIC_HIGH);
}

void Buzzer_off(void) {
    GPIO_writePin(PORTD_ID, PIN3_ID, LOGIC_LOW);
}
void Buzzer_init(void) {
    GPIO_setupPinDirection(PORTD_ID, PIN3_ID, PIN_OUTPUT);
    Buzzer_off();
}
