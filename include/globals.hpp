#pragma once
#include "okapi/api.hpp"
//red start 1 preset prototypes
void autonr1();
void autonr2();
void autonr3();
void autonr4();
void autonr5();
void autonr6();
//red start 2 preset prototypes
void autonr7();
void autonr8();
void autonr9();
void autonr10();
void autonr11();
void autonr12();

//blue start 1 preset prototypes
void autonb1();
void autonb2();
void autonb3();
void autonb4();
void autonb5();
void autonb6();
//blue start 2 preset prototypes
void autonb7();
void autonb8();
void autonb9();
void autonb10();
void autonb11();
void autonb12();

//no preset
void noauton();

void TAP();

//deploy
void deploy();

extern int autonpreset;

//okapi
//extern const auto &ref1;
//extern okapi::MotorGroup left_drive;
//extern okapi::MotorGroup right_drive;
extern okapi::MotorGroup intakes;
extern pros::Controller slave;
//extern okapi::Motor li;
//extern okapi::Motor ri;
extern okapi::Motor a;
extern okapi::Motor t;
extern bool arcade;

