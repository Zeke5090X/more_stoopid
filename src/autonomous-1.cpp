#include "main.h"
using namespace okapi;
auto chassisb1 = ChassisControllerFactory::create(
{1, 2}, {-3, -4},
AbstractMotor::gearset::green,
{4.1_in, 15_in}
);
void autonb1()
{
    deploy();
    intakes.moveVoltage(12000);
    chassisb1.setMaxVelocity(50);
    chassisb1.moveDistance(28_in);
    pros::delay(1600);
    chassisb1.setMaxVelocity(100);
    chassisb1.moveDistance(-27_in);
    pros::delay(700);
    chassisb1.turnAngle(-90_deg);
    pros::delay(500);
    chassisb1.moveDistance(6_in);
    pros::delay(500);
    intakes.moveVelocity(-20);
    t.moveRelative(448, 30);
    pros::delay(500);
    chassisb1.moveDistance(3_in);
}