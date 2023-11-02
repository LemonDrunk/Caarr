/*
 * camera.h
 * Created on: 2023年8月15日
 * Author: Ming
 */
/*元素：(按写代码的优先级自上而下排列)
 * 出库可以固定打角吧？似乎也不需要什么适应性
 * 直道          左、右弯道
 * 无、 左、右车库         斑马线         十字          断路          （三叉路）
 * 大、小圆环           左、右圆环
 */
#ifndef CAMERA_H_
#define CAMERA_H_

#include  "zf_common_headfile.h"

#define LCDH 60            //定义图像的行数（余夏用的60*80，后面说80列宽度对转弯不太够，可以试试100*60/70）
#define LCDW 100           //定义图像的列数
#define ImageSensorMid LCDW/2  //屏幕的中心

//Image_True(二维，图像)→Image_Pixel(二维，图像)→Image_Deal(一维，这个数组并非图像，而是图像的可用信息，如边线位置等)
//extern uint8 Image_True[LCDH][LCDW];//实际图像（灰度图）//实际数据从哪里传进来？
extern uint8 Image_Pixel[LCDH][LCDW];                         //二值化处理后的图像
extern uint8 LeftLine[LCDH];                                  //存放每行左边线
extern uint8 RightLine[LCDH];                                 //存放每行右边线
extern uint8 MidLine[LCDH];                                   //存放每行中线
extern uint8* Image_Use[LCDH][LCDW];

//结构体里为每一行图像的信息
typedef struct {
  //梯度扫线数据？
  int LeftBorder;         //左边线 梯度扫线
  int RightBorder;        //右边线
  int Center;             //中线
  int Wide;               //边界宽度
  uint8 IsLeftFind;       //左边有边标志位
  uint8 IsRightFind;      //右边有边标志位

  //左右手法则扫线数据//？
//  int LeftBoundary_First;  //左边界 保存第一次数据
//  int RightBoundary_First; //右边界 保存第一次数据
//  int LeftBoundary;        //左边界 保存最后一次数据
//  int RightBoundary;       //右边界 保存最后一次数据
} ImageDealDatatypedef;

//图像的总状态信息结构体(图像顶边、双边都丢的行数、丢左行数、丢右行数……)
//typedef struct {
//  int TowPoint;             //控制行，也就是我说的前瞻//Ming:?
//  uint8 OFFLine;            //图像顶边
//  uint8 WhiteLine;          //双边丢边数
//  uint8 OFFLineBoundary;    //八领域截止行
//  uint8 Miss_Left_lines;    //左线丢失//ming：这是标志位？
//  uint8 Miss_Right_lines;   //右线丢失
//  int Det_True;             //ming:?
//  float MU_P;               //ming:?
//  float MU_D;               //ming:?
//  //左右手法则扫线数据
//  uint8 WhiteLine_L;        //左边丢线数
//  uint8 WhiteLine_R;        //右边丢线数
//} ImageStatustypedef;

//图像标志位结构体
typedef struct {
    uint8 LongStraight;/*长直道标志位     0：无     1：为长直道*/
    uint8 Bend;/*弯道标志位      0：无     1：左弯道       2：右弯道*///【注意这里左、右的1、2跟余夏定义的是反的】
    uint8 GarageLocation;/*车库位置标志位      0：无     1：左车库       2：右车库*/
    uint8 Zebra;/*斑马线标志位        0：无     1：为斑马线*/
    uint8 Ramp;/*坡道标志位        0：无     1：为坡道*/
    uint8 RoadBlock;/*路障标志位        0：无     1：为路障*/
    uint8 RingLorR;/*左右圆环标志位        0：无     1：左圆环       2：右圆环*/
    uint8 RingBigorSmall;/*大小圆环标志位        0：无     1：大圆环        2：小圆环*/
    uint8 RingProgress;/*圆环进度*/

//    uint8 zafawfwagsg;//ming:?
//    uint8 zafawfgwa;//ming:?
//    uint8 straight_xie;//ming:?
} ImageFlagtypedef;

typedef struct {
  uint8 point;
  uint8 type;
} JumpPointTypedef;

extern ImageDealDatatypedef ImageDeal[LCDH];//存放处理后图像每一行信息
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
