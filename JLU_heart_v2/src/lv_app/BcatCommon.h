#pragma once

#ifndef LV_BCATCOMMON_H
#define LV_BCATCOMMON_H

#ifdef __cplusplus
extern "C" {
#endif

/*********************
 *      DEFINES
 *********************/
#include "../lvgl/lvgl.h"
#include <stdio.h>

/*Color-black*/
#define BCAT_NW_PRINTER_NIGHT_C1        lv_color_hex(0x18232f) // 背景底色
#define BCAT_NW_PRINTER_NIGHT_C2        lv_color_hex(0x18232f) // 时钟 背景
#define BCAT_NW_PRINTER_NIGHT_C4        lv_color_hex(0x696969) // 天气栏 背景
#define BCAT_NW_PRINTER_NIGHT_C5        lv_color_hex(0x696969) // wifi栏 背景
#define BCAT_NW_PRINTER_NIGHT_C6        lv_color_hex(0x008B8B) // 星期 背景
#define BCAT_NW_PRINTER_NIGHT_C7        lv_color_hex(0xFF8C00) // AM 背景
#define BCAT_NW_PRINTER_NIGHT_C8        lv_color_hex(0xD4F2E7) // 文字 白
#define BCAT_NW_COLOR_NIGHT_OPA	    	LV_OPA_80              // 模块背景透明度

 /*Color-white*/
#define BCAT_NW_PRINTER_DAY_C1          lv_color_hex(0xFFFAF0) // 背景底色
#define BCAT_NW_PRINTER_DAY_C2          lv_color_hex(0xDCDCDC) // 时钟 背景
#define BCAT_NW_PRINTER_DAY_C4          lv_color_hex(0x5F9EA0) // 天气栏 背景6495ED
#define BCAT_NW_PRINTER_DAY_C5          lv_color_hex(0x808080) // wifi栏 背景
#define BCAT_NW_PRINTER_DAY_C6          lv_color_hex(0x3CB371) // 星期 背景
#define BCAT_NW_PRINTER_DAY_C7          lv_color_hex(0xFF8C00) // AM 背景
#define BCAT_NW_PRINTER_DAY_C8          lv_color_hex(0x000000) // 文字 黑
#define BCAT_NW_COLOR_DAY_OPA			LV_OPA_50              // 模块背景透明度
 
// #define BCAT_NW_PRINTER_C1              lv_color_hex(0xFFFAF0) // 背景底色
// #define BCAT_NW_PRINTER_C2              lv_color_hex(0xDCDCDC) // 时钟 背景
// #define BCAT_NW_PRINTER_C4              lv_color_hex(0x5F9EA0) // 天气栏 背景6495ED
// #define BCAT_NW_PRINTER_C5              lv_color_hex(0x808080) // wifi栏 背景
// #define BCAT_NW_PRINTER_C6              lv_color_hex(0x3CB371) // 星期 背景
// #define BCAT_NW_PRINTER_C7              lv_color_hex(0xFF8C00) // AM 背景
#define BCAT_NW_PRINTER_LIGHT           lv_color_hex(0x000000) // 文字 黑
#define BCAT_NW_COLOR_OPA				LV_OPA_50              // 模块背景透明度

#define BCAT_NW_PRINTER_MAIN_BG         lv_color_hex(0x5b8947) 
#define BCAT_NW_PRINTER_CARD_BG         lv_color_hex(0x104E8B) 
#define BCAT_NW_LINE_LIGHT_ORANGE       lv_color_hex(0xFF8C00) 
#define BCAT_NW_PRINTER_WEEK_GREEN	    lv_color_hex(0x6495ED) 
#define BCAT_NW_PRINTER_DARK	        lv_color_hex(0x0d0c0d) 
#define BCAT_NW_PRINTER_WHITE           lv_color_hex(0x000000)
#define BCAT_NW_PRINTER_GRAY            lv_color_hex(0x8a8a8a)
#define BCAT_NW_PRINTER_LIGHT_GRAY      lv_color_hex(0xc4c4c4)
#define BCAT_NW_PRINTER_GREEN           lv_color_hex(0x4cb242)
#define BCAT_NW_PRINTER_RED             lv_color_hex(0xd51732)
#define BCAT_NW_PRINTER_C3              lv_color_hex(0x3a434d)

 /*Sizes*/
#define BCAT_NW_LAYOUTLINE_SHOW			(0)
#define BCAT_NW_SETOFF_BOX				(1)
#define BCAT_NW_BOX_IN_SETOFF			(2)
#define BCAT_NW_COLOR_OPA				LV_OPA_80
#define BCAT_NW_RADIUS					(4)
#define BCAT_NW_TAG_RADIUS				(2)
#define BCAT_NW_SETOFF_LAYOUT			(0)
#define BCAT_NW_SIZE_TITLEBOX_W			(195)
#define BCAT_NW_SIZE_TITLEBOX_H			(30)
#define BCAT_NW_SIZE_CLOCKBOX_W			BCAT_NW_SIZE_TITLEBOX_W
#define BCAT_NW_SIZE_CLOCKBOX_H			(160)
#define BCAT_NW_SIZE_OTHER_W			BCAT_NW_SIZE_TITLEBOX_W
#define BCAT_NW_SIZE_OTHER_H			(50)
#define BCAT_NW_SIZE_WEATHERBOX_W		320 - BCAT_NW_SIZE_TITLEBOX_W
#define BCAT_NW_SIZE_WEATHERBOX_H		(240)
#define BCAT_NW_WIFI_W					(24)
#define BCAT_NW_WIFI_H					BCAT_NW_WIFI_W
#define BCAT_NW_CITY_W					(100)
#define BCAT_NW_CITY_H					(22)
#define BCAT_NW_FIRST_SCREEN			(1)
#define BCAT_NW_SECOND_SCREEN			(2)
#define BCAT_NW_THIRD_SCREEN			(3)

 /*anim*/
//#define	BCAT_NW_ANIM_LOCK				
#define BCAT_NW_ANIM_X				    (LV_VER_RES / 20)
#define BCAT_NW_ANIM_Y				    (LV_VER_RES / 20)
#define BCAT_NW_ANIM_DELAY				(40)
#define BCAT_NW_ANIM_TIME				(150)

typedef struct _BCAT_CLOCK_INFO
{
   int year;
   int mon;
   int mday;
   int wday;
   int hour;
   int min;
   int sec;
   
   _BCAT_CLOCK_INFO()
   {
       year = 0;
       mon = 0;
       mday = 0;
       wday = 0;
       hour = 0;
       min = 0;
       sec = 0;
   }
   
   _BCAT_CLOCK_INFO(int iY, int iM, int iD, int iW, int iH, int iMin, int iS)
   {
       year = iY;
       mon = iM;
       mday = iD;
       wday = iW;
       hour = iH;
       min = iMin;
       sec = iS;
   }

}_BCAT_CLOCK_INFO;

typedef struct _BCAT_WEATHER_INFO
{
   bool bsuc;                   // api请求成功/失败
   char city_cn[20];            // 北京
   char weather_cn[16];         // 阴转晴
   int weather_code;            // 0
   char wind_cn[16];            // 西北风
   char wind_level_cn[25];      // 3-4级转<3级
   int temp_now;                // -21℃
   int temp_max;                // 30℃
   int temp_min;                // -30℃
   int humidity;                // 77
   int pm25;                    // 61
}_BCAT_WEATHER_INFO;

typedef struct _BCAT_ROOM_INFO
{
    float temp;
    float humidity;

    _BCAT_ROOM_INFO()
    {
        temp = 0;
        humidity = 0;
    }

     _BCAT_ROOM_INFO(float ft, float fh)
    {
        temp = ft;
        humidity = fh;
    }
}_BCAT_ROOM_INFO;

void bcat_screen_out_all(lv_obj_t* obj, uint32_t delay);
void bcat_screen_out_all_anim(lv_obj_t* obj, uint32_t delay);
void set_current_screen(int index);
int get_current_screen();
bool is_day();
void set_day(bool bday);
void show_mes(int index);

void bcat_anim_in_up_down(lv_obj_t* obj, uint32_t delay);
void bcat_anim_in_down_up(lv_obj_t* obj, uint32_t delay);
void bcat_anim_in_left_right(lv_obj_t* obj, uint32_t delay);

// color
lv_color_t bcat_get_color_bg();
lv_color_t bcat_get_color_text();
lv_color_t bcat_get_color_title_box();
lv_color_t bcat_get_color_clock_box();
lv_color_t bcat_get_color_weather_box();
lv_color_t bcat_get_color_week();
lv_color_t bcat_get_color_apm();
lv_color_t bcat_get_color_line();

// wifi icon
// LV_IMG_DECLARE(icon_wifi_night_1_32);
// LV_IMG_DECLARE(icon_wifi_night_2_32);
// LV_IMG_DECLARE(icon_wifi_night_3_32);
// LV_IMG_DECLARE(icon_wifi_night_4_32);
// LV_IMG_DECLARE(icon_wifi_day_1_32);
// LV_IMG_DECLARE(icon_wifi_day_2_32);
// LV_IMG_DECLARE(icon_wifi_day_3_32);
// LV_IMG_DECLARE(icon_wifi_day_4_32);

// weather
// LV_IMG_DECLARE(icon_weather_0_64);
// LV_IMG_DECLARE(icon_weather_1_64);
// LV_IMG_DECLARE(icon_weather_2_64);
// LV_IMG_DECLARE(icon_weather_3_64);
// LV_IMG_DECLARE(icon_weather_4_64);
// LV_IMG_DECLARE(icon_weather_5_64);
// LV_IMG_DECLARE(icon_weather_6_64);
// LV_IMG_DECLARE(icon_weather_7_64);
// LV_IMG_DECLARE(icon_weather_8_64);
// LV_IMG_DECLARE(icon_weather_9_64);
// LV_IMG_DECLARE(icon_weather_10_64);
// LV_IMG_DECLARE(icon_weather_11_64);
// LV_IMG_DECLARE(icon_weather_12_64);
// LV_IMG_DECLARE(icon_weather_13_64);

// about
// LV_IMG_DECLARE(icon_esp_night_30);
// LV_IMG_DECLARE(icon_esp_day_30);
// LV_IMG_DECLARE(icon_lvgl_night_30);
// LV_IMG_DECLARE(icon_lvgl_day_30);
// LV_IMG_DECLARE(icon_git_night_30);
// LV_IMG_DECLARE(icon_git_day_30);
// LV_IMG_DECLARE(icon_taobao_30);
// LV_IMG_DECLARE(icon_bilibili_30);
// LV_IMG_DECLARE(icon_rainbow_64);
// LV_IMG_DECLARE(dark_100);
// LV_IMG_DECLARE(white_100);
// LV_IMG_DECLARE(icon_gitee_30);

// screen3
// LV_IMG_DECLARE(icon_bg_320);
// LV_IMG_DECLARE(sta_dark_150);

LV_IMG_DECLARE(icon_jl_150);
LV_IMG_DECLARE(bcat_heart_32);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /*LV_BCATCOMMON_H*/
