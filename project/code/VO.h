/*
 * VO.h
 *
 *  Created on: 2023��10��11��
 *      Author: 23913
 */

#ifndef VO_H_
#define VO_H_
#include "zf_common_headfile.h"
#define UART_RX_LEN 8
extern unsigned char UART_RX_Buffer[UART_RX_LEN];
extern bool frameHeadFlag,frameEndFlag;
typedef struct{
    unsigned char dataName;
    float dataNum;
}VofaDebugger;

void VofaInteract(void);
void VofaReceive(VofaDebugger *debugger);
void VofaTransmit(void);
float HexToFloat(unsigned char *a);



#endif /* VO_H_ */
