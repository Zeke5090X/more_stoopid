#include "main.h"
using namespace okapi;
auto chassis2 = ChassisControllerFactory::create(
{1, 2}, {-3, -4},
AbstractMotor::gearset::green,
{4_in, 15_in}
);
void autonr2()
{
  deploy();
  chassis2.setMaxVelocity(50);
  chassis2.moveDistance(-18_in);
  pros::delay(3000);
  chassis2.moveDistance(9_in);
}
