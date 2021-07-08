#include "main.h"

//test comment
//test comment2
//another test comment

void initialize() {
	pros::lcd::initialize();
	pros::lcd::set_text(1, "G'day!");
	autonomous();
}

void disabled() {}

void competition_initialize() {}

void autonomous() {
	driveLeftBack.move(50); //plug into port12
}

void opcontrol() {

}
