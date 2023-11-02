/*
 * pid.c
 *
 *  Created on: 2023��8��15��
 *      Author: Ming
 */
#include "zf_common_headfile.h"
#include "camera.h"
#include "pid.h"
#define steer_center 780

//�޷����֡�������������������������������������������������������������������������������������������������������������������������������������������������������
#define speed_pwm_max 1500//���ú��ֵ�����pwm���޷�
#define speed_pwm_min -1500//���ú��ֵ����Сpwm���޷�
#define steer_pwm_max 845//���ö�����pwm���޷�
#define steer_pwm_min 715//���ö����Сpwm���޷�

//����޷�
//void motor_speed_pwm_limit(int16 speed_pwm)
//{
//    if(speed_pwm>speed_pwm_max)
//        speed_pwm=speed_pwm_max;
//    if(speed_pwm<speed_pwm_min)
//        speed_pwm=speed_pwm_min;
//}

//����޷�
//void steer_pwm_limit(int16 steer_pwm)
//{
//    if(steer_pwm>steer_pwm_max)
//        steer_pwm=steer_pwm_max;
//    if(steer_pwm<steer_pwm_min)
//        steer_pwm=steer_pwm_min;
//}

//pid���֡�����������������������������������������������������������������������������������������������������
int16 steer_pid(pid_param_t Steer_pid)//λ��ʽPD��������PD����ϵ��
{

    int16 error=0;
    int16 last_error=0;
    float pid_value=0;//pid�����
    float pwm_steer=steer_center;//���Ҫ�������pwm

    //ifͼ�񶥱�С��һ��ֵ������ʱ��ͼ�񶥱߾Ͳ�������Ļ���ߣ�������һ����������������ͼ��������ƽ����ͼ������ƽ��ֵ

    error=ImageSensorMid-ImageDeal[58].Center;//�á���20��ͼ������ߵ㡿Ϊ���� ��ȥ ����Ļ���ߡ�

    pid_value = Steer_pid.Kp*error + Steer_pid.Kd*(error-last_error);
    last_error=error;
    pwm_steer = steer_center + pid_value;

//    steer_pwm_limit((int16)pwm_steer);//�޷���ע��ԭ�����޷����β���int16����//�ƺ�û�����ã�������

    if(pwm_steer>steer_pwm_max)
    {
        pwm_steer=steer_pwm_max;
    }
    if(pwm_steer<steer_pwm_min)
    {
        pwm_steer=steer_pwm_min;
    }

    return (int16)pwm_steer;
}

/***********************************************
* @brief :ʵ���ٶȱջ�
* @param :pid_param_t motorL_pid�����PIDֵ�Ľṹ��
        * int16 enco_true������������ɵ�����ֵ
        * int16 enco_wish����������
* @return:int16 pwm_L �������
* @date  :231008
* @author:T
************************************************/

//Ҫ��KD�����𣿣�ѧ�������õ���PI��

int16 motorL_pid(pid_param_t motorL_pid,int16 enco_true,int16 enco_wish)//����ʽPI
{

    static int16 error=0;//��ǰ���//Ϊɶ���Ķ�������õ�float������Ϊϵ��Ϊfloat������pid��ʽ���������pwm_L���ܴ�С��
    static int16 last_error=0;//�ϴ����
 //   static int16 last_last_error=0;//���ϴ����(��ʱ�Ȳ���)
    static int16 pwm_L=0;
    error=enco_wish-enco_true;
    pwm_L += motorL_pid.Kp*(error-last_error) + motorL_pid.Ki*error ;
    //PID����޷�����ֹ���ڵ����PID������ͬ�����µ�������ջٵ�����
    //ע�⣺��PID����޷���ᵼ����Ӧ����
    if(pwm_L>2000){
        pwm_L=2000;}
    else if(pwm_L<=0){
            pwm_L=0;}
    last_error=error;
    return pwm_L;
}

int16 motorR_pid(pid_param_t motorR_pid,int16 enco_true,int16 enco_wish)//����ʽPI
{

    static int16 error=0;//��ǰ���//Ϊɶ���Ķ�������õ�float������Ϊϵ��Ϊfloat������pid��ʽ���������pwm_L���ܴ�С��
    static int16 last_error=0;//�ϴ����
 //   static int16 last_last_error=0;//���ϴ����(��ʱ�Ȳ���)
    static int16 pwm_R=0;
    error=enco_wish-enco_true;
    pwm_R += motorR_pid.Kp*(error-last_error) + motorR_pid.Ki*error ;
    //PID����޷�����ֹ���ڵ����PID������ͬ�����µ�������ջٵ�����
    //ע�⣺��PID����޷���ᵼ����Ӧ����
    if(pwm_R>2000){
        pwm_R=2000;}
    else if(pwm_R<0){
            pwm_R=0;}
    last_error=error;
    return pwm_R;
}

/***********************************************
* @brief :λ��ʽpidʵ��λ�û�
* @param :pid_param_t Posit_pid��PID����,enco_true��ʵ��ֵ���������ۼ�ֵ����enco_wish��Ŀ��ֵ��Ŀ��λ�ã�
* @return:int16 output��Ϊ�ڻ��ٶȻ�����
* @date  :231008
* @author:T
************************************************/
int16 position_pid(pid_param_t Posit_pid,int16 enco_true,int16 enco_wish)
{
        static int16 error,sum_error,last_error=0;
        static int16 output=0;
        error = enco_wish-enco_true;
        sum_error+=error;
        output = Posit_pid.Kp*error+Posit_pid.Ki*sum_error+Posit_pid.Kd*(error-last_error);
        if(output>2000){
            output=2000;}
        else if(output<0){
            output=0;}
        last_error=error;
        return output;
}

/***********************************************
* @brief :ǰ�����ƣ���ģ�壬Te=0.0005*n+B*w
                            I=Te/Kt/��
                            U=I*R+Ke*��*w,����w=n*pi/30
*
* @param :
* @return:
* @date  :231008
* @author:T
************************************************/
//float profeed(float in){
//    static float last_in;
//    float out;
//
//    last_in=in;
//    return out;
//}
//




/***********************************************
* @brief :�����ֵ������ȫ��/����/����
* @param :int16 speed_pwm������ռ�ձ�
* @return:��
* @date  :
* @author:LMX
************************************************/

void set_whole_speed(int16 speed_pwm_hope)//�������������������Ӽ��١�����ת
{
    //motorL_pid(encoder_get_count(TIM1_ENCOEDER),speed_pwm_hope);
 //   motor_speed_pwm_limit(speed_pwm_hope);
    gpio_init(D12, GPO, GPIO_LOW, GPO_PUSH_PULL);
    gpio_init(D15, GPO, GPIO_LOW, GPO_PUSH_PULL);
    pwm_init(TIM4_PWM_MAP1_CH2_D13, 17000, speed_pwm_hope);
    pwm_init(TIM4_PWM_MAP1_CH3_D14, 17000, speed_pwm_hope);
    //pwm_init(TIM4_PWM_MAP1_CH1_D12, 17000, 5000);
    //pwm_init(TIM4_PWM_MAP1_CH4_D15, 17000, 5000);
}

void set_left_speed(int16 speed_pwm_left){
    gpio_init(D12, GPO, GPIO_LOW, GPO_PUSH_PULL);
    pwm_init(TIM4_PWM_MAP1_CH2_D13, 17000, speed_pwm_left);
}
void set_right_speed(int16 speed_pwm_right){
    gpio_init(D15, GPO, GPIO_LOW, GPO_PUSH_PULL);
    pwm_init(TIM4_PWM_MAP1_CH3_D14, 17000, speed_pwm_right);

}


