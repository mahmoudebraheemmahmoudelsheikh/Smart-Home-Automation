/*
 * dcmotor.h
 *
 *  Created on: Oct 6, 2024
 *      Author: Tweety
 */

#ifndef DCMOTOR_H_
#define DCMOTOR_H_

#include "std_types.h"

typedef enum {
    CW,
    A_CW,
    STOP
} DcMotor_State;

void DcMotor_Init(void);
void DcMotor_Rotate(DcMotor_State state, uint8 speed);

#endif
