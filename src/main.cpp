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
}

// int changeControlSet(){
// 	controlState=controlState*-1;
// 	return(controlState);
// }

void opcontrol() {
	while(true){
		// always using tank(dual), no longer using archade(single) control, no need to toggle between controls
		// if(controlState==1){
		// 		controlSetDrive();
		// }else{
		// 		controlSetDrive2();
		// }
		controlSetDrive2(); //Always on tank(dual) control
		brake(); //checks when 'X' is pressed, then apply brakes

		int b = controlSetLift();
		int c = controlSetMiniLift();
		int d = changeSens();
		// int a = sense_lift_angle();
		// int e = changeControlSet();

		pros::lcd::print(1, "Lift state:%d", b);
		pros::lcd::print(2, "Mini lift state:%d", c);
		pros::lcd::print(3, "Current sensitivity: %d",d);
		// pros::lcd::print(0, "Lift angle:%d", a);
		// pros::lcd::print(4, "Current Control Set: %d",e);
		pros::delay(100);
	}
}
