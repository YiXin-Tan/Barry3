#include "main.h"

//MOTOR OBJECTS DEFINITION
pros::Motor driveLeftFront(MTR_LEFT_FRONT_PORT, pros::E_MOTOR_GEARSET_18, false, pros::E_MOTOR_ENCODER_COUNTS);
pros::Motor driveLeftBack(MTR_LEFT_BACK_PORT, pros::E_MOTOR_GEARSET_18, true, pros::E_MOTOR_ENCODER_COUNTS);
pros::Motor driveRightFront(MTR_RIGHT_FRONT_PORT, pros::E_MOTOR_GEARSET_18, true, pros::E_MOTOR_ENCODER_COUNTS);
pros::Motor driveRightBack(MTR_RIGHT_BACK_PORT, pros::E_MOTOR_GEARSET_18, false, pros::E_MOTOR_ENCODER_COUNTS);

//CONTROLER OBJECT DEFINITION
pros::Controller master(pros::E_CONTROLLER_MASTER);
