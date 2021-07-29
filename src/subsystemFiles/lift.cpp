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
  if (master.get_digital_new_press(TOGGLE_LIFT_BUTTON)){
    lift_state = -lift_state;
    setLiftMotor(lift_state * 100);
  }
  return lift_state;
  //int p = 127 * (master.get_digital(DIGITAL_L1) - master.get_digital(DIGITAL_L2));
  //setLiftMotor(p);
}

int controlSetMiniLift(){
  if (master.get_digital_new_press(TOGGLE_MINI_LIFT_BUTTON)){
    mini_lift_state = -mini_lift_state;
    setMiniLiftMotor(mini_lift_state * 100);
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
