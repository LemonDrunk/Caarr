/*
 * VO.c
 *
 *  Created on: 2023��10��11��
 *      Author: 23913
 */

#ifndef VO_C_
#define VO_C_
/*
 * vofa.c
 *
 *      Created on: 2023��10��1��
 *          Author: ��̫��
 *   Coding format: UTF-8
 */

#include <stdbool.h>
#include "zf_common_headfile.h"
#include "VO.h"
#include "pid.h"
unsigned char UART_RX_Buffer[UART_RX_LEN]={0};

bool frameHeadFlag,frameEndFlag;
VofaDebugger Receive;

//----------------------------------------------------------------------
//  �������    VOFA����
//  ����˵��    ��
//  ���ز���    ��
//  ʹ��ʾ��    VofaInteract();
//  ��ע��Ϣ    ֱ�ӵ���
//----------------------------------------------------------------------
void VofaInteract(void)
{
    VofaReceive(&Receive);

    switch(Receive.dataName)
    {
        //�˴��������ݽ���
        /*************************************************************/
        case 0xA1://�˴����ΪԼ���׳� �ٶ�0xA1�����ٶȻ���P
            //balanceSpeed.P = Receive.dataNum;
            break;
        case 0xA2:
            //balanceSpeed.I = Receive.dataNum;
            break;
        case 0xA3:
            break;
        case 0xB1:
            break;
        case 0xB2:
            break;
        case 0xB3:
            break;
        case 0xC1:
            Motor_Right_PID.Kp=Receive.dataNum;
            break;
        case 0xC2:
            Motor_Right_PID.Ki=Receive.dataNum;
            break;
        case 0xC3:
            Motor_Right_PID.Kd=Receive.dataNum;
            break;
        default:
            break;
        /*************************************************************/
    }

    VofaTransmit();
}

//----------------------------------------------------------------------
//  �������    ����VOFA������
//  ����˵��    �������
//  ���ز���    �������
//  ʹ��ʾ��    �������
//  ��ע��Ϣ    �������
//----------------------------------------------------------------------
void VofaReceive(VofaDebugger *debugger)
{
    if(UART_RX_Buffer[0] == 0xA5 && UART_RX_Buffer[UART_RX_LEN - 1] == 0x5A)//�������ͷβ
    {
        if(UART_RX_Buffer[UART_RX_LEN-2] != 0x08)
        {
            memset(UART_RX_Buffer,0x00,UART_RX_LEN);//�����ڴ棬��ʼ��
            frameHeadFlag = 0;
            frameEndFlag = 0;
        }
        else
        {
            debugger->dataName = UART_RX_Buffer[1];//C1,C2,����P,I
            debugger->dataNum = HexToFloat(&UART_RX_Buffer[2]);//�ؼ�����ת������

            frameHeadFlag = 0;
            frameEndFlag = 0;
        }
    }
    else
    {
        memset(UART_RX_Buffer,0x00,UART_RX_LEN);
        frameHeadFlag = 0;
        frameEndFlag = 0;
    }
}

//----------------------------------------------------------------------
//  �������    ��VOFA��������
//  ����˵��    �������
//  ���ز���    �������
//  ʹ��ʾ��    �������
//  ��ע��Ϣ    �������
//----------------------------------------------------------------------
void VofaTransmit(void)
{
    //�˴��������ݷ���
    /*************************************************************/
    //printf("%f,%f,%f",a,b,c);
    //���밴�մ˸�ʽ�����踽�����з�
    printf("10,20,30");
    /*************************************************************/
    //���л��з�����ɾ
    printf("\n");
}
//----------------------------------------------------------------------
//  �������    ʮ������ת��Ϊ������
//  ����˵��    �������
//  ���ز���    �������
//  ʹ��ʾ��    �������
//  ��ע��Ϣ    �������
//----------------------------------------------------------------------
float HexToFloat(unsigned char *a)
{
    unsigned char b,c,d;
    b = *(a+1);
    c = *(a+2);
    d = *(a+3);
    union _float
    {
        float f;
        unsigned char byte[4];
    };
    float m;
    union _float fl;
    fl.byte[0] = *a;
    fl.byte[1] = b;
    fl.byte[2] = c;
    fl.byte[3] = d;
    m = fl.f;
    return m;
}




#endif /* VO_C_ */
