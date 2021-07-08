#include "main.h"

//HELPER FUNCTION
void setLiftMotor(int distance){
  lift.move_relative(distance, 100); //distance either 100 or -100
}

void setMiniLiftMotor(int distance){
  mini_lift.move_relative(distance, 100); //distance either 100 or -100
}


//CONTROL FUNCTION
int controlSetLift(){
  //lift up / down toggle stitch: L1
  if (master.get_digital_new_press(toggle_Lift_Button)){
    lift_state = -1 * lift_state;
    //lift.move(lift_state * 100);
    setLiftMotor(lift_state * 100);
  }
  return lift_state;
  //int p = 127 * (master.get_digital(DIGITAL_L1) - master.get_digital(DIGITAL_L2));
  //setLiftMotor(p);
}

int controlSetMiniLift(){
  //lift up / down toggle stitch: L1
  if (master.get_digital_new_press(toggle_MiniLift_Button)){
    mini_lift_state = -1 * mini_lift_state;
    setLiftMotor(lift_state * 100);
  }
  return mini_lift_state;
}


//AUTONOMOUS FUNCTION
bool sense_touching_goal(){
  int a = button.get_new_press();
  if (button.get_new_press()){
    printf("%d", button.get_value());
  }
  return button.get_value();
}

int sense_lift_angle(){
  int angle = potentiometer.get_value();
  printf("%d\n", angle);
  return angle;
}
