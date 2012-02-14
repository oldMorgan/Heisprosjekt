#ifndef ELEVATOR_IO_H
#define ELEVATOR_IO_H

#include "elev.h"
#include "elevator_ctrl.h"

extern direction_t direction;

#define buttonType_t elev_button_type_t
void io_resetStopLight();
void io_closeDoor();
void io_resetAllButtonLights();
void io_resetFloorLightsOnTemporaryStop(int, direction_t);
void io_resetButtonLight(buttonType_t,int);
void io_setStopLight();
void io_openDoor();
//void io_setFloorCallLight(floor_t, direction_t);
void io_setButtonLight(buttonType_t, int);
//void io_setCommandLight(floor_t);
void io_setFloorIndicator(int);

void io_startMotor();
void io_stopMotor();
int io_elevatorIsObstructed();
int io_elevatorIsInFloor();
int io_getCurrentFloor();
#endif
