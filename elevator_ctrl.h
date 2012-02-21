#ifndef ELEVATOR_CTRL_H
#define ELEVATOR_CTRL_H

//TODO: stdio.h er kun for feilsøking, kan fjernes i endelig versjon
#include <stdio.h>
#include <time.h>
#include "elevator_sm.h"
#include "elevator_ui.h"
#include "elevator_io.h"

#define NUMBEROFFLOORS 4 
#define NUMBEROFBUTTONTYPES 3
#define COMMAND 2


typedef enum {
	UP=1, 
	DOWN=-1
}direction_t;

extern state_t state;
extern elev_button_type_t lastButtonTypeOrder;
extern int lastFloorOrder;
extern int motorIsRunning;

void potet(char[]);
void debug_printDestinationMatrix();
void ctrl_initiateElevator();
/*Actions*/
void ctrl_handleStop();
void ctrl_handleEmergencyStop();
void ctrl_handleDestination();
void ctrl_handleDestinationFromIdle();
void ctrl_handleDestinationFromEM();
void ctrl_addOrderToList();
/*Guards*/
int ctrl_orderTypeCommand();
int ctrl_orderNotInCurrentFloor();
int ctrl_noObstruction();
int ctrl_floorHasOrder();
int ctrl_doorClosed();
/*hovedfunksjoner*/
//void ctrl_goToOrder();
void ctrl_checkSensor();
int ctrl_orderAtCurrentFloor();
/*Støttefunksjoner*/
void ctrl_setNewDirection();
int ctrl_checkLowerFloorsForOrders();
int ctrl_checkUpperFloorsForOrders();
void ctrl_clearDestinationMatrix();
void ctrl_setLightsAtElevatorStop();
int ctrl_orderListHasOrders();
void ctrl_removeOrder();

#endif //ELEVATOR_CTRL_H
