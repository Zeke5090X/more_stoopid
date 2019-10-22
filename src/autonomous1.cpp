#include "main.h"
using namespace okapi;
auto chassis1 = ChassisControllerFactory::create(
{1, 2}, {-3, -4},
AbstractMotor::gearset::green,
{4_in, 15_in}
);
void autonr1()
{
    //deploy();
    intakes.moveVoltage(12000);
    chassis1.setMaxVelocity(50);
    chassis1.moveDistance(24_in);
    pros::delay(1200);
    chassis1.setMaxVelocity(100);
    chassis1.moveDistance(-23_in);
    pros::delay(700);
    chassis1.turnAngle(90_deg);
    pros::delay(500);
    chassis1.moveDistance(6_in);
    pros::delay(500);
    intakes.moveVelocity(-20);
    t.moveRelative(448, 30);
}
