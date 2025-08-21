/*
 *ldr.c
 *
 *  Created on: Oct 9, 2024
 *      Author: Tweety
 */


#include "ADC.h"
#include "gpio.h"
#define LDR_CHANNEL 0

uint16 LDR_getLightIntensity(void) {

    GPIO_setupPinDirection(PORTA_ID, PIN0_ID, PIN_INPUT);
    uint16 adc_value = ADC_readChannel(LDR_CHANNEL);
    uint16 light_intensity = ((uint32)adc_value * 100) / 1024;
    return light_intensity;
}
