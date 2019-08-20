#include "main.h"
#include "okapi/api.hpp"

using namespace okapi;

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

const double liftP = 1.0;
const double liftI = 0.001;
const double liftD = 0.1;

void autonomous() {
  auto chassis = ChassisControllerFactory::create(
    {LEFT_WHEELS_PORT1,LEFT_WHEELS_PORT2}, //Left motors
    {RIGHT_WHEELS_PORT1,RIGHT_WHEELS_PORT2}, //Right motors
    AbstractMotor::gearset::green, //Gearset (200rpm)
    {4.125_in, 12.5_in} //Wheel size, wheelbase width
  );

  //TODO profile robot to determine actual values for this
  auto profileController = AsyncControllerFactory::motionProfile(
    1.0, //Max linear velocity
    2.0, //Max linear acceleration
    10.0, //Max linear jerk
    chassis //Chassis controller
  );

  auto liftController = AsyncControllerFactory::posPID(ARM_PORT, liftP, liftI, liftD); //Max 270 degrees

  //Sample movement Code
  profileController.generatePath({
    Point{0_m, 0_m, 0_deg},
    Point{1_m, 0_m, 90_deg}},
    "Test"
  );

  profileController.setTarget("TEST");
  profileController.waitUntilSettled();
  liftController.setTarget(270);
}
