#include "main.h"

//HELPER FUNCTIONS (DEFINITION)
void leftDriveMotor(int i){
  driveLeftFront.move(i);
  driveLeftBack.move(i);
  pros::lcd::print(5, "i%d", i);
}

void rightDriveMotor(int i){
  driveRightFront.move(i);
  driveRightBack.move(i);
}

void setDriveMotor(int power, int turn){
  leftDriveMotor(power + turn); // if turn ->, left motor have to turn more
  rightDriveMotor(power - turn);
}

void resetDriveEncoders(){
  driveLeftFront.tare_position();
  driveLeftBack.tare_position();
  driveRightFront.tare_position();
  driveRightBack.tare_position();
}

double getAveragePosition(){
  return fabs(driveLeftFront.get_position() +
              driveLeftBack.get_position() +
              driveRightFront.get_position() +
              driveRightBack.get_position()) / 4;
}

//DRIVER CONTROL (DEFINION)
void controlSetDrive(){
  int drivePower = master.get_analog(ANALOG_RIGHT_Y);
  int driveTurn = master.get_analog(ANALOG_RIGHT_X);
  if(abs(drivePower) < 10) // power=0 if joystick analog val too small
    drivePower = 0;
  if(abs(driveTurn) < 10) // turn=0 if joystick analog val too small
    driveTurn = 0;
  pros::lcd::print(4, "P%d T%d \n", drivePower, driveTurn);

  printf("P%d T%d \n", drivePower, driveTurn);
  setDriveMotor(drivePower, driveTurn);
}

//DRIVER CONTROL SET 2 (definition)
void controlSetDrive2(){
  int drivePowerRight = master.get_analog(ANALOG_RIGHT_Y);
  int driveTurnRight = master.get_analog(ANALOG_RIGHT_X);
  int drivePowerLeft = master.get_analog(ANALOG_LEFT_Y);
  int driveTurnLeft = master.get_analog(ANALOG_LEFT_X);
  if(abs(drivePowerRight) < 10) // Right power=0 if joystick analog val too small
    drivePowerRight = 0;
  if(abs(driveTurnRight) < 10) // Right turn=0 if joystick analog val too small
    driveTurnRight = 0;
  if(abs(driveTurnLeft) < 10) //Left turn=0 if joystick analog val too small
    driveTurnLeft=0;
  if(abs(drivePowerLeft)<10) //Left power=0 if joystick analog val too small
    drivePowerLeft=0;
  printf("RP%d RT%d \n", drivePowerRight, driveTurnRight);
  printf("LP%d LT%d \n", drivePowerLeft, driveTurnLeft);

  leftDriveMotor(drivePowerLeft + driveTurnLeft);
  rightDriveMotor(drivePowerRight + driveTurnRight);
}

//AUTONOMOUS CONTROL (DEFINITION)
void translate(int units, int voltage){
  int direction = abs(units) / units;
  resetDriveEncoders();
  while(getAveragePosition() < abs(units)){
    setDriveMotor(direction * voltage, direction * voltage);
    pros::delay(20);
  }
  setDriveMotor(direction * -10, direction * -10);
  pros::delay(50);
  setDriveMotor(0,0);
}
