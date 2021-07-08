#include "main.h"

void initialize() {
	pros::lcd::initialize();
	pros::lcd::set_text(1, "G'day! Uploaded via controller");
	printf("G'day!\n");
	autonomous();
}

void disabled() {}

void competition_initialize() {}

void autonomous() {
	printf("Running autonomous\n");
	pros::delay(2000);
	//driveLeftBack.move(50); //plug into port12
}

void opcontrol() {
	while(true){
		controlSetDrive();
		int a = sense_lift_angle();
		pros::lcd::print(0, "angle:%d", a);
		pros::delay(100);
	}
}
