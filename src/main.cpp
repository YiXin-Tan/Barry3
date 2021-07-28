#include "main.h"

void initialize() {
	pros::lcd::initialize();
	pros::lcd::set_text(1, "G'day! Uploaded via controller");
	autonomous();
}

void disabled() {}

void competition_initialize() {}

void autonomous() {
	printf("Running autonomous\n");
	pros::delay(2000);
	//driveLeftBack.move(50); //plug into port12
}

int changeControlSet(){
	controlState=controlState*-1;
	return(controlState);
}

void opcontrol() {
	while(true){
		if(controlState==1){
				controlSetDrive();
		}else{
				controlSetDrive2();
		}
		brake();
		int e = changeControlSet();
		int d = changeSens();
		int c = controlSetMiniLift();
		int b = controlSetLift();
		int a = sense_lift_angle();
		pros::lcd::print(0, "angle:%d", a);
		pros::lcd::print(1, "lift:%d", b);
		pros::lcd::print(2, "mini_lift:%d", c);
		pros::lcd::print(3, "Current sensitivity: %d",d);
		pros::lcd::print(4, "Current Control Set: %d",e);
		pros::delay(100);
	}
}
