#include "main.h"

//HELPER FUNCTION (DECLARATION)
void setLiftMotor(int distance);
void setMiniLiftMotor(int distance);

//CONTROL FUNCTION (DECLARATION)
//volatile int lift_state = -1; //lift down: -1
int controlSetLift();
int controlSetMiniLift();


//AUTONOMOUS FUNCTIONS (DECLARATION)
bool sense_touching_goal();
int sense_lift_angle();
