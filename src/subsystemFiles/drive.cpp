#include "main.h"

//=======================HELPER FUNCTIONS (DEFINION)=======================
//motor.move max range: [-127 ~ 127]
//controler max range: [-127 ~ 127]
void leftDriveMotor(int i){
  driveLeftFront.move(i);
  driveLeftBack.move(i);
  // pros::lcd::print(5, "i%d", i);
}

void rightDriveMotor(int i){
  driveRightFront.move(i);
  driveRightBack.move(i);
}

void setDriveMotor(int power, int turn){
  leftDriveMotor(power + turn); // if turn ->, left motor have to turn more
  rightDriveMotor(power - turn);
}

//=======================DRIVER CONTROL (DEFINION)=======================
//Archade(single) Control (no longer in use)
/*
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
  */

  //Tank(dual) Control
  void controlSetDrive2(){
    if(master.get_digital(BRAKE_BUTTON)){
      driveLeftFront.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
      driveLeftBack.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
      driveRightFront.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
      driveRightBack.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
      // get percentages of L&R ANALOG_Y, then mutiply by control_cap
      double analog_left_y = (double) master.get_analog(ANALOG_LEFT_Y);
      double double_drivePowerBrake = analog_left_y / 127 * 50;
      int drivePowerBrake = (int) double_drivePowerBrake;

      driveLeftFront.move_velocity(drivePowerBrake);
      driveLeftBack.move_velocity(drivePowerBrake);
      driveRightFront.move_velocity(drivePowerBrake);
      driveRightBack.move_velocity(drivePowerBrake);
      // leftDriveMotor(drivePowerLeft);
      // rightDriveMotor(drivePowerRight);
    }
    else if (master.get_digital(pros::E_CONTROLLER_DIGITAL_Y)){
      driveLeftFront.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
      driveLeftBack.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
      driveRightFront.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
      driveRightBack.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
      double analog_left_x = (double) master.get_analog(ANALOG_LEFT_X);
      double double_drivePowerTurn = analog_left_x / 127 * control_cap;
      int drivePowerTurn = (int) double_drivePowerTurn;

      leftDriveMotor(drivePowerTurn);
      rightDriveMotor(-drivePowerTurn);

    }
    else{
      driveLeftFront.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
      driveLeftBack.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
      driveRightFront.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
      driveRightBack.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
      double analog_left_y = (double) master.get_analog(ANALOG_LEFT_Y);
      double double_drivePowerLeft = analog_left_y / 127 * control_cap;
      int drivePowerLeft = (int) double_drivePowerLeft;

      double analog_right_y = (double) master.get_analog(ANALOG_RIGHT_Y);
      double double_drivePowerRight = analog_right_y / 127 * control_cap;
      int drivePowerRight = (int) double_drivePowerRight;

      if(abs(drivePowerRight) < 3) // Right power=0 if joystick analog val too small
      drivePowerRight = 0;
      if(abs(drivePowerLeft) < 3) //Left power=0 if joystick analog val too small
      drivePowerLeft=0;

      leftDriveMotor(drivePowerLeft);
      rightDriveMotor(drivePowerRight);
    }




    /*
    // int driveTurnRight = master.get_analog(ANALOG_RIGHT_X);
    // int driveTurnLeft = master.get_analog(ANALOG_LEFT_X);
    if(abs(driveTurnRight) < 10) // Right turn=0 if joystick analog val too small
    driveTurnRight = 0;
    if(abs(driveTurnLeft) < 10) //Left turn=0 if joystick analog val too small
    driveTurnLeft=0;

    printf("RP%d RT%d \n", drivePowerRight, driveTurnRight);
    printf("LP%d LT%d \n", drivePowerLeft, driveTurnLeft);

    leftDriveMotor(drivePowerLeft + driveTurnLeft);
    rightDriveMotor(drivePowerRight + driveTurnRight);

    accelerate2(drivePowerLeft, driveLeftFront.get_power(), 1);
    accelerate2(drivePowerRight, driveRightBack.get_power(), 2);
    */
  }

//=======================ACCELERATION & BREAK (DEFINION)=======================
//Slowly increments power for which the motors will move at
/*
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
*/

//Brakes the motors
int brake(){
  if (master.get_digital_new_press(BRAKE_BUTTON)){
    brake_state = -brake_state;
  //   if (brake_state){ //brake_state = 1: apply brake
  //     master.rumble("-");
  //     pros::delay(1000);
  //     return 1;
  //   }
  //   else{
  //     master.rumble(".");
  //   }
  }
  // if(master.get_digital(BRAKE_BUTTON)){
  //   driveLeftFront.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
  //   driveLeftBack.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
  //   driveRightFront.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
  //   driveRightBack.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
  //   driveLeftFront.move_velocity(0);
  //   driveLeftBack.move_velocity(0);
  //   driveRightFront.move_velocity(0);
  //   driveRightBack.move_velocity(0);
  // }
  // else{
  //   driveLeftFront.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
  //   driveLeftBack.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
  //   driveRightFront.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
  //   driveRightBack.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
  // }
  // return master.get_digital(BRAKE_BUTTON);
  return brake_state;
}

//=======================AUTONOMOUS CONTROL (DEFINION)=======================

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

//=======================MISCELANIOUS FUNCTIONS (DEFINION)=======================
int changeSens(){
  /*
  motor.move max range: -127 ~ 127
  master.ANALOG_Y max range: -127 ~ 127
  control_cap max range: 0 ~ 127 (increment by +- 25)
  127
  102
  77
  52
  27
  */
  if(master.get_digital_new_press(INCREMENT_SENSITIVITY_BUTTON) && control_cap < 127){
    control_cap += 25;
  }
  if(master.get_digital_new_press(DECREMENT_SENSITIVITY_BUTTON) && control_cap > 27){
    control_cap -= 25;
  }
  return(control_cap);
}
