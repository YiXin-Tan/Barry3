#include "main.h"

int changeSens(){
  if(master.get_digital_new_press(decrementSensButton)){
    if(sensitivity-1 != 0){
      sensitivity--;
      return(sensitivity);
    }
  }
  if(master.get_digital_new_press(incrementSensButton)){
    sensitivity++;
    return(sensitivity);
  }
  return(0); //unsure?
}

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

//Slowly increments power for which the motors will move at
void accelerate(int targetPower, int turn){
  inFunc=true;
  while(inFunc==true){
    for(int i= previousTurn + driveRightFront.get_power();i<targetPower;i=i+sensitivity){
      setDriveMotor(i,turn);
      inFunc=false;
    }
    for(int i= previousTurn+ driveRightFront.get_power();i>targetPower;i=i-sensitivity){
      setDriveMotor(i,turn);
      inFunc=false;
    }
  }
  }

void accelerate2(int targetPower, int currentPower, int lr){
  inFunc=true;
  while(inFunc==true){
    for(int i = currentPower; i < targetPower; i=i+sensitivity){
      if(lr==1){
        leftDriveMotor(i);
      }else{
        rightDriveMotor(i);
      }
    }
    for(int i = currentPower; i > targetPower; i=i-sensitivity){
        if(lr==1){
          leftDriveMotor(i);
        }else{
          rightDriveMotor(i);
        }
    }
    inFunc=false;
  }
}

//Brakes the motors
void brake(){
  if(master.get_digital_new_press(brake_button)){
    driveLeftFront.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
    driveLeftBack.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
    driveRightFront.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
    driveRightBack.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
  }
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

  printf("P%d T%d", drivePower, driveTurn);
  //printf("M1%d", driveLeftBack.get_position());
  setDriveMotor(drivePower, driveTurn);
  //setDriveMotor(drivePower, 0);
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
