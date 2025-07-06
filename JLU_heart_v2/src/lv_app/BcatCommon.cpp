#include "BcatCommon.h"

static int icurrent_id = 0;
bool g_bDay = true;
static lv_obj_t* label_mes = nullptr;
static void mes_task(lv_task_t* t);
static lv_task_t* bcat_task = nullptr;
int itime = 0;

void set_current_screen(int index)
{
    icurrent_id = index;
}

int get_current_screen()
{
    return icurrent_id;
}

void bcat_screen_out_all(lv_obj_t* obj, uint32_t delay)
{
    if (bcat_task != nullptr)
    {  
        lv_task_del(bcat_task);
        bcat_task = nullptr;
    }

    if (label_mes != nullptr)
    {
        lv_obj_del(label_mes);
        label_mes = nullptr;
    }

    lv_obj_t* child = lv_obj_get_child_back(obj, NULL);
    while (child)
    {
        lv_obj_del(child);
        child = lv_obj_get_child_back(obj, child);
    }
}

void bcat_screen_out_all_anim(lv_obj_t* obj, uint32_t delay)
{
    if (bcat_task != nullptr)
    {  
        lv_task_del(bcat_task);
        bcat_task = nullptr;
    }

    if (label_mes != nullptr)
    {
        lv_obj_del(label_mes);
        label_mes = nullptr;
    }
    
    lv_obj_t* child = lv_obj_get_child_back(obj, NULL);
    while (child)
    {
        if (child == label_mes)
        {
            continue;
        }

        lv_anim_t a;
        lv_anim_init(&a);
        lv_anim_set_var(&a, child);
        lv_anim_set_time(&a, BCAT_NW_ANIM_TIME);
        lv_anim_set_delay(&a, delay);
        lv_anim_set_exec_cb(&a, (lv_anim_exec_xcb_t)lv_obj_set_y);
        if (lv_obj_get_y(child) < 120) {
            lv_anim_set_values(&a, lv_obj_get_y(child),
                lv_obj_get_y(child) - BCAT_NW_ANIM_Y);
        }
        else {
            lv_anim_set_values(&a, lv_obj_get_y(child),
                lv_obj_get_y(child) + BCAT_NW_ANIM_Y);

            delay += BCAT_NW_ANIM_DELAY;
        }
        lv_anim_set_ready_cb(&a, lv_obj_del_anim_ready_cb);
        lv_anim_start(&a);
        child = lv_obj_get_child_back(obj, child);
    }
}

bool is_day()
{
    return g_bDay;
}

void set_day(bool bday)
{
    g_bDay = bday;
}

lv_color_t bcat_get_color_bg()
{
    return g_bDay ? BCAT_NW_PRINTER_DAY_C1 : BCAT_NW_PRINTER_NIGHT_C1;
}

lv_color_t bcat_get_color_title_box()
{
    return g_bDay ? BCAT_NW_PRINTER_DAY_C5 : BCAT_NW_PRINTER_NIGHT_C5;
}

lv_color_t bcat_get_color_clock_box()
{
    return g_bDay ? BCAT_NW_PRINTER_DAY_C2 : BCAT_NW_PRINTER_NIGHT_C2;
}

lv_color_t bcat_get_color_weather_box()
{
    return g_bDay ? BCAT_NW_PRINTER_DAY_C4 : BCAT_NW_PRINTER_NIGHT_C4;
}

lv_color_t bcat_get_color_text()
{
    return g_bDay ? BCAT_NW_PRINTER_DAY_C8 : BCAT_NW_PRINTER_NIGHT_C8;
}

lv_color_t bcat_get_color_line()
{
    return g_bDay ? BCAT_NW_PRINTER_DAY_C8 : BCAT_NW_PRINTER_NIGHT_C8;
}

lv_color_t bcat_get_color_apm()
{
    return g_bDay ? BCAT_NW_PRINTER_DAY_C7 : BCAT_NW_PRINTER_NIGHT_C7;
}

lv_color_t bcat_get_color_week()
{
    return g_bDay ? BCAT_NW_PRINTER_DAY_C6 : BCAT_NW_PRINTER_NIGHT_C6;
}

