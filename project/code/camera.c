/*
 * camera.c
 *
 *  Created on: 2023��8��15��
 *      Author: Ming
 */
#include "camera.h"
#include "math.h"
//����extern�ı����Ķ���***********************************************************************************
uint8 Image_True[LCDH][LCDW];//ʵ��ͼ�񣨻Ҷ�ͼ��//ʵ�����ݴ����ﴫ������
uint8 Image_Pixel[LCDH][LCDW];                         //��ֵ��������ͼ��
uint8 LeftLine[LCDH];                                  //���ÿ�������
uint8 RightLine[LCDH];                                 //���ÿ���ұ���
uint8 MidLine[LCDH];                                   //���ÿ������
ImageDealDatatypedef ImageDeal[LCDH];//��Ŵ����ͼ��ÿһ����Ϣ
//ImageStatustypedef  ImageStatus;
ImageFlagtypedef ImageFlag;
//*************************************************************************

uint8* Image_Use[LCDH][LCDW];//ָ�����

int BottomBorderL;//����е�����ߵ�
int BottomBorderR;//����е��ұ��ߵ�
int BottomCenter;//����е��е�
int Xsite,Ysite;//��ʱ������XsiteΪͼ���ĳ�У�YsiteΪͼ���ĳ��

//��һ�������¼ֱ���İ��uint8 Half_Straight_Wide[LCDH]={};
//��һ�������¼����İ��uint8 Half_Bend_Wide[LCDH]={};

//��ȡ���ߺͱ������ͺ���
//���ߺ���Get_ExtraLine(){}���ݱ�־λ�ж�Ҫ��Ҫ���߼���ת�����ߺ���
//�Ͻ��������ַ�ɨ�ߣ�
//sobel��
//Ԫ���жϺ�������Բ����Բ���õ��ѭ���򵥵㣩����Բ�����µ������������·�ϡ������ߡ����ҳ���Element_Judge(){}
//��־λ�����ʼ��void Flag_Init(){}

//void Element_Judge_Bend(){}
//void Element_Judge_GarageLocation(){}
//void Element_Judge_Zebra(){}
//void Element_Judge_Ramp(){}
//void Element_Judge_RoadBlock(){}
//void Element_Judge_RingLorR(){}
//void Element_Judge_RingBigorSmall(){}
//void Element_Judge_RingProgress(){}

//void Element_Handle_Bend(){}
//void Element_Handle_GarageLocation(){}
//void Element_Handle_Zebra(){}
//void Element_Handle_Ramp(){}
//void Element_Handle_RoadBlock(){}
//void Element_Handle_RingLorR(){}
//void Element_Handle_RingBigorSmall(){}
//void Element_Handle_RingProgress(){}
//*******************************************************************************************************************
//ͼ���ʼ����ѹ��ͼ������������ͷ������ͼ����Ҫ���ڴ����ͼ���������ok��
void Image_CompressInit(void)
{
    float Mh = MT9V03X_H;           //����ͷ������
    float Mw = MT9V03X_W;           //����ͷ������
    float Lh = LCDH;                //���ڴ��������
    float Lw = LCDW;                //���ڴ��������

    int i, j, row, line;
    const float div_h = Mh / Lh,    //����ԭʼ��ͼ��ߴ��������Ҫ��ͼ��ߴ�ȷ����ѹ������
                div_w = Mw / Lw;
    for (i = 0; i < LCDH; i++)      //������ֵ
    {
      row = i * div_h + 0.5;    //+0.5�൱���������룬���磬i*divh�õ�����1.4�����row�õ�1.9(row��int��ʵ��ȡ1)���õ�����1.5�����õ�2 (row��int��ʵ��ȡ2)
      for (j = 0; j < LCDW; j++)
      {
        line = j * div_w + 0.5;
        Image_Use[i][j] = &mt9v03x_image[row][line];//Image_Use[][]��һ��ָ��������飬&ȡ��mt9v03x_image[][]�ĵ�ַ
//        Image_True[i][j] = mt9v03x_image[row][line];
      }
    }
///*���д�ı���������ͷ����ȡ������
//    uint8 i,j;
//    for(i=0;i<LCDH;i++)
//    {
//        for(j=0;j<LCDW;j++)
//        {
//            Image_True[i][j] = mt9v03x_image[i][j];
////            Image_Use[i][j] = &mt9v03x_image[i][j];     //Image_Use[][]��һ��ָ��������飬&ȡ��mt9v03x_image[][]�ĵ�ַ
//        }
//    }
//*/
}

