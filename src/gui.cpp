#include "main.h"
void gui(){
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