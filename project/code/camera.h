/*
 * camera.h
 * Created on: 2023��8��15��
 * Author: Ming
 */
/*Ԫ�أ�(��д��������ȼ����϶�������)
 * ������Թ̶���ǰɣ��ƺ�Ҳ����Ҫʲô��Ӧ��
 * ֱ��          �������
 * �ޡ� ���ҳ���         ������         ʮ��          ��·          ������·��
 * ��СԲ��           ����Բ��
 */
#ifndef CAMERA_H_
#define CAMERA_H_

#include  "zf_common_headfile.h"

#define LCDH 60            //����ͼ��������������õ�60*80������˵80�п�ȶ�ת�䲻̫������������100*60/70��
#define LCDW 100           //����ͼ�������
#define ImageSensorMid LCDW/2  //��Ļ������

//Image_True(��ά��ͼ��)��Image_Pixel(��ά��ͼ��)��Image_Deal(һά��������鲢��ͼ�񣬶���ͼ��Ŀ�����Ϣ�������λ�õ�)
//extern uint8 Image_True[LCDH][LCDW];//ʵ��ͼ�񣨻Ҷ�ͼ��//ʵ�����ݴ����ﴫ������
extern uint8 Image_Pixel[LCDH][LCDW];                         //��ֵ��������ͼ��
extern uint8 LeftLine[LCDH];                                  //���ÿ�������
extern uint8 RightLine[LCDH];                                 //���ÿ���ұ���
extern uint8 MidLine[LCDH];                                   //���ÿ������
extern uint8* Image_Use[LCDH][LCDW];

//�ṹ����Ϊÿһ��ͼ�����Ϣ
typedef struct {
  //�ݶ�ɨ�����ݣ�
  int LeftBorder;         //����� �ݶ�ɨ��
  int RightBorder;        //�ұ���
  int Center;             //����
  int Wide;               //�߽���
  uint8 IsLeftFind;       //����б߱�־λ
  uint8 IsRightFind;      //�ұ��б߱�־λ

  //�����ַ���ɨ������//��
//  int LeftBoundary_First;  //��߽� �����һ������
//  int RightBoundary_First; //�ұ߽� �����һ������
//  int LeftBoundary;        //��߽� �������һ������
//  int RightBoundary;       //�ұ߽� �������һ������
} ImageDealDatatypedef;

//ͼ�����״̬��Ϣ�ṹ��(ͼ�񶥱ߡ�˫�߶���������������������������������)
//typedef struct {
//  int TowPoint;             //�����У�Ҳ������˵��ǰհ//Ming:?
//  uint8 OFFLine;            //ͼ�񶥱�
//  uint8 WhiteLine;          //˫�߶�����
//  uint8 OFFLineBoundary;    //�������ֹ��
//  uint8 Miss_Left_lines;    //���߶�ʧ//ming�����Ǳ�־λ��
//  uint8 Miss_Right_lines;   //���߶�ʧ
//  int Det_True;             //ming:?
//  float MU_P;               //ming:?
//  float MU_D;               //ming:?
//  //�����ַ���ɨ������
//  uint8 WhiteLine_L;        //��߶�����
//  uint8 WhiteLine_R;        //�ұ߶�����
//} ImageStatustypedef;

//ͼ���־λ�ṹ��
typedef struct {
    uint8 LongStraight;/*��ֱ����־λ     0����     1��Ϊ��ֱ��*/
    uint8 Bend;/*�����־λ      0����     1�������       2�������*///��ע���������ҵ�1��2�����Ķ�����Ƿ��ġ�
    uint8 GarageLocation;/*����λ�ñ�־λ      0����     1���󳵿�       2���ҳ���*/
    uint8 Zebra;/*�����߱�־λ        0����     1��Ϊ������*/
    uint8 Ramp;/*�µ���־λ        0����     1��Ϊ�µ�*/
    uint8 RoadBlock;/*·�ϱ�־λ        0����     1��Ϊ·��*/
    uint8 RingLorR;/*����Բ����־λ        0����     1����Բ��       2����Բ��*/
    uint8 RingBigorSmall;/*��СԲ����־λ        0����     1����Բ��        2��СԲ��*/
    uint8 RingProgress;/*Բ������*/

//    uint8 zafawfwagsg;//ming:?
//    uint8 zafawfgwa;//ming:?
//    uint8 straight_xie;//ming:?
} ImageFlagtypedef;

typedef struct {
  uint8 point;
  uint8 type;
} JumpPointTypedef;

extern ImageDealDatatypedef ImageDeal[LCDH];//��Ŵ����ͼ��ÿһ����Ϣ
//extern ImageStatustypedef  ImageStatus;
extern ImageFlagtypedef ImageFlag;

void Image_CompressInit(void);
uint8 Get_Threshold(uint8* image[LCDH][LCDW],
                    uint16 col,
                    uint16 row);
void Get_BinaryImage();
void Get_BaseLine();
void draw_midline();
//uint8 Protect_Without_Road(uint8 StartLine,uint8 EndLine);
//uint8 outadge_protect(uint8 StartLine,uint8 EndLine);
uint8 outadge_protect(uint8 StartLine,uint8 EndLine,uint8 StartRow,uint8 EndRow);
//void Get_AllLine();
//float Judge_Straight(uint8 choice , uint8 StartLine , uint8 EndLine);
//void Judge_Long_Straight();
//void Handle_Long_Straight();
//void GetBorder_And_GetBorederType(uint8* p,uint8 type,uint8 H,uint8 L,JumpPointTypedef* Q);
//void Image_Mother_Function();

#endif /* CAMERA_H_ */
