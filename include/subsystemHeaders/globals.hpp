#include "main.h"

//MOTOR OBJECTS DECLARATION
extern pros::Motor driveLeftFront;
extern pros::Motor driveLeftBack;
extern pros::Motor driveRightFront;
extern pros::Motor driveRightBack;
extern pros::Motor claw; //not in use
extern pros::Motor lift;
extern pros::Motor mini_lift;

//CONTROLER OBJECT DECLARATION
extern pros::Controller master;

//SENSOR OBJECTS DECLARATION
extern pros::ADIPotentiometer potentiometer;
extern pros::ADIDigitalIn button;

//MISCALANIOUS CONSTANTS
#define MTR_LEFT_FRONT_PORT 2
#define MTR_LEFT_BACK_PORT 1
#define MTR_RIGHT_FRONT_PORT 4
#define MTR_RIGHT_BACK_PORT 3
#define MTR_CLAW_PORT 1 //not in use
#define MTR_LIFT_PORT 16
#define MTR_MINI_LIFT_PORT 12
#define SENSOR_POTENTIOMETER_PORT 'A'
#define SENSOR_BUTTON_PORT 'C'
#define toggle_Lift_Button DIGITAL_R1
#define toggle_MiniLift_Button DIGITAL_L1

extern int lift_state;
extern int mini_lift_state;