//*******************************************************************************************************************
//������ֵ����ֵ����������ϸ΢����
uint8 Get_Threshold(uint8* image[LCDH][LCDW],
                    uint16 col,
                    uint16 row)
{
#define GrayScale 256
 uint16 width = col;
 uint16 height = row;
 int pixelCount[GrayScale];
 float pixelPro[GrayScale];
 int i, j, pixelSum = width * height;
 uint8 threshold = 0;
 for (i = 0; i < GrayScale; i++)                    //�Ȱ�pixelCount��pixelPro��������Ԫ��ȫ����ֵΪ0
 {
   pixelCount[i] = 0;
   pixelPro[i] = 0;
 }

 uint32 gray_sum = 0;
 /**************************************ͳ��ÿ���Ҷ�ֵ(0-255)������ͼ���г��ֵĴ���**************************************/
 for (i = 0; i < height; i += 1)                   //����ͼ���ÿһ�У��ӵ����е���59�С�
 {
   for (j = 0; j < width; j += 1)                  //����ͼ���ÿһ�У��ӵ����е���79�С�
   {
     pixelCount[*image[i][j]]++;       //����ǰ�����ص������ֵ���Ҷ�ֵ����Ϊ����������±ꡣ
     gray_sum += *image[i][j];         //���������Ҷ�ͼ��ĻҶ�ֵ�ܺ͡�
   }
 }
 /**************************************ͳ��ÿ���Ҷ�ֵ(0-255)������ͼ���г��ֵĴ���**************************************/



 /**************************************����ÿ������ֵ���Ҷ�ֵ���������Ҷ�ͼ������ռ�ı���*************************************************/
 for (i = 0; i < GrayScale; i++)
 {
     pixelPro[i] = (float)pixelCount[i] / pixelSum;
 }
 /**************************************����ÿ������ֵ���Ҷ�ֵ���������Ҷ�ͼ������ռ�ı���**************************************************/



 /**************************************��ʼ��������ͼ��ĻҶ�ֵ��0-255������һ��Ҳ�Ǵ����������һ��***************************/
 /*******************Ϊʲô˵������⣿��Ϊ��Ҳ�ǲ���⣡�������������һ����ѧ���⣬��������Ϊ��ѧ��ʽ��***************************/
 float w0, w1, u0tmp, u1tmp, u0, u1, u, deltaTmp, deltaMax = 0;
 w0 = w1 = u0tmp = u1tmp = u0 = u1 = u = deltaTmp = 0;
 for (j = 0; j < GrayScale; j++)
 {
   w0 += pixelPro[j];                          //�����������ÿ���Ҷ�ֵ�����ص���ռ�ı���֮�ͣ����������ֵı�����
   u0tmp += j * pixelPro[j];

   w1 = 1 - w0;
   u1tmp = gray_sum / pixelSum - u0tmp;

   u0 = u0tmp / w0;                            //����ƽ���Ҷ�
   u1 = u1tmp / w1;                            //ǰ��ƽ���Ҷ�
   u = u0tmp + u1tmp;                          //ȫ��ƽ���Ҷ�
   deltaTmp = w0 * pow((u0 - u), 2) + w1 * pow((u1 - u), 2);
   if (deltaTmp > deltaMax)
   {
     deltaMax = deltaTmp;
     threshold = j;
   }
   if (deltaTmp < deltaMax)
   {
     break;
   }
 }
 return threshold;
}

//*******************************************************************************************************************
//�Ҷ�ͼ�ô�򷨵õ�����ֵ���ж�ֵ������
void Get_BinaryImage()
//���Ļ����˶Ա�־λ���жϣ�����ͬ��ֵ��ʲô�ã�(���룺������ת��ʱ�ῴ���ܴ�һƬ�������������ⲿ�ֵĻ���ֵ�ͻ�ƫС)
{
    uint8 i,j=0;
//    uint8 threshold_0=100;
    uint8 threshold_0=Get_Threshold(Image_Use,LCDW,LCDH);

    for(i=0;i<LCDH;i++)
    {
        for(j=0;j<LCDW;j++)
        {
            if(*Image_Use[i][j] > threshold_0 )//Get_Threshold�ĵ�һ��������ָ�����͵�//*Image_Use����������
                Image_Pixel[i][j]=255;//������ֵ����Ϊ1������
            else
                Image_Pixel[i][j]=0;//С����ֵ����Ϊ0������
        }
    }
}

