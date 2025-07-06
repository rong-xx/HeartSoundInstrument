#pragma once

#ifndef BCAT_CIRCLE_PRO_1
#define BCAT_CIRCLE_PRO_1

#ifdef __cplusplus
extern "C" {
#endif

#include "../lvgl/lvgl.h"
#include "./BcatCommon.h"

void bcat_creat_circle_pro_1(void);
void bcat_circle_pro_1_noready();
bool bcat_circle_pro_1_done();
void bcat_reset_heart();
void set_value_1(int peaks);
void set_value_2(int hr);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /*BCAT_CIRCLE_PRO_1*/
