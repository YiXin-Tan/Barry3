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
	lift.move_relative(50, 100);
	pros::delay(2000);
}

void opcontrol() {
	master.rumble("...");
	while(true){
    master.print(0, 0, "hi");
		int sens = changeSens();
		int br = brake(); //checks when 'X' is pressed, then apply brakes
		controlSetDrive2(); //Always on tank(dual) control

		int lift_angle = controlSetLift();
		int mini_lift_s = controlSetMiniLift();
		

		pros::lcd::print(1, "Lift angle:%d", lift_angle);
		pros::lcd::print(2, "Mini lift state:%d", mini_lift_s);
		pros::lcd::print(3, "Sensitivity: %d",sens);
		pros::lcd::print(4, "Break: %d",br);
		
		// pros::lcd::print(0, "Lift angle:%d", a);
		// pros::lcd::print(4, "Current Control Set: %d",e);
		pros::delay(100);
	}
}