void show_mes(int index)
{
    static const char* strs[] = { "\uf042 亮度:100%", "\uf042 亮度:70%", "\uf042 亮度:40%", "\uf042 亮度:10%", "\uf042 亮度:自动调节", "\uf085 开始重置" };
    if (index < 0 || index > 5)
    {
        return;
    }

    if (label_mes == nullptr)
    {
        label_mes = lv_label_create(lv_scr_act(), NULL);
        lv_obj_set_style_local_bg_opa(label_mes, LV_OBJ_PART_MAIN, LV_STATE_DEFAULT, LV_OPA_COVER);
        lv_obj_set_style_local_bg_color(label_mes, LV_OBJ_PART_MAIN, LV_STATE_DEFAULT, BCAT_NW_LINE_LIGHT_ORANGE);
        lv_label_set_long_mode(label_mes, LV_LABEL_LONG_SROLL_CIRC);
        lv_label_set_align(label_mes, LV_LABEL_ALIGN_CENTER);
        lv_obj_set_size(label_mes, 120, 22);
        lv_obj_align(label_mes, lv_scr_act(), LV_ALIGN_IN_TOP_MID, 0, 10);
        lv_obj_set_click(label_mes, false);
        lv_obj_set_hidden(label_mes, false);
        lv_obj_clear_state(label_mes, LV_STATE_DISABLED);
        lv_obj_set_drag(label_mes, false);
        lv_obj_set_style_local_text_color(label_mes, LV_BTN_PART_MAIN, LV_STATE_DEFAULT, LV_COLOR_WHITE);
        lv_obj_set_style_local_text_opa(label_mes, LV_BTN_PART_MAIN, LV_STATE_DEFAULT, 255);
        lv_obj_set_style_local_text_font(label_mes, LV_BTN_PART_MAIN, LV_STATE_DEFAULT, &bcat_font_16_mes);
        lv_obj_set_style_local_border_width(label_mes, LV_BTN_PART_MAIN, LV_STATE_DEFAULT, 2);
        lv_obj_set_style_local_border_color(label_mes, LV_BTN_PART_MAIN, LV_STATE_DEFAULT, LV_COLOR_WHITE);
        lv_obj_set_style_local_radius(label_mes, LV_OBJ_PART_MAIN, LV_STATE_DEFAULT, 4);
    }

    lv_label_set_text(label_mes, strs[index]);
    if (bcat_task == nullptr)
    {
        bcat_task = lv_task_create(mes_task, 200, LV_TASK_PRIO_MID, NULL);
    }
    itime = 0;
}

static void mes_task(lv_task_t* t)
{
    itime++;

    if (itime >= 10)
    {
        lv_obj_del(label_mes);
        label_mes = nullptr;
        lv_task_del(bcat_task);
        bcat_task = nullptr;
    }
}

void bcat_anim_in_up_down(lv_obj_t* obj, uint32_t delay)
{
    if (obj == nullptr)
    {
        return;
    }

    lv_anim_t a;
    lv_anim_init(&a);
    lv_anim_set_var(&a, obj);
    lv_anim_set_time(&a, BCAT_NW_ANIM_TIME);
    lv_anim_set_delay(&a, delay);
    lv_anim_set_exec_cb(&a, (lv_anim_exec_xcb_t)lv_obj_set_y);
    lv_anim_set_values(&a, lv_obj_get_y(obj) - BCAT_NW_ANIM_Y,
        lv_obj_get_y(obj));
    lv_anim_start(&a);
    lv_obj_fade_in(obj, BCAT_NW_ANIM_TIME - 50, delay);
}

void bcat_anim_in_down_up(lv_obj_t* obj, uint32_t delay)
{
    if (obj == nullptr)
    {
        return;
    }

    lv_anim_t a;
    lv_anim_init(&a);
    lv_anim_set_var(&a, obj);
    lv_anim_set_time(&a, BCAT_NW_ANIM_TIME);
    lv_anim_set_delay(&a, delay);
    lv_anim_set_exec_cb(&a, (lv_anim_exec_xcb_t)lv_obj_set_y);
    lv_anim_set_values(&a, lv_obj_get_y(obj) + BCAT_NW_ANIM_Y,
        lv_obj_get_y(obj));
    lv_anim_start(&a);
    lv_obj_fade_in(obj, BCAT_NW_ANIM_TIME - 50, delay);
}

void bcat_anim_in_left_right(lv_obj_t* obj, uint32_t delay)
{
    if (obj == nullptr)
    {
        return;
    }

    lv_anim_t a;
    lv_anim_init(&a);
    lv_anim_set_var(&a, obj);
    lv_anim_set_time(&a, BCAT_NW_ANIM_TIME);
    lv_anim_set_delay(&a, delay);
    lv_anim_set_exec_cb(&a, (lv_anim_exec_xcb_t)lv_obj_set_x);

    if (lv_obj_get_x(obj) < 50) {
        lv_anim_set_values(&a, lv_obj_get_x(obj) - BCAT_NW_ANIM_X,
            lv_obj_get_x(obj));
    }
    else
    {
        lv_anim_set_values(&a, lv_obj_get_x(obj) + BCAT_NW_ANIM_X,
            lv_obj_get_x(obj));
    }
    lv_anim_start(&a);
    lv_obj_fade_in(obj, BCAT_NW_ANIM_TIME - 50, delay);
}