#pragma once

#ifndef BCAT_CIRCLE_PRO_2
#define BCAT_CIRCLE_PRO_2

#ifdef __cplusplus
extern "C" {
#endif

#include "../lvgl/lvgl.h"
#include "BcatCommon.h"

void bcat_creat_circle_pro_2(void);
void bcat_circle_pro_2_noready();
bool bcat_circle_pro_2_done();
void bcat_set_value_id(uint32_t id);
void setLabelText(const char* text);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /*BCAT_CIRCLE_PRO_2*/
