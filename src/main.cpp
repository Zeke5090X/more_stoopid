#include "main.h"
#include "lvgldefs.h"
using namespace okapi;
Controller masterController;
Controller partnerController;
auto drive = ChassisControllerFactory::create(
 {1, 2}, {-3, -4},
AbstractMotor::gearset::green,
{4_in, 10.5_in}
);
const int LI_MOTOR = 15;
const int RI_MOTOR = 14;
const int A_MOTOR = 12;
const int T_MOTOR = 13;
Motor li(LI_MOTOR);
Motor ri(RI_MOTOR);
Motor a(A_MOTOR);
Motor t(T_MOTOR);
//ControllerButton liftup(1, up, false);
bool arcade = true;
int auton = 0;
/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */

void initialize() 
{
	lv_style_t btn1_rel;
	lv_style_t btn1_pr;
	lv_style_t btn2_rel;
	lv_style_t btn2_pr;
	lv_style_t btn3_rel;
	lv_style_t btn3_pr;

	lv_obj_t * DSBTN;
	lv_obj_t * DSTXT;

	lv_obj_t * misctab;
	lv_obj_t * misctabbtn;
	lv_obj_t * misctabbtntxt;
	lv_obj_t * redstart1;
	lv_obj_t * redstart1btn;
	lv_obj_t * redstart1btntxt;
	lv_obj_t * redstart2;
	lv_obj_t * redstart2btn;
	lv_obj_t * redstart2btntxt;
	lv_obj_t * bluestart1;
	lv_obj_t * bluestart1btn;
	lv_obj_t * bluestart1btntxt;
	lv_obj_t * bluestart2;
	lv_obj_t * bluestart2btn;
	lv_obj_t * bluestart2btntxt;

	lv_style_copy(&btn1_rel, &lv_style_plain);
	btn1_rel.body.main_color = LV_COLOR_MAKE(255, 0, 0);
	btn1_rel.body.grad_color = LV_COLOR_MAKE(127, 0, 0);
	btn1_rel.body.radius = 1;
	btn1_rel.text.color = LV_COLOR_MAKE(255, 255, 255);

	lv_style_copy(&btn1_pr, &btn1_rel);
	btn1_pr.body.main_color = LV_COLOR_MAKE(127, 0, 0);
	btn1_pr.body.grad_color = LV_COLOR_MAKE(63, 0, 0);
	
	lv_style_copy(&btn2_rel, &lv_style_plain);
	btn1_rel.body.main_color = LV_COLOR_MAKE(0, 0, 255);
	btn1_rel.body.grad_color = LV_COLOR_MAKE(0, 0, 127);
	btn1_rel.body.radius = 1;
	btn1_rel.text.color = LV_COLOR_MAKE(255, 255, 255);

	lv_style_copy(&btn2_pr, &btn2_rel);
	btn1_pr.body.main_color = LV_COLOR_MAKE(0, 0, 127);
	btn1_pr.body.grad_color = LV_COLOR_MAKE(0, 0, 63);

	lv_style_copy(&btn3_rel, &lv_style_plain);
	btn1_rel.body.main_color = LV_COLOR_MAKE(255, 0, 0);
	btn1_rel.body.grad_color = LV_COLOR_MAKE(0, 0, 255);
	btn1_rel.body.radius = 1;
	btn1_rel.text.color = LV_COLOR_MAKE(255, 255, 255);

	lv_style_copy(&btn3_pr, &btn3_rel);
	btn1_pr.body.main_color = LV_COLOR_MAKE(127, 0, 0);
	btn1_pr.body.grad_color = LV_COLOR_MAKE(0, 0, 127);

	misctab = lv_page_create(lv_scr_act(), NULL);
	lv_obj_set_size(misctab, 1000, 500);
	lv_obj_set_pos(misctab, 0, 60);

	misctabbtn = lv_btn_create(lv_scr_act(), NULL);
	lv_obj_set_pos(misctabbtn, 0, 0);
	lv_obj_set_size(misctabbtn, 125, 50);
	lv_btn_set_style(misctabbtn, LV_BTN_STYLE_REL, &btn1_rel);
	lv_btn_set_style(misctabbtn, LV_BTN_STYLE_PR, &btn1_pr);

	misctabbtntxt = lv_label_create(misctabbtn, NULL);
	lv_label_set_text(misctabbtntxt, "MISC.");

	redstart1 = lv_page_create(lv_scr_act(), NULL);
	lv_obj_set_size(redstart1, 1000, 500);
	lv_obj_set_pos(redstart1, 0, 60);

	redstart1btn = lv_btn_create(lv_scr_act(), NULL);
	lv_obj_set_pos(redstart1btn, 135, 0);
	lv_obj_set_size(redstart1btn, 125, 50);
	lv_btn_set_style(redstart1btn, LV_BTN_STYLE_REL, &btn1_rel);
	lv_btn_set_style(redstart1btn, LV_BTN_STYLE_PR, &btn1_pr);

	redstart1btntxt = lv_label_create(redstart1btn, NULL);
	lv_label_set_text(redstart1btntxt, "RS1");

	redstart2 = lv_page_create(lv_scr_act(), NULL);
	lv_obj_set_size(redstart2, 1000, 500);
	lv_obj_set_pos(redstart2, 0, 60);
	
	redstart2btn = lv_btn_create(lv_scr_act(), NULL);
	lv_obj_set_pos(redstart2btn, 260, 0);
	lv_obj_set_size(redstart2btn, 125, 50);
	lv_btn_set_style(redstart2btn, LV_BTN_STYLE_REL, &btn1_rel);
	lv_btn_set_style(redstart2btn, LV_BTN_STYLE_PR, &btn1_pr);

	redstart2btntxt = lv_label_create(redstart2btn, NULL);
	lv_label_set_text(redstart2btntxt, "RS2");


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
	/*t.moveRelative(45, 60)override;
	pros::delay(10);
	t.moveRelative(45, 60)override;
	a.moveRelative(45, 60)override;
	pros::delay(10);
	a.moveRelative(-45, -60)override;
	pros::delay(10);
	li.moveVoltage(-12000)override;
	ri.moveVoltage(12000)override;
	pros::delay(2);
	void moveDistance(QLength 48in) override;
	void waitUntilSettled() override;
	li.moveVoltage(0)override;
	ri.moceVoltage(0)override;
	void moveDistance(QLength -47in) override;
	void waitUntilSettled() override;
	void turnAngle(float 90) override;
	void moveDistance(QLength 7in) override;
	void stop() override;
	t.moveAbsolute(45, 10) override;
	pros::delay(5);
	void moveDistance(QLength 4in) override;*/
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
		
		pros::delay(20);
	}
}
