/*
 * Encoder.c
 *
 *  Created on: 2023年9月24日
 *      Author: 23913
 */
#include "zf_common_headfile.h"
#include "pid.h"
#include "VO.h"
#include "FIliter.h"
#define ENCODER_1                   (TIM1_ENCOEDER)
#define ENCODER_1_DIR               (TIM1_ENCOEDER_MAP3_CH1_E9)
#define ENCODER_1_LSB               (TIM1_ENCOEDER_MAP3_CH2_E11)

#define ENCODER_2                   (TIM8_ENCOEDER)
#define ENCODER_2_DIR               (TIM8_ENCOEDER_MAP0_CH1_C6)
#define ENCODER_2_LSB               (TIM8_ENCOEDER_MAP0_CH2_C7)
int16 ENCO_Wish_L=0;
int16 ENCO_Wish_R=0;
int16 encoder_data_1 = 0;
int16 encoder_data_2 = 0;
int16 encoder_sum_1 =0;
int16 encoder_sum_2 =0;
float encofloat_1;
float encofloat_2;
int16* point1=0;
int16* point2=0;
float speed1=0;
float speed2=0;
pid_param_t Steer_PID;
pid_param_t Motor_Left_PID;
pid_param_t Motor_Right_PID;
pid_param_t Posit_PID;

/***********************************************
* @brief :PID初始化函数
* @param :无
* @return:无
* @date  :231008
* @author:T
************************************************/
void PID_Init(void){
    Steer_PID.Kp=3;
    Steer_PID.Ki=0;
    Steer_PID.Kd=0;

    Motor_Left_PID.Kp=60;
    Motor_Left_PID.Ki=0.5;
    Motor_Left_PID.Kd=0;

    Motor_Right_PID.Kp=62;
    Motor_Right_PID.Ki=0.3;
    Motor_Right_PID.Kd=0;

}

/***********************************************
* @brief :编码器初始化，开启定时器5中断
* @param :无
* @return:无
* @date  :231008
* @author:T
************************************************/
void Encoder_init(void){
    encoder_dir_init(ENCODER_1, ENCODER_1_DIR, ENCODER_1_LSB);                  // 初始化编码器模块与引脚 方向解码编码器模式
    encoder_dir_init(ENCODER_2, ENCODER_2_DIR, ENCODER_2_LSB);
    pit_ms_init(TIM5_PIT, 15);//100ms=Tc
}

/***********************************************
* @brief :根据编码器读值计算速度，调节PID不需要，直接用脉冲数
* @param :int16 encoder_data：编码器读到的值
* @return:float v：速度（m/s）
* @date  :231008
* @author:T
************************************************/

float speedcau(int16 encoder_data){
    //f1=M1/Tc=encoder_data/100ms
    float f1=encoder_data/0.01;
    //n=f1/Z*60.Z=2*1024,60=rpm;
    float n=f1/(2*1024*60);
    //w=2*pi*n
    float w=2*3.14*n;
    //w后轮=w*齿轮比
    float w1=w*30/68;
    //v=r*w
    float v=0.065*w1;
    return v;
}

/***********************************************
* @brief :编码器中断处理，读脉冲值+速度闭环
* @param :无
* @return:无
* @date  :231008
* @author:T
************************************************/
//中断中读编码器，应该需要加低通滤波处理，建议在此中断一并处理控速
//增量式：先调整积分项，求起振点，接着调节比例项，抑制振荡，最后调节微分项，削弱超调
//略稳定的参数：0.1，1/kp,ki（可以加KD抑制超调）
float fdata[4]={0};
uint8 tail[4]={0x00, 0x00, 0x80, 0x7f};
void pit_hanlder (void)
{
        int16 pwm_l;
        int16 pwm_r;
        encoder_data_1 = encoder_get_count(ENCODER_1);
        encoder_clear_count(ENCODER_1);
        encoder_data_2 = -1*encoder_get_count(ENCODER_2);
        encoder_clear_count(ENCODER_2);
        encoder_sum_1+=encoder_data_1;
        encoder_sum_2+=encoder_data_2;
        pwm_l=motorL_pid(Motor_Left_PID, encoder_data_1,ENCO_Wish_L);
        pwm_r=motorR_pid(Motor_Right_PID,encoder_data_2,ENCO_Wish_R);
              fdata[0]=(float)encoder_data_1;
              fdata[1]=(float)encoder_data_2;
              fdata[2]=(float)ENCO_Wish_L;
              wireless_uart_send_buffer((uint8*)fdata, sizeof(float)* 4);
              wireless_uart_send_buffer((uint8 *)tail, sizeof(char) * 4);
        set_left_speed(pwm_l);
        set_right_speed(pwm_r);

        wireless_uart_read_buffer(UART_RX_Buffer, UART_RX_LEN);
        VofaInteract();
    //vofa上位机
}

/***********************************************
* @brief :中断处理舵机控制，为了方便使用结构体，取出来
* @param :无
* @return:无
* @date  :231008
* @author:T
************************************************/
void steer_control(void){
    pwm_init(TIM2_PWM_MAP3_CH1_A15, 50, steer_pid(Steer_PID));//PD控制舵机
}



