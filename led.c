/*
 *led.c
 *
 *  Created on: Oct 6, 2024
 *      Author: Tweety
 */

#include "gpio.h"
#include "led.h"
#include "avr/io.h"



void LED_on(LED_ID id) {
    GPIO_writePin(PORTB_ID, id, LOGIC_HIGH);
}

void LED_off(LED_ID id) {
    GPIO_writePin(PORTB_ID, id, LOGIC_LOW);
}
void LEDS_init(void) {
    GPIO_setupPinDirection(PORTB_ID, PIN5_ID, PIN_OUTPUT);
    GPIO_setupPinDirection(PORTB_ID, PIN6_ID, PIN_OUTPUT);
    GPIO_setupPinDirection(PORTB_ID, PIN7_ID, PIN_OUTPUT);
    LED_off(LED_RED);
    LED_off(LED_GREEN);
    LED_off(LED_BLUE);
}



