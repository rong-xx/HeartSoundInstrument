#include "Bcat_circle_pro_2.h"


static lv_obj_t* bg_circle_pro_2;
bool bcat_circle_done_pro_2 = false;
int i_circle_pro_border_test_2 = 0;
static lv_obj_t* circle_pro_load_arc_2;
static lv_style_t circle_pro_style_arc_bg2;
static lv_style_t circle_pro_style_arc_indic2;
static lv_style_t circle_pro_2_style_line;
static lv_obj_t* circle_pro_2_bcat_line1;
static lv_obj_t* circle_pro_2_value_id;
lv_obj_t* label_value_1;


void bcat_creat_circle_pro_2(void)
{
	bg_circle_pro_2 = lv_obj_create(lv_scr_act(), NULL);
	lv_obj_clean_style_list(bg_circle_pro_2, LV_OBJ_PART_MAIN);
	lv_obj_set_style_local_bg_opa(bg_circle_pro_2, LV_OBJ_PART_MAIN, LV_STATE_DEFAULT, LV_OPA_COVER);
	lv_obj_set_style_local_bg_color(bg_circle_pro_2, LV_OBJ_PART_MAIN, LV_STATE_DEFAULT, BCAT_NW_PRINTER_NIGHT_C1);
	lv_obj_set_size(bg_circle_pro_2, LV_HOR_RES, LV_VER_RES);

    // circle_pro_load_arc_2 = lv_arc_create(lv_scr_act(), NULL);
    // lv_arc_set_start_angle(circle_pro_load_arc_2, 0);
    // lv_arc_set_end_angle(circle_pro_load_arc_2, 0);
    // lv_arc_set_bg_angles(circle_pro_load_arc_2, 0, 360);
    // lv_arc_set_rotation(circle_pro_load_arc_2, 360);
    // lv_obj_set_style_local_bg_color(circle_pro_load_arc_2, LV_OBJ_PART_MAIN, LV_STATE_DEFAULT, lv_color_hex(0x18232f));
    // lv_obj_set_size(circle_pro_load_arc_2, 267, 267);
    // lv_obj_set_click(circle_pro_load_arc_2, false);
    // lv_obj_align(circle_pro_load_arc_2, lv_scr_act(), LV_ALIGN_CENTER, 0, 0);
    // lv_style_init(&circle_pro_style_arc_indic2);
    // lv_style_set_line_width(&circle_pro_style_arc_indic2, LV_STATE_DEFAULT, 1);
    // lv_style_set_line_color(&circle_pro_style_arc_indic2, LV_STATE_DEFAULT, LV_COLOR_WHITE);
    // lv_style_init(&circle_pro_style_arc_bg2);
    // lv_style_set_bg_color(&circle_pro_style_arc_bg2, LV_STATE_DEFAULT, lv_color_hex(0x18232f));
    // lv_style_set_line_width(&circle_pro_style_arc_bg2, LV_STATE_DEFAULT, 1);
    // lv_style_set_line_color(&circle_pro_style_arc_bg2, LV_STATE_DEFAULT, lv_color_hex(0x18232f));
    // lv_obj_add_style(circle_pro_load_arc_2, LV_ARC_PART_INDIC, &circle_pro_style_arc_indic2);
    // lv_obj_add_style(circle_pro_load_arc_2, LV_ARC_PART_BG, &circle_pro_style_arc_bg2);
    // lv_style_set_border_width(&circle_pro_style_arc_bg2, LV_STATE_DEFAULT, i_circle_pro_border_test_2);
    // lv_arc_set_end_angle(circle_pro_load_arc_2, 360);

    lv_style_init(&circle_pro_2_style_line);
    lv_style_set_line_width(&circle_pro_2_style_line, LV_STATE_DEFAULT, 4);
    lv_style_set_line_color(&circle_pro_2_style_line, LV_STATE_DEFAULT, BCAT_NW_LINE_LIGHT_ORANGE);
    lv_style_set_line_rounded(&circle_pro_2_style_line, LV_STATE_DEFAULT, true);

    lv_coord_t unit_w = LV_HOR_RES / 4;
    static lv_point_t circle_pro_2_points_1[] = { {0, unit_w}, {LV_HOR_RES, unit_w} };
    circle_pro_2_bcat_line1 = lv_line_create(lv_scr_act(), NULL);
    lv_line_set_points(circle_pro_2_bcat_line1, circle_pro_2_points_1, 2);
    lv_obj_add_style(circle_pro_2_bcat_line1, LV_LINE_PART_MAIN, &circle_pro_2_style_line);
    
    lv_obj_t* label_title_1 = lv_label_create(lv_scr_act(), NULL);
    lv_label_set_long_mode(label_title_1, LV_LABEL_LONG_SROLL_CIRC);
    lv_label_set_align(label_title_1, LV_LABEL_ALIGN_CENTER);
    lv_obj_set_size(label_title_1, LV_HOR_RES, unit_w);
    lv_obj_align(label_title_1, lv_scr_act(), LV_ALIGN_IN_TOP_LEFT, 0, 22);
    lv_obj_set_style_local_text_color(label_title_1, LV_BTN_PART_MAIN, LV_STATE_DEFAULT, LV_COLOR_WHITE);
    lv_obj_set_style_local_text_opa(label_title_1, LV_BTN_PART_MAIN, LV_STATE_DEFAULT, 255);
    lv_obj_set_style_local_text_font(label_title_1, LV_BTN_PART_MAIN, LV_STATE_DEFAULT, &bcat_font_circle_big_);
    lv_obj_set_style_local_border_width(label_title_1, LV_BTN_PART_MAIN, LV_STATE_DEFAULT, i_circle_pro_border_test_2);
    lv_obj_set_style_local_border_color(label_title_1, LV_BTN_PART_MAIN, LV_STATE_DEFAULT, LV_COLOR_WHITE);
    lv_label_set_text(label_title_1, "心音仪");

    label_value_1 = lv_label_create(lv_scr_act(), NULL);
    lv_label_set_long_mode(label_value_1, LV_LABEL_LONG_SROLL_CIRC);
    lv_label_set_align(label_value_1, LV_LABEL_ALIGN_CENTER);
    lv_obj_set_size(label_value_1, LV_HOR_RES, unit_w);
    lv_obj_align(label_value_1, lv_scr_act(), LV_ALIGN_IN_TOP_LEFT, 0, unit_w + 10);
    lv_obj_set_style_local_text_color(label_value_1, LV_BTN_PART_MAIN, LV_STATE_DEFAULT, LV_COLOR_RED);
    lv_obj_set_style_local_text_opa(label_value_1, LV_BTN_PART_MAIN, LV_STATE_DEFAULT, 255);
    lv_obj_set_style_local_text_font(label_value_1, LV_BTN_PART_MAIN, LV_STATE_DEFAULT, &bcat_font_circle_big_);
    lv_obj_set_style_local_border_width(label_value_1, LV_BTN_PART_MAIN, LV_STATE_DEFAULT, i_circle_pro_border_test_2);
    lv_obj_set_style_local_border_color(label_value_1, LV_BTN_PART_MAIN, LV_STATE_DEFAULT, LV_COLOR_WHITE);
    lv_label_set_text(label_value_1, "Press To Start:");
    
    circle_pro_2_value_id = lv_label_create(lv_scr_act(), NULL);
    lv_label_set_long_mode(circle_pro_2_value_id, LV_LABEL_LONG_SROLL_CIRC);
    lv_label_set_align(circle_pro_2_value_id, LV_LABEL_ALIGN_CENTER);
    lv_obj_set_size(circle_pro_2_value_id, LV_HOR_RES, unit_w);
    lv_obj_align(circle_pro_2_value_id, lv_scr_act(), LV_ALIGN_IN_TOP_LEFT, 0, unit_w * 2 - 20);
    lv_obj_set_style_local_text_color(circle_pro_2_value_id, LV_BTN_PART_MAIN, LV_STATE_DEFAULT, LV_COLOR_WHITE);
    lv_obj_set_style_local_text_opa(circle_pro_2_value_id, LV_BTN_PART_MAIN, LV_STATE_DEFAULT, 255);
    lv_obj_set_style_local_text_font(circle_pro_2_value_id, LV_BTN_PART_MAIN, LV_STATE_DEFAULT, &bcat_font_circle_big_);
    lv_obj_set_style_local_border_width(circle_pro_2_value_id, LV_BTN_PART_MAIN, LV_STATE_DEFAULT, i_circle_pro_border_test_2);
    lv_obj_set_style_local_border_color(circle_pro_2_value_id, LV_BTN_PART_MAIN, LV_STATE_DEFAULT, LV_COLOR_WHITE);
    lv_label_set_text(circle_pro_2_value_id, "仪器ID: 14581412");

    lv_obj_t* circle_pro_2_school = lv_label_create(lv_scr_act(), NULL);
    lv_label_set_long_mode(circle_pro_2_school, LV_LABEL_LONG_BREAK);
    lv_label_set_align(circle_pro_2_school, LV_LABEL_ALIGN_CENTER);
    lv_obj_set_size(circle_pro_2_school, LV_HOR_RES, unit_w * 2);
    lv_obj_align(circle_pro_2_school, lv_scr_act(), LV_ALIGN_IN_TOP_LEFT, 0, unit_w * 2 + 13);
    lv_obj_set_style_local_text_color(circle_pro_2_school, LV_BTN_PART_MAIN, LV_STATE_DEFAULT, LV_COLOR_GRAY);
    lv_obj_set_style_local_text_opa(circle_pro_2_school, LV_BTN_PART_MAIN, LV_STATE_DEFAULT, 255);
    lv_obj_set_style_local_text_font(circle_pro_2_school, LV_BTN_PART_MAIN, LV_STATE_DEFAULT, &bcat_font_circle_big_);
    lv_obj_set_style_local_border_width(circle_pro_2_school, LV_BTN_PART_MAIN, LV_STATE_DEFAULT, i_circle_pro_border_test_2);
    lv_obj_set_style_local_border_color(circle_pro_2_school, LV_BTN_PART_MAIN, LV_STATE_DEFAULT, LV_COLOR_WHITE);
    lv_label_set_text(circle_pro_2_school, "吉林大学仪器科学与电气工程学院");    
   
    lv_obj_t* circle_pro_2_school_2 = lv_label_create(lv_scr_act(), NULL);
    lv_label_set_long_mode(circle_pro_2_school_2, LV_LABEL_LONG_BREAK);
    lv_label_set_align(circle_pro_2_school_2, LV_LABEL_ALIGN_CENTER);
    lv_obj_set_size(circle_pro_2_school_2, LV_HOR_RES, unit_w * 2);
    lv_obj_align(circle_pro_2_school_2, lv_scr_act(), LV_ALIGN_IN_BOTTOM_MID, 0, -35);
    lv_obj_set_style_local_text_color(circle_pro_2_school_2, LV_BTN_PART_MAIN, LV_STATE_DEFAULT, LV_COLOR_GRAY);
    lv_obj_set_style_local_text_opa(circle_pro_2_school_2, LV_BTN_PART_MAIN, LV_STATE_DEFAULT, 255);
    lv_obj_set_style_local_text_font(circle_pro_2_school_2, LV_BTN_PART_MAIN, LV_STATE_DEFAULT, &bcat_font_circle_big_);
    lv_obj_set_style_local_border_width(circle_pro_2_school_2, LV_BTN_PART_MAIN, LV_STATE_DEFAULT, i_circle_pro_border_test_2);
    lv_obj_set_style_local_border_color(circle_pro_2_school_2, LV_BTN_PART_MAIN, LV_STATE_DEFAULT, LV_COLOR_WHITE);
    lv_label_set_text(circle_pro_2_school_2, "医疗仪器研究室");    


    bcat_circle_done_pro_2 = true;
}

void bcat_circle_pro_2_noready()
{
    bcat_circle_done_pro_2 = false;
}

bool bcat_circle_pro_2_done()
{
    return bcat_circle_done_pro_2;
}

void bcat_set_value_id(uint32_t id)
{
    if (!bcat_circle_done_pro_2) return;
    lv_label_set_text_fmt(circle_pro_2_value_id, "仪器ID: %u", id);
}

void setLabelText(const char* text) {
    lv_label_set_text_fmt(label_value_1, text);
}