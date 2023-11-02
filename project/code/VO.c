/*
 * VO.c
 *
 *  Created on: 2023年10月11日
 *      Author: 23913
 */

#ifndef VO_C_
#define VO_C_
/*
 * vofa.c
 *
 *      Created on: 2023年10月1日
 *          Author: 蕉太狼
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
//  函数简介    VOFA交互
//  参数说明    空
//  返回参数    空
//  使用示例    VofaInteract();
//  备注信息    直接调用
//----------------------------------------------------------------------
void VofaInteract(void)
{
    VofaReceive(&Receive);

    switch(Receive.dataName)
    {
        //此处进行数据接收
        /*************************************************************/
        case 0xA1://此处编号为约定俗成 假定0xA1代表速度环的P
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
//  函数简介    接收VOFA的数据
//  参数说明    无需调用
//  返回参数    无需调用
//  使用示例    无需调用
//  备注信息    无需调用
//----------------------------------------------------------------------
void VofaReceive(VofaDebugger *debugger)
{
    if(UART_RX_Buffer[0] == 0xA5 && UART_RX_Buffer[UART_RX_LEN - 1] == 0x5A)//检测数据头尾
    {
        if(UART_RX_Buffer[UART_RX_LEN-2] != 0x08)
        {
            memset(UART_RX_Buffer,0x00,UART_RX_LEN);//申请内存，初始化
            frameHeadFlag = 0;
            frameEndFlag = 0;
        }
        else
        {
            debugger->dataName = UART_RX_Buffer[1];//C1,C2,代表P,I
            debugger->dataNum = HexToFloat(&UART_RX_Buffer[2]);//控件参数转浮点数

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
//  函数简介    向VOFA发送数据
//  参数说明    无需调用
//  返回参数    无需调用
//  使用示例    无需调用
//  备注信息    无需调用
//----------------------------------------------------------------------
void VofaTransmit(void)
{
    //此处进行数据发送
    /*************************************************************/
    //printf("%f,%f,%f",a,b,c);
    //必须按照此格式，无需附带换行符
    printf("10,20,30");
    /*************************************************************/
    //下行换行符不可删
    printf("\n");
}
//----------------------------------------------------------------------
//  函数简介    十六进制转换为浮点数
//  参数说明    无需调用
//  返回参数    无需调用
//  使用示例    无需调用
//  备注信息    无需调用
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
