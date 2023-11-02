/*
 * Encoder.c
 *
 *  Created on: 2023��9��24��
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
* @brief :PID��ʼ������
* @param :��
* @return:��
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
* @brief :��������ʼ����������ʱ��5�ж�
* @param :��
* @return:��
* @date  :231008
* @author:T
************************************************/
void Encoder_init(void){
    encoder_dir_init(ENCODER_1, ENCODER_1_DIR, ENCODER_1_LSB);                  // ��ʼ��������ģ�������� ������������ģʽ
    encoder_dir_init(ENCODER_2, ENCODER_2_DIR, ENCODER_2_LSB);
    pit_ms_init(TIM5_PIT, 15);//100ms=Tc
}

/***********************************************
* @brief :���ݱ�������ֵ�����ٶȣ�����PID����Ҫ��ֱ����������
* @param :int16 encoder_data��������������ֵ
* @return:float v���ٶȣ�m/s��
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
    //w����=w*���ֱ�
    float w1=w*30/68;
    //v=r*w
    float v=0.065*w1;
    return v;
}

/***********************************************
* @brief :�������жϴ���������ֵ+�ٶȱջ�
* @param :��
* @return:��
* @date  :231008
* @author:T
************************************************/
//�ж��ж���������Ӧ����Ҫ�ӵ�ͨ�˲����������ڴ��ж�һ���������
//����ʽ���ȵ��������������㣬���ŵ��ڱ���������񵴣�������΢�����������
//���ȶ��Ĳ�����0.1��1/kp,ki�����Լ�KD���Ƴ�����
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
    //vofa��λ��
}

/***********************************************
* @brief :�жϴ��������ƣ�Ϊ�˷���ʹ�ýṹ�壬ȡ����
* @param :��
* @return:��
* @date  :231008
* @author:T
************************************************/
void steer_control(void){
    pwm_init(TIM2_PWM_MAP3_CH1_A15, 50, steer_pid(Steer_PID));//PD���ƶ��
}



