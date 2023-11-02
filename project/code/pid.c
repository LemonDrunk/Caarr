/*
 * pid.c
 *
 *  Created on: 2023年8月15日
 *      Author: Ming
 */
#include "zf_common_headfile.h"
#include "camera.h"
#include "pid.h"
#define steer_center 780

//限幅部分————————————————————————————————————————————————————————————————————————————
#define speed_pwm_max 1500//设置后轮电机最大pwm以限幅
#define speed_pwm_min -1500//设置后轮电机最小pwm以限幅
#define steer_pwm_max 845//设置舵机最大pwm以限幅
#define steer_pwm_min 715//设置舵机最小pwm以限幅

//电机限幅
//void motor_speed_pwm_limit(int16 speed_pwm)
//{
//    if(speed_pwm>speed_pwm_max)
//        speed_pwm=speed_pwm_max;
//    if(speed_pwm<speed_pwm_min)
//        speed_pwm=speed_pwm_min;
//}

//舵机限幅
//void steer_pwm_limit(int16 steer_pwm)
//{
//    if(steer_pwm>steer_pwm_max)
//        steer_pwm=steer_pwm_max;
//    if(steer_pwm<steer_pwm_min)
//        steer_pwm=steer_pwm_min;
//}

//pid部分———————————————————————————————————————————————————
int16 steer_pid(pid_param_t Steer_pid)//位置式PD；参数：PD两个系数
{

    int16 error=0;
    int16 last_error=0;
    float pid_value=0;//pid的输出
    float pwm_steer=steer_center;//最后要给舵机的pwm

    //if图像顶边小于一个值（过弯时，图像顶边就不会在屏幕顶边，会下移一定行数），就三行图像中线求平均→图像中线平均值

    error=ImageSensorMid-ImageDeal[58].Center;//用【第20行图像的中线点】为期望 减去 【屏幕中线】

    pid_value = Steer_pid.Kp*error + Steer_pid.Kd*(error-last_error);
    last_error=error;
    pwm_steer = steer_center + pid_value;

//    steer_pwm_limit((int16)pwm_steer);//限幅，注意原函数限幅的形参是int16类型//似乎没起作用？？！！

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
* @brief :实现速度闭环
* @param :pid_param_t motorL_pid：存放PID值的结构体
        * int16 enco_true：传入编码器采的脉冲值
        * int16 enco_wish：期望脉冲
* @return:int16 pwm_L 赋给电机
* @date  :231008
* @author:T
************************************************/

//要用KD参数吗？（学长代码用的是PI）

int16 motorL_pid(pid_param_t motorL_pid,int16 enco_true,int16 enco_wish)//增量式PI
{

    static int16 error=0;//当前误差//为啥余夏定义误差用的float——因为系数为float，代了pid公式计算出来的pwm_L可能带小数
    static int16 last_error=0;//上次误差
 //   static int16 last_last_error=0;//上上次误差(暂时先不用)
    static int16 pwm_L=0;
    error=enco_wish-enco_true;
    pwm_L += motorL_pid.Kp*(error-last_error) + motorL_pid.Ki*error ;
    //PID输出限幅，防止由于电机和PID工作不同步导致电机超调烧毁的问题
    //注意：对PID输出限幅后会导致响应变慢
    if(pwm_L>2000){
        pwm_L=2000;}
    else if(pwm_L<=0){
            pwm_L=0;}
    last_error=error;
    return pwm_L;
}

int16 motorR_pid(pid_param_t motorR_pid,int16 enco_true,int16 enco_wish)//增量式PI
{

    static int16 error=0;//当前误差//为啥余夏定义误差用的float——因为系数为float，代了pid公式计算出来的pwm_L可能带小数
    static int16 last_error=0;//上次误差
 //   static int16 last_last_error=0;//上上次误差(暂时先不用)
    static int16 pwm_R=0;
    error=enco_wish-enco_true;
    pwm_R += motorR_pid.Kp*(error-last_error) + motorR_pid.Ki*error ;
    //PID输出限幅，防止由于电机和PID工作不同步导致电机超调烧毁的问题
    //注意：对PID输出限幅后会导致响应变慢
    if(pwm_R>2000){
        pwm_R=2000;}
    else if(pwm_R<0){
            pwm_R=0;}
    last_error=error;
    return pwm_R;
}

/***********************************************
* @brief :位置式pid实现位置环
* @param :pid_param_t Posit_pid：PID参数,enco_true：实际值（编码器累加值），enco_wish：目标值（目标位置）
* @return:int16 output作为内环速度环输入
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
* @brief :前馈控制，仅模板，Te=0.0005*n+B*w
                            I=Te/Kt/φ
                            U=I*R+Ke*φ*w,其中w=n*pi/30
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
* @brief :电机赋值函数，全轮/左轮/右轮
* @param :int16 speed_pwm：调节占空比
* @return:无
* @date  :
* @author:LMX
************************************************/

void set_whole_speed(int16 speed_pwm_hope)//根据正负来控制来做加减速、正反转
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