//*******************************************************************************************************************
//��ȡͼ������еı��߼����������2��3��4��5�еı���
//�ӵ�����Ļ������������(����for)���ҵ����������ڵ��˵���ҵ��˱���
void Get_BaseLine(){//Ϊʲô����д������Զ�����ң�
    for (Xsite =ImageSensorMid ; Xsite > 0; Xsite--)//����Ļ�м�������ұ���
    {
        if(Image_Pixel[LCDH-1][Xsite]==0 && Image_Pixel[LCDH-1][Xsite-1]==0)//ɨ���Ǵӽ�����Զ��ɨ������Ϊ��0�У���������ͷ��Զ���ǵ�0�У�
        {
            BottomBorderL=Xsite;
            break;
        }
        else if (Xsite==0+1)//�Ҳ������������ڵ��������һ����Ϊ���ߵ�
        {
            BottomBorderL=Xsite;
            break;
        }
    }
    for (Xsite =ImageSensorMid ; Xsite < LCDW; Xsite++)//����Ļ�м����ұ��ұ���
    {
        if(Image_Pixel[LCDH-1][Xsite]==0 && Image_Pixel[LCDH-1][Xsite+1]==0)
        {
            BottomBorderR=Xsite;
            break;
        }
        else if (Xsite==LCDW-1)//�Ҳ������������ڵ��������һ����Ϊ���ߵ�
        {
            BottomBorderR=Xsite;
            break;
        }
    }

    ImageDeal[LCDH-1].LeftBorder=BottomBorderL;//��¼�����
    ImageDeal[LCDH-1].RightBorder=BottomBorderR;//��¼�ұ���
    ImageDeal[LCDH-1].Center=(ImageDeal[LCDH-1].LeftBorder+ImageDeal[LCDH-1].RightBorder)/2;//��¼����
    ImageDeal[LCDH-1].Wide=ImageDeal[LCDH-1].RightBorder-ImageDeal[LCDH-1].LeftBorder;//��¼�������
    //ImageDeal[LCDH-1].IsLeftFind=0;//��¼����߱�־λ�����Ƿ������ҵ�
    //ImageDeal[LCDH-1].IsRightFind=0;//��¼�ұ��߱�־λ�����Ƿ������ҵ�

    //�ٴӵڶ��п�ʼ����4����//Ϊʲô����д������Զ�����ң�
    //��ֱ��ֱ�ӽ�������Ϊͼ��߶Ⱦ������˰ɣ�
    for (Ysite = LCDH-2 ; Ysite>=0 ; Ysite--)
    {
        for (Xsite = ImageDeal[Ysite+1].Center; Xsite > 0; Xsite--)//����ɨ��
        {
            if(Image_Pixel[Ysite][Xsite]==0 && Image_Pixel[Ysite][Xsite-1]==0)//ɨ���Ǵӽ�����Զ��ɨ������Ϊ��0�У���������ͷ��Զ���ǵ�0�У�
            {
                BottomBorderL=Xsite;
                break;
            }
            else if (Xsite==0+1)//�Ҳ������������ڵ��������һ����Ϊ���ߵ�
            {
                BottomBorderL=Xsite;
                break;
            }
        }
        ImageDeal[Ysite].LeftBorder=Xsite;//��¼�����

        for (Xsite = ImageDeal[Ysite+1].Center; Xsite < LCDW; Xsite++)//����ɨ��
        {
            if(Image_Pixel[Ysite][Xsite]==0 && Image_Pixel[Ysite][Xsite+1]==0)//ɨ���Ǵӽ�����Զ��ɨ������Ϊ��0�У���������ͷ��Զ���ǵ�0�У�
            {
                BottomBorderR=Xsite;
                break;
            }
            else if (Xsite==LCDW-1)//�Ҳ������������ڵ��������һ����Ϊ���ߵ�
            {
                BottomBorderR=Xsite;
                break;
            }
        }
        ImageDeal[Ysite].RightBorder=Xsite;//��¼�ұ���

        ImageDeal[Ysite].Center=(ImageDeal[Ysite].LeftBorder+ImageDeal[Ysite].RightBorder)/2;//��¼����
        ImageDeal[Ysite].Wide=ImageDeal[Ysite].RightBorder-ImageDeal[Ysite].LeftBorder;//��¼�������
        //ImageDeal[Ysite].IsLeftFind=0;//��¼����߱�־λ�����Ƿ������ҵ�
        //ImageDeal[Ysite].IsRightFind=0;//��¼�ұ��߱�־λ�����Ƿ������ҵ�
    }
}


