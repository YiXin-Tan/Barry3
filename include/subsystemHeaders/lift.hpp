#include "main.h"

//HELPER FUNCTION (DECLARATION)
void setLiftMotor(int distance);

//CONTROL FUNCTION (DECLARATION)
//int lift_state = -1; //lift down: -1
void controlSetLift();

//AUTONOMOUS FUNCTIONS (DECLARATION)
bool sense_touching_goal();
int sense_lift_angle();
