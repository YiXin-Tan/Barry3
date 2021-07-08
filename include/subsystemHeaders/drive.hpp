#include "main.h"

//HELPER FUNCTION (DECLARATION)
void leftDriveMotor(int i);
void rightDriveMotor(int i);
void setDriveMotor(int power, int turn);

void resetDriveEncoders();
double getAveragePosition();

//DRIVER CONTROL (DECLARATION)
void controlSetDrive();

//AUTONOMOUS CONTROL (DECLARATION)
void translate(int units, int voltage);