void draw_midline(void)
{
    int i,temp;
    for(i=59;i>=0;i--)
    {
        temp=ImageDeal[i].Center;
        Image_Pixel[i][temp]=0;
    }

}
//*******************************************************************************************************************
//���籣����һ��������Χ�ڿ����Ķ�ֵ��ͼ��ȫ��/����ĳ���ٷֱȼ��ж�Ϊ���硪������1��ʾ���磬����Ϊ0���Ż���ֻ���жϣ����Ʋ�������������������������ָ�����
//�Լ���ģ������Ĳ�һ��������ͳ���˺ڵ�Ͱ׵��ٶ��⴦����û����
//uint8 Protect_Without_Road(uint8 StartLine,uint8 EndLine)
//{
//    int i,j;
//    uint16 BlackDotNum=0;
//    for(i=StartLine;i<EndLine;i++)
//    {
//        for(j=0;j<LCDW;j++)
//        {
//            if(Image_Pixel[i][j]==0||mt9v03x_image[50][ImageSensorMid==0])
//            {
//                BlackDotNum++;
//            }
//        }
//    }
//    if(BlackDotNum >= (int)0.75*(EndLine-StartLine)*LCDW)
//    {
//        return 1;
//    }
//    else
//    {
//        return 0;
//    }
//}

