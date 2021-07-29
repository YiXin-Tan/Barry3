#include "main.h"

//HELPER FUNCTION (DECLARATION)
void leftDriveMotor(int i);
void rightDriveMotor(int i);
void setDriveMotor(int power, int turn);

//DRIVER CONTROL (DECLARATION)
// void controlSetDrive();
void controlSetDrive2();

//ACCELERATION & BREAK(DECLARATION)
void accelerate(int targetPower, int turn);
void accelerate2(int targetPower, int currentPower,int lr);
void brake();


//AUTONOMOUS CONTROL (DECLARATION)
void resetDriveEncoders();
double getAveragePosition();
void translate(int units, int voltage);

//MISCELANIOUS FUNCTIONS (DECLARATION)
int changeSens();
