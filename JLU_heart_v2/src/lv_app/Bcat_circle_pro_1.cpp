#include "Bcat_circle_pro_1.h"

static lv_obj_t *bg_circle_pro_1;
bool bcat_circle_done_pro_1 = false;
int i_circle_pro_border_test_1 = 0;
static lv_obj_t *circle_pro_load_arc_1;
static lv_style_t circle_pro_style_arc_bg1;
static lv_style_t circle_pro_style_arc_indic1;

static lv_style_t circle_pro_1_style_line;
static lv_obj_t *circle_pro_1_bcat_line1;
static lv_obj_t *circle_pro_1_bcat_line2;
static lv_obj_t *circle_pro_1_bcat_line3;
static lv_obj_t *circle_pro_1_heart_icon;

static void circle_pro_1_heart_task(lv_task_t *t);
static lv_task_t * task = nullptr;
int g_heart_zoom = 256;
int g_heart_unit = 20;
lv_obj_t* label_value_11;
lv_obj_t* label_value_2;

void bcat_creat_circle_pro_1(void)
{
  bg_circle_pro_1 = lv_obj_create(lv_scr_act(), NULL);
  lv_obj_clean_style_list(bg_circle_pro_1, LV_OBJ_PART_MAIN);
  lv_obj_set_style_local_bg_opa(bg_circle_pro_1, LV_OBJ_PART_MAIN, LV_STATE_DEFAULT, LV_OPA_COVER);
  lv_obj_set_style_local_bg_color(bg_circle_pro_1, LV_OBJ_PART_MAIN, LV_STATE_DEFAULT, BCAT_NW_PRINTER_NIGHT_C1);
  lv_obj_set_size(bg_circle_pro_1, LV_HOR_RES, LV_VER_RES);

  // circle_pro_load_arc_1 = lv_arc_create(lv_scr_act(), NULL);
  // lv_arc_set_start_angle(circle_pro_load_arc_1, 0);
  // lv_arc_set_end_angle(circle_pro_load_arc_1, 0);
  // lv_arc_set_bg_angles(circle_pro_load_arc_1, 0, 360);
  // lv_arc_set_rotation(circle_pro_load_arc_1, 360);
  // lv_obj_set_style_local_bg_color(circle_pro_load_arc_1, LV_OBJ_PART_MAIN, LV_STATE_DEFAULT, lv_color_hex(0x18232f));
  // lv_obj_set_size(circle_pro_load_arc_1, 267, 267);
  // lv_obj_set_click(circle_pro_load_arc_1, false);
  // lv_obj_align(circle_pro_load_arc_1, lv_scr_act(), LV_ALIGN_CENTER, 0, 0);
  // lv_style_init(&circle_pro_style_arc_indic1);
  // lv_style_set_line_width(&circle_pro_style_arc_indic1, LV_STATE_DEFAULT, 1);
  // lv_style_set_line_color(&circle_pro_style_arc_indic1, LV_STATE_DEFAULT, LV_COLOR_WHITE);
  // lv_style_init(&circle_pro_style_arc_bg1);
  // lv_style_set_bg_color(&circle_pro_style_arc_bg1, LV_STATE_DEFAULT, lv_color_hex(0x18232f));
  // lv_style_set_line_width(&circle_pro_style_arc_bg1, LV_STATE_DEFAULT, 1);
  // lv_style_set_line_color(&circle_pro_style_arc_bg1, LV_STATE_DEFAULT, lv_color_hex(0x18232f));
  // lv_obj_add_style(circle_pro_load_arc_1, LV_ARC_PART_INDIC, &circle_pro_style_arc_indic1);
  // lv_obj_add_style(circle_pro_load_arc_1, LV_ARC_PART_BG, &circle_pro_style_arc_bg1);
  // lv_style_set_border_width(&circle_pro_style_arc_bg1, LV_STATE_DEFAULT, i_circle_pro_border_test_1);
  // lv_arc_set_end_angle(circle_pro_load_arc_1, 360);

  lv_style_init(&circle_pro_1_style_line);
  lv_style_set_line_width(&circle_pro_1_style_line, LV_STATE_DEFAULT, 4);
  lv_style_set_line_color(&circle_pro_1_style_line, LV_STATE_DEFAULT, BCAT_NW_LINE_LIGHT_ORANGE);
  lv_style_set_line_rounded(&circle_pro_1_style_line, LV_STATE_DEFAULT, true);

  lv_coord_t unit_w = LV_HOR_RES / 4;
  static lv_point_t circle_pro_1_points_1[] = {{0, unit_w}, {LV_HOR_RES, unit_w}};
  circle_pro_1_bcat_line1 = lv_line_create(lv_scr_act(), NULL);
  lv_line_set_points(circle_pro_1_bcat_line1, circle_pro_1_points_1, 2);
  lv_obj_add_style(circle_pro_1_bcat_line1, LV_LINE_PART_MAIN, &circle_pro_1_style_line);

  static lv_point_t circle_pro_1_points_2[] = {{0, unit_w * 3}, {LV_HOR_RES, unit_w * 3}};
  circle_pro_1_bcat_line2 = lv_line_create(lv_scr_act(), NULL);
  lv_line_set_points(circle_pro_1_bcat_line2, circle_pro_1_points_2, 2);
  lv_obj_add_style(circle_pro_1_bcat_line2, LV_LINE_PART_MAIN, &circle_pro_1_style_line);

  // static lv_point_t circle_pro_1_points_3[] = {{LV_HOR_RES / 2, unit_w}, {LV_HOR_RES / 2, unit_w * 3}};
  // circle_pro_1_bcat_line3 = lv_line_create(lv_scr_act(), NULL);
  // lv_line_set_points(circle_pro_1_bcat_line3, circle_pro_1_points_3, 2);
  // lv_obj_add_style(circle_pro_1_bcat_line3, LV_LINE_PART_MAIN, &circle_pro_1_style_line);

  lv_obj_t *label_title_1 = lv_label_create(lv_scr_act(), NULL);
  lv_label_set_long_mode(label_title_1, LV_LABEL_LONG_SROLL_CIRC);
  lv_label_set_align(label_title_1, LV_LABEL_ALIGN_CENTER);
  lv_obj_set_size(label_title_1, LV_HOR_RES, unit_w);
  lv_obj_align(label_title_1, lv_scr_act(), LV_ALIGN_IN_TOP_LEFT, 0, 22);
  lv_obj_set_style_local_text_color(label_title_1, LV_BTN_PART_MAIN, LV_STATE_DEFAULT, LV_COLOR_WHITE);
  lv_obj_set_style_local_text_opa(label_title_1, LV_BTN_PART_MAIN, LV_STATE_DEFAULT, 255);
  lv_obj_set_style_local_text_font(label_title_1, LV_BTN_PART_MAIN, LV_STATE_DEFAULT, &bcat_font_circle_big_);
  lv_obj_set_style_local_border_width(label_title_1, LV_BTN_PART_MAIN, LV_STATE_DEFAULT, i_circle_pro_border_test_1);
  lv_obj_set_style_local_border_color(label_title_1, LV_BTN_PART_MAIN, LV_STATE_DEFAULT, LV_COLOR_WHITE);
  lv_label_set_text(label_title_1, "心音异常识别");

  lv_obj_t *label_title_2 = lv_label_create(lv_scr_act(), NULL);
  lv_label_set_long_mode(label_title_2, LV_LABEL_LONG_SROLL_CIRC);
  lv_label_set_align(label_title_2, LV_LABEL_ALIGN_CENTER);
  lv_obj_set_size(label_title_2, LV_HOR_RES / 2, unit_w);
  lv_obj_align(label_title_2, lv_scr_act(), LV_ALIGN_IN_TOP_LEFT, 0, unit_w + 11);
  lv_obj_set_style_local_text_color(label_title_2, LV_BTN_PART_MAIN, LV_STATE_DEFAULT, LV_COLOR_WHITE);
  lv_obj_set_style_local_text_opa(label_title_2, LV_BTN_PART_MAIN, LV_STATE_DEFAULT, 255);
  lv_obj_set_style_local_text_font(label_title_2, LV_BTN_PART_MAIN, LV_STATE_DEFAULT, &bcat_font_circle_big_);
  lv_obj_set_style_local_border_width(label_title_2, LV_BTN_PART_MAIN, LV_STATE_DEFAULT, i_circle_pro_border_test_1);
  lv_obj_set_style_local_border_color(label_title_2, LV_BTN_PART_MAIN, LV_STATE_DEFAULT, LV_COLOR_WHITE);
  lv_label_set_text(label_title_2, "识别结果:");

  lv_obj_t *label_title_3 = lv_label_create(lv_scr_act(), NULL);
  lv_label_set_long_mode(label_title_3, LV_LABEL_LONG_SROLL_CIRC);
  lv_label_set_align(label_title_3, LV_LABEL_ALIGN_CENTER);
  lv_obj_set_size(label_title_3, LV_HOR_RES / 2, unit_w);
  lv_obj_align(label_title_3, lv_scr_act(), LV_ALIGN_IN_TOP_LEFT, LV_HOR_RES / 2, unit_w + 11);
  lv_obj_set_style_local_text_color(label_title_3, LV_BTN_PART_MAIN, LV_STATE_DEFAULT, LV_COLOR_WHITE);
  lv_obj_set_style_local_text_opa(label_title_3, LV_BTN_PART_MAIN, LV_STATE_DEFAULT, 255);
  lv_obj_set_style_local_text_font(label_title_3, LV_BTN_PART_MAIN, LV_STATE_DEFAULT, &bcat_font_circle_big_);
  lv_obj_set_style_local_border_width(label_title_3, LV_BTN_PART_MAIN, LV_STATE_DEFAULT, i_circle_pro_border_test_1);
  lv_obj_set_style_local_border_color(label_title_3, LV_BTN_PART_MAIN, LV_STATE_DEFAULT, LV_COLOR_WHITE);
  lv_label_set_text(label_title_3, "心率:");

  label_value_11 = lv_label_create(lv_scr_act(), NULL);
  lv_label_set_long_mode(label_value_11, LV_LABEL_LONG_SROLL_CIRC);
  lv_label_set_align(label_value_11, LV_LABEL_ALIGN_CENTER);
  lv_obj_set_size(label_value_11, LV_HOR_RES / 2, unit_w);
  lv_obj_align(label_value_11, lv_scr_act(), LV_ALIGN_IN_TOP_LEFT, 0, LV_HOR_RES / 2 + 0);
  lv_obj_set_style_local_text_color(label_value_11, LV_BTN_PART_MAIN, LV_STATE_DEFAULT, LV_COLOR_RED);
  lv_obj_set_style_local_text_opa(label_value_11, LV_BTN_PART_MAIN, LV_STATE_DEFAULT, 255);
  lv_obj_set_style_local_text_font(label_value_11, LV_BTN_PART_MAIN, LV_STATE_DEFAULT, &bcat_font_circle_value_big_);
  lv_obj_set_style_local_border_width(label_value_11, LV_BTN_PART_MAIN, LV_STATE_DEFAULT, i_circle_pro_border_test_1);
  lv_obj_set_style_local_border_color(label_value_11, LV_BTN_PART_MAIN, LV_STATE_DEFAULT, LV_COLOR_WHITE);
  lv_label_set_text(label_value_11, "异常");

  label_value_2 = lv_label_create(lv_scr_act(), NULL);
  lv_label_set_long_mode(label_value_2, LV_LABEL_LONG_SROLL_CIRC);
  lv_label_set_align(label_value_2, LV_LABEL_ALIGN_CENTER);
  lv_obj_set_size(label_value_2, LV_HOR_RES / 2, unit_w);
  lv_obj_align(label_value_2, lv_scr_act(), LV_ALIGN_IN_TOP_LEFT, LV_HOR_RES / 2, LV_HOR_RES / 2 + 0);
  lv_obj_set_style_local_text_color(label_value_2, LV_BTN_PART_MAIN, LV_STATE_DEFAULT, LV_COLOR_RED);
  lv_obj_set_style_local_text_opa(label_value_2, LV_BTN_PART_MAIN, LV_STATE_DEFAULT, 255);
  lv_obj_set_style_local_text_font(label_value_2, LV_BTN_PART_MAIN, LV_STATE_DEFAULT, &bcat_font_circle_value_big_);
  lv_obj_set_style_local_border_width(label_value_2, LV_BTN_PART_MAIN, LV_STATE_DEFAULT, i_circle_pro_border_test_1);
  lv_obj_set_style_local_border_color(label_value_2, LV_BTN_PART_MAIN, LV_STATE_DEFAULT, LV_COLOR_WHITE);
  lv_label_set_text(label_value_2, "0");

  lv_obj_t *label_unit_2 = lv_label_create(lv_scr_act(), NULL);
  lv_label_set_long_mode(label_unit_2, LV_LABEL_LONG_SROLL_CIRC);
  lv_label_set_align(label_unit_2, LV_LABEL_ALIGN_LEFT);
  lv_obj_set_size(label_unit_2, LV_HOR_RES / 2, unit_w);
  lv_obj_align(label_unit_2, lv_scr_act(), LV_ALIGN_IN_TOP_LEFT, LV_HOR_RES - 20, LV_HOR_RES / 2 + 8);
  lv_obj_set_style_local_text_color(label_unit_2, LV_BTN_PART_MAIN, LV_STATE_DEFAULT, LV_COLOR_WHITE);
  lv_obj_set_style_local_text_opa(label_unit_2, LV_BTN_PART_MAIN, LV_STATE_DEFAULT, 255);
  lv_obj_set_style_local_text_font(label_unit_2, LV_BTN_PART_MAIN, LV_STATE_DEFAULT, &bcat_font_circle_small_);
  lv_obj_set_style_local_border_width(label_unit_2, LV_BTN_PART_MAIN, LV_STATE_DEFAULT, i_circle_pro_border_test_1);
  lv_obj_set_style_local_border_color(label_unit_2, LV_BTN_PART_MAIN, LV_STATE_DEFAULT, LV_COLOR_WHITE);
  lv_label_set_text(label_unit_2, " ");

  lv_obj_t *cont_logo = lv_cont_create(lv_scr_act(), NULL);
  lv_obj_set_size(cont_logo, unit_w - 15, unit_w - 15);
  lv_obj_clean_style_list(cont_logo, LV_CONT_PART_MAIN);
  lv_obj_align(cont_logo, lv_scr_act(), LV_ALIGN_IN_BOTTOM_MID, 0, -10);
  circle_pro_1_heart_icon = lv_img_create(cont_logo, NULL);
  lv_img_set_src(circle_pro_1_heart_icon, &bcat_heart_32);
  lv_obj_align_origo(circle_pro_1_heart_icon, NULL, LV_ALIGN_CENTER, 0, 0);
  lv_img_set_zoom(circle_pro_1_heart_icon, g_heart_zoom);
  lv_obj_set_style_local_border_width(cont_logo, LV_BTN_PART_MAIN, LV_STATE_DEFAULT, i_circle_pro_border_test_1);
  lv_obj_set_style_local_border_color(cont_logo, LV_BTN_PART_MAIN, LV_STATE_DEFAULT, LV_COLOR_WHITE);

  bcat_circle_done_pro_1 = true;
  task = lv_task_create(circle_pro_1_heart_task, 30, LV_TASK_PRIO_LOWEST, bg_circle_pro_1);
}

void circle_pro_1_heart_task(lv_task_t *t)
{
  if (g_heart_zoom < 220 || g_heart_zoom > 400)
    g_heart_unit = -g_heart_unit;
  g_heart_zoom -= g_heart_unit;
  lv_img_set_zoom(circle_pro_1_heart_icon, g_heart_zoom);
}

void bcat_circle_pro_1_noready()
{
  bcat_circle_done_pro_1 = false;
}

bool bcat_circle_pro_1_done()
{
  
  return bcat_circle_done_pro_1;
}

void bcat_reset_heart()
{
  lv_task_del(task);
  g_heart_zoom = 256;
  g_heart_unit = 20;
}

void set_value_1(int peaks)
{
    if (!bcat_circle_done_pro_1) return;
    if (peaks >= 55 && peaks <= 110){
      lv_label_set_text_fmt(label_value_11, "正常");
    }
    else{
      lv_label_set_text_fmt(label_value_11, "异常");
    }

}

void set_value_2(int hr)
{
    if (!bcat_circle_done_pro_1) return;
    lv_label_set_text_fmt(label_value_2, "%d", hr);
}