uint8 outadge_protect(uint8 StartLine,uint8 EndLine,uint8 StartRow,uint8 EndRow)
{
    int i,j;
    int BlackdotNum=0;
    for(i=StartLine;i<EndLine;i++)
    {
        for(j=StartRow;j<EndRow;j++)
        {
            if(Image_Pixel[i][j]==0)
            {
                BlackdotNum++;
            }
        }
    }
    if(BlackdotNum>=(int)(0.75*(EndLine-StartLine)*(EndRow-StartRow)))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void Get_AllLine(){}//��ӵĲ���//���������ߣ������Ż���5����������Ļ���������ߣ���ô��Χ�˸������������������ò����İɣ�

//*******************************************************************************************************************
//ֱ���жϡ�ԭ����̫��⹫ʽ���塿
//С��1�ж�Ϊֱ����intǿת��Ϊ0������������ж�
float Judge_Straight(uint8 choice , uint8 StartLine , uint8 EndLine)
{
    int i;//����ѭ��
    float S = 0,//��?��
          sum = 0, //����
          err = 0, //���
          k = 0;//ֱ������б��
    switch (choice)
    {
        case 1:
            k = (float)(ImageDeal[StartLine].LeftBorder - ImageDeal[EndLine].LeftBorder) / (StartLine - EndLine);
            for (i = 0; i < EndLine - StartLine; i++)
            {
                //ע����������Ǹ�ƽ������
                err = (ImageDeal[StartLine].LeftBorder + k * i - ImageDeal[i + StartLine].LeftBorder) * (ImageDeal[StartLine].LeftBorder + k * i - ImageDeal[i + StartLine].LeftBorder);
                sum += err;
            }
            S = sum / (EndLine - StartLine);
            break;
        case 2:
            k = (float)(ImageDeal[StartLine].RightBorder - ImageDeal[EndLine].RightBorder) / (StartLine - EndLine);
            for (i = 0; i < EndLine - StartLine; i++)
            {
                err = (ImageDeal[StartLine].RightBorder + k * i - ImageDeal[i + StartLine].RightBorder) * (ImageDeal[StartLine].RightBorder + k * i - ImageDeal[i + StartLine].RightBorder);
                sum += err;
            }
            S = sum / (EndLine - StartLine);
            break;
    }
    return S;
}

//*******************************************************************************************************************
//��ֱ���жϡ��á���־λ
void Judge_Long_Straight()
{
    //if(������־λ�������壬���ж��Ѿ�Ϊ����Ԫ����)
    //return��//�˳�����
    if(Judge_Straight(1,10,50)<=1 && Judge_Straight(2,10,50)<=1)//���Ļ�and��OFFLine��Miss_Left_lines��Miss_Right_lines���ж�
    {
        ImageFlag.LongStraight=1;
    }
}

//*******************************************************************************************************************
//��ֱ���жϡ�ȡ���á���־λ
void Handle_Long_Straight()
{
    if(ImageFlag.LongStraight==1)
    {
        if(Judge_Straight(1,10,50)>1 && Judge_Straight(2,10,50)>1)//������Ԫ�صı�־λ�Ļ��Ͱ�ImageFlag.LongStraight��0
            //���Ļ�||��OFFLine��Miss_Left_lines��Miss_Right_lines���ж�
        {
            ImageFlag.LongStraight=0;
        }
    }
}

//*******************************************************************************************************************
//��ȡ���ߺͱ�������T(��������) W(�ޱ���) H(������)
//p��?
//type��L �� R����ʾ����ɨ�� �� ����ɨ��
//H��L��ͼ������������޺�����
//Q��?
//���ģ�����PicTemp(PicTemp�Ǹ�ָ�룬ָ��һ������)��IntervalLow�п�ʼɨ��ɨ��IntervalHigh�У�Ȼ��ѵõ��ı������ڵ��кͱ������ͼ�¼��JumpPoint�ṹ���С���
void GetBorder_And_GetBorederType(uint8* p,uint8 type,uint8 H,uint8 L,JumpPointTypedef* Q)
{
    uint8 i = 0;
    if (type == 'L')                                    //���type��L(Left),���������ɨ������ߡ�
    {
    for (i = H; i >= L; i--)                            //����(��������H)������������L��ɨ
        {
            if (*(p + i) == 1 && *(p + i - 1) == 0)     //����кڰ����䡪������1�ǰ� 0�Ǻ�
            {
                Q->point = i;                           //�ǾͰ�����м�¼������Ϊ�����
                Q->type = 'T';                          //���Ұ���һ�е������������䣬�������ͼ�ΪT��������������
                break;                                  //�ҵ��˾�����ѭ��������
            }
          //********************************
            else if (i == (L + 1))                      //Ҫ��ɨ�����û�ҵ�
            {
                if (*(p + (L + H) / 2) != 0)            //����ɨ��������м��ǰ����ص�
                {
                  Q->point = (L + H) / 2;               //��ô����Ϊ��һ�е�������Ǵ�����ɨ��������е㡣
                  Q->type = 'W';                        //���Ұ���һ�е����Ƿ��������䣬�������ͼ�ΪW�����ޱ��С�
                  break;                                //����ѭ��������
                }
                //*********************************
                else                                    //Ҫ��ɨ�����û�ҵ�������ɨ��������м��Ǻ����ص�
                {
                  Q->point = H;                         //��ô����Ϊ��һ�е�������Ǵ�����ɨ��������������ޡ�
                  Q->type = 'H';                        //����Ҳ����һ�е����Ƿ��������䣬�����������ͼ�ΪH�����������С�
                  break;                                //����ѭ��������
                }
            }
        }
    }
    //*******************************************************************************
    else if (type == 'R')                         //���type��R(Right),��ɨ���ұ��ߡ�
    {
        for (i = L; i <= H; i++)                    //��������ɨ
        {
            if (*(p + i) == 1 && *(p + i + 1) != 1)   //����кڰ�����    1�ǰ� 0�Ǻ�
            {
              Q->point = i;                           //�ǾͰ�����м�¼������Ϊ�ұ���
              Q->type = 'T';                          //���Ұ���һ�е������������䣬�������ͼ�ΪT��������������
              break;                                  //�ҵ��˾�����ѭ��������
            }
            else if (i == (H - 1))                    //Ҫ��ɨ�����û�ҵ�
            {
                if (*(p + (L + H) / 2) != 0)            //����ɨ��������м��ǰ����ص�
                {
                    Q->point = (L + H) / 2;               //��ô����Ϊ��һ�е��ұ����Ǵ�����ɨ��������е㡣
                    Q->type = 'W';                        //���Ұ���һ�е����Ƿ��������䣬�������ͼ�ΪW�����ޱ��С�
                    break;
                }
                else                                    //Ҫ��ɨ�����û�ҵ�������ɨ��������м��Ǻ����ص�
                {
                    Q->point = L;                         //��ô����Ϊ��һ�е��ұ����Ǵ�����ɨ��������������ޡ�
                    Q->type = 'H';                        //����Ҳ����һ�е����Ƿ��������䣬�����������ͼ�ΪH�����������С�
                    break;                                //����ѭ��������
                }
            }
        }
    }
}

//*******************************************************************************************************************
//ͼ����������������ִ������ͼ���Ӻ���
void Image_Mother_Function()
{
    if(mt9v03x_finish_flag==1)
    {
        //��־λ�ж�
        //ͼ�����Ӻ���
    }
    mt9v03x_finish_flag=0;//�����־λ�Դ�����һ֡ͼ��
}


