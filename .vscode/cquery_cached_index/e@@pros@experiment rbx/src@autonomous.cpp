#include "main.h"

/**
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
 */

 //Subject to change
 #define RIGHT_WHEELS_PORT1 1
 #define RIGHT_WHEELS_PORT2 2
 #define LEFT_WHEELS_PORT1 3
 #define LEFT_WHEELS_PORT2 4
 #define ARM_PORT 7
 #define INTAKE_PORT1 5
 #define INTAKE_PORT2 6

void autonomous() {
  pros::Controller master(pros::E_CONTROLLER_MASTER);
  pros::Motor left_motor1(LEFT_WHEELS_PORT1);
  pros::Motor left_motor2(LEFT_WHEELS_PORT2);
  pros::Motor right_motor1(RIGHT_WHEELS_PORT1,true);
  pros::Motor right_motor2(RIGHT_WHEELS_PORT2,true);
  pros::Motor arm (ARM_PORT);
  pros::Motor intake1 (INTAKE_PORT1);
  pros::Motor intake2 (INTAKE_PORT2);

  
}
