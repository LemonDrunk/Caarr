/*
 * Encoder.h
 *
 *  Created on: 2023��9��24��
 *      Author: 23913
 */

#ifndef ENCODER_H_
#define ENCODER_H_
void Encoder_init(void);
void pit_hanlder (void);
void steer_control(void);
void PID_Init(void);
float HexToFloat(unsigned char *a);
extern float encofloat_1;
extern float encofloat_2;
extern int16 encoder_data_1 ;
extern int16 encoder_data_2 ;//ֵ��ȫ�ֱ���
extern int16 ENCO_Wish_L;
extern int16 ENCO_Wish_R;
extern int16 encoder_sum_1 ;
extern int16 encoder_sum_2 ;
extern float speed1;
extern float speed2;

#endif /* ENCODER_H_ */
