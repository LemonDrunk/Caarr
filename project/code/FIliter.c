/*
 * FIliter.c
 *
 *  Created on: 2023��10��18��
 *      Author: 23913
 */

/***********************************************
* @brief :һ���ͺ��㷨�˲�
* @param :aȨ�أ�value������ֵ
* @return:������ֵvalue
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
