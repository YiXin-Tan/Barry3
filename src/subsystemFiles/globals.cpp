#include "main.h"

//MOTOR OBJECTS DEFINITION
pros::Motor driveLeftFront(MTR_LEFT_FRONT_PORT, pros::E_MOTOR_GEARSET_18, true, pros::E_MOTOR_ENCODER_COUNTS);
pros::Motor driveLeftBack(MTR_LEFT_BACK_PORT, pros::E_MOTOR_GEARSET_18, false, pros::E_MOTOR_ENCODER_COUNTS);
pros::Motor driveRightFront(MTR_RIGHT_FRONT_PORT, pros::E_MOTOR_GEARSET_18, false, pros::E_MOTOR_ENCODER_COUNTS);
pros::Motor driveRightBack(MTR_RIGHT_BACK_PORT, pros::E_MOTOR_GEARSET_18, true, pros::E_MOTOR_ENCODER_COUNTS);
//pros::Motor claw(MTR_CLAW_PORT, pros::E_MOTOR_GEARSET_18, false, pros::E_MOTOR_ENCODER_COUNTS);
pros::Motor lift(MTR_LIFT_PORT, pros::E_MOTOR_GEARSET_18, false, pros::E_MOTOR_ENCODER_COUNTS);
pros::Motor mini_lift(MTR_MINI_LIFT_PORT, pros::E_MOTOR_GEARSET_18, false, pros::E_MOTOR_ENCODER_COUNTS);


//CONTROLER OBJECT DEFINITION
pros::Controller master(pros::E_CONTROLLER_MASTER);

//SENSOR OBJECTS DEFINITION
pros::ADIPotentiometer potentiometer(SENSOR_POTENTIOMETER_PORT);
pros::ADIDigitalIn button(SENSOR_BUTTON_PORT);

int lift_state = -1;
int mini_lift_state = -1;
bool inFunc=false;
int sensitivity=10;
int controlState=1;
