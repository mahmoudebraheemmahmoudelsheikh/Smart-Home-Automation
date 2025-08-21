/*
 * main.c
 *
 *  Created on: Oct 9, 2024
 *      Author: Tweety
 */

#include "GPIO.h"
#include "ADC.h"
#include "LCD.h"

#include "PWM.h"
#include "LDR.h"
#include "LED.h"
#include "DCMotor.h"
#include "FlameSensor.h"
#include "Buzzer.h"

#include <util/delay.h>
#define ldr_threshold_1      15
#define ldr_threshold_2      50
#define ldr_threshold_3      70
#define temp_high            40
#define temp_middile_high    35
#define temp_middile_low     30
#define temp_low             25


int main(void) {
    // Initialize modules
    DcMotor_Init();
    FlameSensor_init();
    LEDS_init();
    Buzzer_init();
    ADC_init();
    LCD_init();


    uint8 prev_flame_detected = 0xFF;
    uint8 flame_detected;
    uint16 temp_value, ldr_value;

    LCD_displayStringRowColumn(0, 0, "WELCOME TO");
    LCD_displayStringRowColumn(1, 0, "SmartHomeProject");

    _delay_ms(500);
    LCD_clearScreen();

    while (1) {
        temp_value = LM35_getTemperature();
        flame_detected = FlameSensor_getValue();
        ldr_value = LDR_getLightIntensity();

        if (flame_detected && flame_detected != prev_flame_detected)
        {

            Buzzer_on();
            LCD_clearScreen();
            LCD_displayStringRowColumn(0, 0, "Critical alert!");
            LCD_displayStringRowColumn(1, 0, "---------------");
            prev_flame_detected = flame_detected;
        }
        else if (!flame_detected && flame_detected != prev_flame_detected)
        {

            Buzzer_off();
            LCD_clearScreen();
            prev_flame_detected = flame_detected;
        }

        if (!flame_detected)
        {
            LCD_moveCursor(0, 0);

            if (temp_value >= temp_high)
            {
                PWM_Timer0_Start(100);
                DcMotor_Rotate(CW, 100);
                LCD_displayString("Fan is ON (100%)");
            }
            else if (temp_value >= temp_middile_high)
            {
                PWM_Timer0_Start(75);                        // Fan at 75%
                DcMotor_Rotate(CW, 75);
                LCD_displayString("Fan is ON (75%)");
            }
            else if (temp_value >= temp_middile_low)
            {
                PWM_Timer0_Start(50);                       // Fan at 50%
                DcMotor_Rotate(CW, 50);
                LCD_displayString("Fan is ON (50%)");
            }
            else if (temp_value >= temp_low)
            {
                PWM_Timer0_Start(25);                       // Fan at 25%
                DcMotor_Rotate(CW, 25);
                LCD_displayString("Fan is ON (25%)");
            }
            else
            {
                PWM_Timer0_Start(0);                       // Fan OFF
                DcMotor_Rotate(CW, 0);
                LCD_displayString("Fan is OFF");
            }

            // LED control based on light intensity
            if (ldr_value <= ldr_threshold_1)
            {
                LED_on(LED_RED);
                LED_on(LED_GREEN);
                LED_on(LED_BLUE);
            }
            else if (ldr_value <= ldr_threshold_2)
            {
                LED_on(LED_RED);
                LED_on(LED_GREEN);
                LED_off(LED_BLUE);
            }
            else if (ldr_value <= ldr_threshold_3)
            {
                LED_on(LED_RED);
                LED_off(LED_GREEN);
                LED_off(LED_BLUE);
            }
            else
            {
                LED_off(LED_RED);
                LED_off(LED_GREEN);
                LED_off(LED_BLUE);
            }

            // Display LDR and temperature readings
            LCD_moveCursor(1, 0);
            LCD_displayString("Temp=");
            LCD_intgerToString(temp_value);
            LCD_displayString("LDR=");
            LCD_intgerToString(ldr_value);
            LCD_displayString("% ");
        }
    }
}
