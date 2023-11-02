/*
 * FIliter.c
 *
 *  Created on: 2023年10月18日
 *      Author: 23913
 */

/***********************************************
* @brief :一阶滞后算法滤波
* @param :a权重，value待处理值
* @return:处理后的值value
* @date  :231018
* @author:T
************************************************/
#include "zf_common_headfile.h"
int16 Lag_1(int16 a,int16 value){
    static int16 last_value;
    value=(1-a)*last_value-a*value;
    last_value = value;
    return value;
}
int16 Lag_2(int16 a,int16 value){
    static int16 last_value;
    value=(1-a)*last_value-a*value;
    last_value = value;
    return value;
}
