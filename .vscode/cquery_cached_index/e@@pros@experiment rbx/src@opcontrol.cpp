#include "main.h"

/**
 * Runs the operator control code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the operator
 * control mode.
 *
 * If no competition control is connected, this function will run immediately
 * following initialize().
 *
 * If the robot is disabled or communications is lost, the
 * operator control task will be stopped. Re-enabling the robot will restart the
 * task, not resume it from where it left off.
 */

//Port 1,10,12 broken

//Subject to change
#define RIGHT_WHEELS_PORT1 13
#define RIGHT_WHEELS_PORT2 2
#define LEFT_WHEELS_PORT1 3
#define LEFT_WHEELS_PORT2 4
#define ARM_PORT 7
#define INTAKE_PORT1 5
#define INTAKE_PORT2 6
#define TRAY_PORT 11

void opcontrol() {
	pros::lcd::set_text(1, "Op!");
	std::cout << "op";
	pros::Controller master(pros::E_CONTROLLER_MASTER);
	pros::Motor left_motor1(LEFT_WHEELS_PORT1);
	pros::Motor left_motor2(LEFT_WHEELS_PORT2);
	pros::Motor right_motor1(RIGHT_WHEELS_PORT1,true);
	pros::Motor right_motor2(RIGHT_WHEELS_PORT2,true);
	pros::Motor arm (ARM_PORT);
	pros::Motor intake1 (INTAKE_PORT1,true);
	pros::Motor intake2 (INTAKE_PORT2);
	pros::Motor tray (TRAY_PORT);
	while (true) {
		std::cout << master.get_analog(ANALOG_LEFT_Y);
		left_motor1.move(master.get_analog(ANALOG_LEFT_Y));
		left_motor2.move(master.get_analog(ANALOG_LEFT_Y));
		right_motor1.move(master.get_analog(ANALOG_RIGHT_Y));
		right_motor2.move(master.get_analog(ANALOG_RIGHT_Y));
		if (master.get_digital(DIGITAL_R1)) {
			arm.move_velocity(200);
		}
		else if (master.get_digital(DIGITAL_R2)) {
			arm.move_velocity(-200);
		}
		else {
			arm.move_velocity(0);
		}
		if (master.get_digital(DIGITAL_L1)) {
			intake1.move_velocity(200);//Max rpm
			intake2.move_velocity(200);
		}
		else if (master.get_digital(DIGITAL_L2)) {
			intake1.move_velocity(-200);
			intake2.move_velocity(-200);
		}
		else {
	 		intake1.move_velocity(5);
			intake2.move_velocity(5);
		}
		if(master.get_digital(DIGITAL_X)) {
			tray.move_velocity(-30);
		}
		else if (master.get_digital(DIGITAL_B)) {
			tray.move_velocity(120);
		}
		else {
			tray.move_velocity(0);
		}
		pros::delay(10);
	}
}
