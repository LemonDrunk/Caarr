//        /*********************************************************************************************************************
//        * CH32V307VCT6 Opensource Library ����CH32V307VCT6 ��Դ�⣩��һ�����ڹٷ� SDK �ӿڵĵ�������Դ��
//        * Copyright (c) 2022 SEEKFREE ��ɿƼ�
//        *
//        * ���ļ���CH32V307VCT6 ��Դ���һ����
//        *
//        * CH32V307VCT6 ��Դ�� ��������
//        * �����Ը��������������ᷢ���� GPL��GNU General Public License���� GNUͨ�ù������֤��������
//        * �� GPL �ĵ�3�棨�� GPL3.0������ѡ��ģ��κκ����İ汾�����·�����/���޸���
//        *
//        * ����Դ��ķ�����ϣ�����ܷ������ã�����δ�������κεı�֤
//        * ����û�������������Ի��ʺ��ض���;�ı�֤
//        * ����ϸ����μ� GPL
//        *
//        * ��Ӧ�����յ�����Դ���ͬʱ�յ�һ�� GPL �ĸ���
//        * ���û�У������<https://www.gnu.org/licenses/>
//        *
//        * ����ע����
//        * ����Դ��ʹ�� GPL3.0 ��Դ���֤Э�� �����������Ϊ���İ汾
//        * �������Ӣ�İ��� libraries/doc �ļ����µ� GPL3_permission_statement.txt �ļ���
//        * ���֤������ libraries �ļ����� �����ļ����µ� LICENSE �ļ�
//        * ��ӭ��λʹ�ò����������� ���޸�����ʱ���뱣����ɿƼ��İ�Ȩ����������������
//        *
//        * �ļ�����          main
//        * ��˾����          �ɶ���ɿƼ����޹�˾
//        * �汾��Ϣ          �鿴 libraries/doc �ļ����� version �ļ� �汾˵��
//        * ��������          MounRiver Studio V1.8.1
//        * ����ƽ̨          CH32V307VCT6
//        * ��������          https://seekfree.taobao.com/
//        *
//        * �޸ļ�¼
//        * ����                                      ����                             ��ע
//        * 2022-09-15        ��W            first version
//        ********************************************************************************************************************/

//        #define BEEP                (C13)
//        //���⣺һ������set_pwm�ͻ�ǿ��ֹͣ���ڣ����շ����˻��Ƕ�ʱ�����ȼ����⣿
//        int main (void)
//        {
//            clock_init(SYSTEM_CLOCK_120M);      // ��ʼ��оƬʱ�� ����Ƶ��Ϊ 120MHz
//            debug_init();                       // ��ر��������������ڳ�ʼ��MPU ʱ�� ���Դ���
//            key_init(5);
//
//            while(1)
//              {
//                }
//}
//

#include "zf_common_headfile.h"
#define BEEP                (C13)
#include "Menu.h"
#include "camera.h"
#include "pid.h"
#include"Encoder.h"
#include "VO.h"
int main (void)
{
    clock_init(SYSTEM_CLOCK_144M);                                              // ��ʼ��оƬʱ�� ����Ƶ��Ϊ 144MHz
    debug_init();// ��ʼ��Ĭ�� Debug UART
    mt9v03x_init();//����ͷ��ʼ��
    PID_Init();
    key_init(5);
    gpio_init(BEEP, GPO, GPIO_LOW, GPO_PUSH_PULL);

    TFT_Init();//ע����ڶ�ʱ��֮ǰ
//    pit_ms_init(TIM6_PIT,5);//��ʱ�жϳ�ʼ������ÿ10ms�����pwm��ok�ġ�
//    Encoder_init();//��ʼ�����������򿪶�ʱ��5��100ms��
    pit_ms_init(TIM7_PIT,15);//��ȡ����״̬��ʱ��

    wireless_uart_init();//ע�⴮�ڳ�ʼ�����ڶ�ʱ������
    set_whole_speed(1200);//ע�����whileǰ
    // �˴���д�û����� ���������ʼ�������
        tft180_clear();
        tft180_full(RGB565_WHITE);
    while(1)
    {
         Menu_Switch();

    }
}


