#include "main.h"
using namespace okapi;
Controller masterController;
MotorGroup left_drive({1, 2});
MotorGroup right_drive({-3, -4});
MotorGroup intakes({15, -16});
pros::Controller slave(pros::E_CONTROLLER_PARTNER);
auto drive = ChassisControllerFactory::create(
left_drive, 
right_drive,
AbstractMotor::gearset::green,
{4_in, 15_in}
);
//const auto &ref1 = drive;
/*Motor li(15,
		 false,
		 AbstractMotor::gearset::red,
		 AbstractMotor::encoderUnits::degrees);
Motor ri(16,
		 true,
		 AbstractMotor::gearset::red,
		 AbstractMotor::encoderUnits::degrees);*/
Motor a(12,
		true,
		AbstractMotor::gearset::red,
		AbstractMotor::encoderUnits::degrees);		
Motor t(13,
		true,
		AbstractMotor::gearset::red,
		AbstractMotor::encoderUnits::degrees);
/*ControllerButton intakef = masterController[ControllerDigital::R1];
ControllerButton intaker = masterController[ControllerDigital::R2];
ControllerButton intakers = masterController[ControllerDigital::L1];
ControllerButton intakeia = masterController[ControllerDigital::L2];*/
ControllerButton armup = masterController[ControllerDigital::up];
ControllerButton armdown = masterController[ControllerDigital::down];
ControllerButton tiltforward = masterController[ControllerDigital::right];
ControllerButton tiltback = masterController[ControllerDigital::left];
bool arcade = false;
int autonpreset = 2;
/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */

void initialize() 
{
	//gui();
	left_drive.setBrakeMode(AbstractMotor::brakeMode::coast);
	right_drive.setBrakeMode(AbstractMotor::brakeMode::coast);
	a.setBrakeMode(AbstractMotor::brakeMode::hold);
	intakes.setGearing(AbstractMotor::gearset::red);
	masterController.setText(2, 7, "Zeke is dum");
}

/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {}

/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */
void competition_initialize() {}

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
void autonomous() 
{
	if (autonpreset==0){}
	else if(autonpreset==1)
	{
		autonr1();
	}
	else if(autonpreset==2)
	{
		autonr2();
	}
	else{}
	
}

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
void opcontrol() {
	int state = 0;
	while (true) {
		if(arcade==true)
		{
		drive.arcade(masterController.getAnalog(ControllerAnalog::leftY),
            		 masterController.getAnalog(ControllerAnalog::rightX));	
		}
		else
		{
		 drive.tank(masterController.getAnalog(ControllerAnalog::leftY),
		 			masterController.getAnalog(ControllerAnalog::rightY));
		}
		if(state==0)
		{
			if(slave.get_digital_new_press(DIGITAL_R1))
			{
				state = 1;
			}
			if(slave.get_digital_new_press(DIGITAL_R2))
			{
				state = -1;
			}
			if(slave.get_digital_new_press(DIGITAL_L1))
			{
				state = -2;
			}
			intakes.moveVelocity(0);
		}
		else if(state==1)
		{
			if(slave.get_digital_new_press(DIGITAL_R2))
			{
				state = -1;
			}
			if(slave.get_digital_new_press(DIGITAL_L1))
			{
				state = -2;
			}
			if(slave.get_digital_new_press(DIGITAL_R1))
			{
				state = 0;
			}
			intakes.moveVoltage(12000);
		}
		else if(state==-1)
		{
			if(slave.get_digital_new_press(DIGITAL_R2))
			{
				state = 1;
			}
			if(slave.get_digital_new_press(DIGITAL_L1))
			{
				state = -2;
			}
			if(slave.get_digital_new_press(DIGITAL_R1))
			{
				state = 0;
			}
			intakes.moveVoltage(-12000);
		}
		else
		{
			if(slave.get_digital_new_press(DIGITAL_R1))
			{
				state = 1;
			}
			if(slave.get_digital_new_press(DIGITAL_R2))
			{
				state = -1;
			}
			if(slave.get_digital_new_press(DIGITAL_L1))
			{
				state = 0;
			}
			intakes.moveVelocity(-20);
		}
		if(slave.get_digital_new_press(DIGITAL_A))
		{
			t.moveRelative(448, 30);
		}
		if(slave.get_digital_new_press(DIGITAL_B))
		{
			t.moveRelative(-448, -60);
		}		
		if(tiltforward.isPressed())
		{
			t.moveVelocity(30);
		}
		else if(tiltback.isPressed())
		{
			t.moveVelocity(-60);
		}
		else
		{
			t.moveVelocity(0);
		}
		
		if(armup.isPressed())
		{
			a.moveVelocity(50);
		}
		else if(armdown.isPressed())
		{
			a.moveVelocity(-50);
		}
		else
		{
			a.moveVelocity(0);
		}
		
		pros::delay(20);
	}
}