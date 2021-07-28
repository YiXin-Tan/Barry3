#include "main.h"

//HELPER FUNCTION (DECLARATION)
void leftDriveMotor(int i);
void rightDriveMotor(int i);
void setDriveMotor(int power, int turn);

void accelerate(int targetPower, int turn);
void accelerate2(int targetPower, int currentPower,int lr);
void brake();

void resetDriveEncoders();
double getAveragePosition();

//DRIVER CONTROL (DECLARATION)
void controlSetDrive();
void controlSetDrive2();

//AUTONOMOUS CONTROL (DECLARATION)
void translate(int units, int voltage);

//MISCELANIOUS FUNCTIONS (DECLARATION)
int changeSens();
