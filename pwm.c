/*
 *pwm.c
 *
 *  Created on: Oct 6, 2024
 *      Author: Tweety
 */


#include "PWM.h"
#include "avr/io.h"

void PWM_Timer0_Start(uint8 duty_cycle) {

    // Set fast PWM mode with non-inverting output

    TCCR0 = (1<<WGM00) | (1<<WGM01) | (1<<COM01) | (1<<CS02) | (1<<CS00);
    OCR0 = (duty_cycle * 255) / 100;
    DDRB |= (1<<PB3);
}
