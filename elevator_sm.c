#include "elevator_sm.h"

static state_t state=IDLE;
struct state_action_pair_t{
	state_t nextState;
	int (*guard)();	
	void (*action)();
};

/*nextState, guard, action (også kjent som nestetilstand, betingelse, handling)*/
struct state_action_pair_t stateTable[NUMBEROFSTATES][NUMBEROFEVENTS] = {
/*				NEW_DESTINATION									FLOOR_REACHED								STOP_PRESSED						ORDER_BUTTON_PRESSED		*/
/*EXECUTING_ORDER*/		{{EXECUTING_ORDER, NULL, NULL},							{TEMPORARY_STOP, ctrl_stopElevatorAtCurrentFloor, ctrl_handleStop},	{EMERGENCY_STOP, NULL, ctrl_handleEmergencyStop},	{EXECUTING_ORDER, NULL, ctrl_handleNewOrder}				},
/*TEMPORARY_STOP*/		{{EXECUTING_ORDER, ctrl_doorClosed, ctrl_handleDestination},			{IDLE, ctrl_doorClosed, NULL},						{EMERGENCY_STOP, NULL, ctrl_handleEmergencyStop},	{TEMPORARY_STOP,ctrl_newOrderNotInCurrentFloor,ctrl_handleNewOrder}	},
/*IDLE*/			{{EXECUTING_ORDER, ctrl_orderListHaveOrders, ctrl_handleDestinationFromIdle},	{IDLE, NULL, NULL},							{EMERGENCY_STOP, NULL, ctrl_handleEmergencyStop},	{IDLE, NULL, ctrl_handleNewOrder}					},
/*EMERGENCY_STOP*/		{{EXECUTING_ORDER, ctrl_noObstruction, ctrl_handleDestinationFromEM},		{EMERGENCY_STOP, NULL, NULL},						{EMERGENCY_STOP, NULL, ctrl_handleEmergencyStop},	{EMERGENCY_STOP, ctrl_newOrderFromCommandButton, ctrl_handleNewOrder}	},
};

void sm_handleEvent(event_t event){
	struct state_action_pair_t transition = stateTable[state][event];
	if(transition.guard == NULL || transition.guard()){
		state = transition.nextState;
		if(transition.action != NULL)
			transition.action();
	}
}
