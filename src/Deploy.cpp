#include "main.h"
void deploy()
{
    t.moveRelative(506, 100);
    pros::delay(1895);
    t.moveRelative(-337, -100);
    pros::delay(20);
    a.moveRelative(490, 50);
    pros::delay(2000);
    a.moveRelative(-490, -50);
    pros::delay(1500);
    t.moveRelative(-169, -100);
    pros::delay(15);
}