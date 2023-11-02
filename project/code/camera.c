/*
 * camera.c
 *
 *  Created on: 2023年8月15日
 *      Author: Ming
 */
#include "camera.h"
#include "math.h"
//用于extern的变量的定义***********************************************************************************
uint8 Image_True[LCDH][LCDW];//实际图像（灰度图）//实际数据从哪里传进来？
uint8 Image_Pixel[LCDH][LCDW];                         //二值化处理后的图像
uint8 LeftLine[LCDH];                                  //存放每行左边线
uint8 RightLine[LCDH];                                 //存放每行右边线
uint8 MidLine[LCDH];                                   //存放每行中线
ImageDealDatatypedef ImageDeal[LCDH];//存放处理后图像每一行信息
//ImageStatustypedef  ImageStatus;
ImageFlagtypedef ImageFlag;
//*************************************************************************

uint8* Image_Use[LCDH][LCDW];//指针变量

int BottomBorderL;//最底行的左边线点
int BottomBorderR;//最底行的右边线点
int BottomCenter;//最底行的中点
int Xsite,Ysite;//临时变量，Xsite为图像的某列，Ysite为图像的某行

//用一个数组记录直道的半宽？uint8 Half_Straight_Wide[LCDH]={};
//用一个数组记录弯道的半宽？uint8 Half_Bend_Wide[LCDH]={};

//获取边线和边线类型函数
//补线函数Get_ExtraLine(){}根据标志位判断要不要补线及跳转到补线函数
//上交大左右手法扫线？
//sobel？
//元素判断函数：左圆环（圆环用电磁循迹简单点）、右圆环、坡道、左右弯道、路障、斑马线、左右车库Element_Judge(){}
//标志位清零初始化void Flag_Init(){}

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
//图像初始化并压缩图像函数（将摄像头读到的图像导入要用于处理的图像数组里）【ok】
void Image_CompressInit(void)
{
    float Mh = MT9V03X_H;           //摄像头的行数
    float Mw = MT9V03X_W;           //摄像头的列数
    float Lh = LCDH;                //用于处理的行数
    float Lw = LCDW;                //用于处理的列数

    int i, j, row, line;
    const float div_h = Mh / Lh,    //根据原始的图像尺寸和你所需要的图像尺寸确定好压缩比例
                div_w = Mw / Lw;
    for (i = 0; i < LCDH; i++)      //遍历赋值
    {
      row = i * div_h + 0.5;    //+0.5相当于四舍五入，例如，i*divh得到的是1.4，最后row得到1.9(row是int型实际取1)；得到的是1.5，最后得到2 (row是int型实际取2)
      for (j = 0; j < LCDW; j++)
      {
        line = j * div_w + 0.5;
        Image_Use[i][j] = &mt9v03x_image[row][line];//Image_Use[][]是一个指针变量数组，&取了mt9v03x_image[][]的地址
//        Image_True[i][j] = mt9v03x_image[row][line];
      }
    }
///*最初写的遍历把摄像头数据取出来：
//    uint8 i,j;
//    for(i=0;i<LCDH;i++)
//    {
//        for(j=0;j<LCDW;j++)
//        {
//            Image_True[i][j] = mt9v03x_image[i][j];
////            Image_Use[i][j] = &mt9v03x_image[i][j];     //Image_Use[][]是一个指针变量数组，&取了mt9v03x_image[][]的地址
//        }
//    }
//*/
}

//*******************************************************************************************************************
//大津法求二值化阈值（跟余夏有细微区别）
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
 for (i = 0; i < GrayScale; i++)                    //先把pixelCount和pixelPro两个数组元素全部赋值为0
 {
   pixelCount[i] = 0;
   pixelPro[i] = 0;
 }

 uint32 gray_sum = 0;
 /**************************************统计每个灰度值(0-255)在整幅图像中出现的次数**************************************/
 for (i = 0; i < height; i += 1)                   //遍历图像的每一行，从第零行到第59行。
 {
   for (j = 0; j < width; j += 1)                  //遍历图像的每一列，从第零列到第79列。
   {
     pixelCount[*image[i][j]]++;       //将当前的像素点的像素值（灰度值）作为计数数组的下标。
     gray_sum += *image[i][j];         //计算整幅灰度图像的灰度值总和。
   }
 }
 /**************************************统计每个灰度值(0-255)在整幅图像中出现的次数**************************************/



 /**************************************计算每个像素值（灰度值）在整幅灰度图像中所占的比例*************************************************/
 for (i = 0; i < GrayScale; i++)
 {
     pixelPro[i] = (float)pixelCount[i] / pixelSum;
 }
 /**************************************计算每个像素值（灰度值）在整幅灰度图像中所占的比例**************************************************/



 /**************************************开始遍历整幅图像的灰度值（0-255），这一步也是大津法最难理解的一步***************************/
 /*******************为什么说他难理解？因为我也是不理解！！反正好像就是一个数学问题，你可以理解为数学公式。***************************/
 float w0, w1, u0tmp, u1tmp, u0, u1, u, deltaTmp, deltaMax = 0;
 w0 = w1 = u0tmp = u1tmp = u0 = u1 = u = deltaTmp = 0;
 for (j = 0; j < GrayScale; j++)
 {
   w0 += pixelPro[j];                          //求出背景部分每个灰度值的像素点所占的比例之和，即背景部分的比例。
   u0tmp += j * pixelPro[j];

   w1 = 1 - w0;
   u1tmp = gray_sum / pixelSum - u0tmp;

   u0 = u0tmp / w0;                            //背景平均灰度
   u1 = u1tmp / w1;                            //前景平均灰度
   u = u0tmp + u1tmp;                          //全局平均灰度
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
//灰度图用大津法得到的阈值进行二值化处理
void Get_BinaryImage()
//余夏还多了对标志位的判断，给不同阈值？什么用？(猜想：例如像转弯时会看到很大一片蓝背景，算上这部分的话阈值就会偏小)
{
    uint8 i,j=0;
//    uint8 threshold_0=100;
    uint8 threshold_0=Get_Threshold(Image_Use,LCDW,LCDH);

    for(i=0;i<LCDH;i++)
    {
        for(j=0;j<LCDW;j++)
        {
            if(*Image_Use[i][j] > threshold_0 )//Get_Threshold的第一个参数是指针类型的//*Image_Use可能有问题
                Image_Pixel[i][j]=255;//大于阈值设置为1，即白
            else
                Image_Pixel[i][j]=0;//小于阈值设置为0，即黑
        }
    }
}

//*******************************************************************************************************************
//获取图像最底行的边线及接下来最底2、3、4、5行的边线
//从底行屏幕中心往两边找(两个for)，找到连续两个黑点就说明找到了边线
void Get_BaseLine(){//为什么余夏写的是由远往近找？
    for (Xsite =ImageSensorMid ; Xsite > 0; Xsite--)//从屏幕中间向左边找边线
    {
        if(Image_Pixel[LCDH-1][Xsite]==0 && Image_Pixel[LCDH-1][Xsite-1]==0)//扫线是从近端向远端扫，近端为第0行；但读摄像头是远端是第0行？
        {
            BottomBorderL=Xsite;
            break;
        }
        else if (Xsite==0+1)//找不到连续两个黑点则把最左一点作为边线点
        {
            BottomBorderL=Xsite;
            break;
        }
    }
    for (Xsite =ImageSensorMid ; Xsite < LCDW; Xsite++)//从屏幕中间向右边找边线
    {
        if(Image_Pixel[LCDH-1][Xsite]==0 && Image_Pixel[LCDH-1][Xsite+1]==0)
        {
            BottomBorderR=Xsite;
            break;
        }
        else if (Xsite==LCDW-1)//找不到连续两个黑点则把最右一点作为边线点
        {
            BottomBorderR=Xsite;
            break;
        }
    }

    ImageDeal[LCDH-1].LeftBorder=BottomBorderL;//记录左边线
    ImageDeal[LCDH-1].RightBorder=BottomBorderR;//记录右边线
    ImageDeal[LCDH-1].Center=(ImageDeal[LCDH-1].LeftBorder+ImageDeal[LCDH-1].RightBorder)/2;//记录中线
    ImageDeal[LCDH-1].Wide=ImageDeal[LCDH-1].RightBorder-ImageDeal[LCDH-1].LeftBorder;//记录赛道宽度
    //ImageDeal[LCDH-1].IsLeftFind=0;//记录左边线标志位——是否正常找到
    //ImageDeal[LCDH-1].IsRightFind=0;//记录右边线标志位——是否正常找到

    //再从第二行开始再找4行线//为什么余夏写的是由远往近找？
    //跑直道直接将行数定为图像高度就能跑了吧？
    for (Ysite = LCDH-2 ; Ysite>=0 ; Ysite--)
    {
        for (Xsite = ImageDeal[Ysite+1].Center; Xsite > 0; Xsite--)//向左扫线
        {
            if(Image_Pixel[Ysite][Xsite]==0 && Image_Pixel[Ysite][Xsite-1]==0)//扫线是从近端向远端扫，近端为第0行；但读摄像头是远端是第0行？
            {
                BottomBorderL=Xsite;
                break;
            }
            else if (Xsite==0+1)//找不到连续两个黑点则把最左一点作为边线点
            {
                BottomBorderL=Xsite;
                break;
            }
        }
        ImageDeal[Ysite].LeftBorder=Xsite;//记录左边线

        for (Xsite = ImageDeal[Ysite+1].Center; Xsite < LCDW; Xsite++)//向右扫线
        {
            if(Image_Pixel[Ysite][Xsite]==0 && Image_Pixel[Ysite][Xsite+1]==0)//扫线是从近端向远端扫，近端为第0行；但读摄像头是远端是第0行？
            {
                BottomBorderR=Xsite;
                break;
            }
            else if (Xsite==LCDW-1)//找不到连续两个黑点则把最右一点作为边线点
            {
                BottomBorderR=Xsite;
                break;
            }
        }
        ImageDeal[Ysite].RightBorder=Xsite;//记录右边线

        ImageDeal[Ysite].Center=(ImageDeal[Ysite].LeftBorder+ImageDeal[Ysite].RightBorder)/2;//记录中线
        ImageDeal[Ysite].Wide=ImageDeal[Ysite].RightBorder-ImageDeal[Ysite].LeftBorder;//记录赛道宽度
        //ImageDeal[Ysite].IsLeftFind=0;//记录左边线标志位——是否正常找到
        //ImageDeal[Ysite].IsRightFind=0;//记录右边线标志位——是否正常找到
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
//出界保护：一个行数范围内看到的二值化图像全黑/超过某个百分比即判断为出界——返回1表示出界，否则为0；优化：只做判断，控制部分在其他函数里，这样功能区分更明显
//自己想的，跟余夏不一样。余夏统计了黑点和白点再额外处理？还没看到
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

void Get_AllLine(){}//最复杂的部分//八邻域搜线？可以优化成5领域吗？自屏幕下向上搜线，那么周围八个像素中下面三个是用不到的吧？

//*******************************************************************************************************************
//直线判断【原理？不太理解公式含义】
//小于1判断为直道，int强转就为0，便可以用于判断
float Judge_Straight(uint8 choice , uint8 StartLine , uint8 EndLine)
{
    int i;//用于循环
    float S = 0,//【?】
          sum = 0, //误差和
          err = 0, //误差
          k = 0;//直道边线斜率
    switch (choice)
    {
        case 1:
            k = (float)(ImageDeal[StartLine].LeftBorder - ImageDeal[EndLine].LeftBorder) / (StartLine - EndLine);
            for (i = 0; i < EndLine - StartLine; i++)
            {
                //注意下面这句是个平方运算
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
//长直道判断【置】标志位
void Judge_Long_Straight()
{
    //if(其他标志位都有意义，即判断已经为其他元素了)
    //return；//退出函数
    if(Judge_Straight(1,10,50)<=1 && Judge_Straight(2,10,50)<=1)//余夏还and了OFFLine、Miss_Left_lines、Miss_Right_lines的判断
    {
        ImageFlag.LongStraight=1;
    }
}

//*******************************************************************************************************************
//长直道判断【取消置】标志位
void Handle_Long_Straight()
{
    if(ImageFlag.LongStraight==1)
    {
        if(Judge_Straight(1,10,50)>1 && Judge_Straight(2,10,50)>1)//有其他元素的标志位的话就把ImageFlag.LongStraight置0
            //余夏还||了OFFLine、Miss_Left_lines、Miss_Right_lines的判断
        {
            ImageFlag.LongStraight=0;
        }
    }
}

//*******************************************************************************************************************
//获取边线和边线类型T(正常边线) W(无边行) H(大跳变)
//p：?
//type：L 或 R，表示往左扫线 或 往右扫线
//H、L：图像列区间的上限和下限
//Q：?
//余夏：“从PicTemp(PicTemp是个指针，指向一个数组)的IntervalLow列开始扫，扫到IntervalHigh列，然后把得到的边线所在的列和边线类型记录到JumpPoint结构体中。”
void GetBorder_And_GetBorederType(uint8* p,uint8 type,uint8 H,uint8 L,JumpPointTypedef* Q)
{
    uint8 i = 0;
    if (type == 'L')                                    //如果type是L(Left),则从右往左扫描左边线。
    {
    for (i = H; i >= L; i--)                            //从右(区间上限H)往左（区间下限L）扫
        {
            if (*(p + i) == 1 && *(p + i - 1) == 0)     //如果有黑白跳变————1是白 0是黑
            {
                Q->point = i;                           //那就把这个列记录下来作为左边线
                Q->type = 'T';                          //并且把这一行当作是正常跳变，边线类型记为T，即边线正常。
                break;                                  //找到了就跳出循环不找了
            }
          //********************************
            else if (i == (L + 1))                      //要是扫到最后都没找到
            {
                if (*(p + (L + H) / 2) != 0)            //并且扫描区间的中间是白像素点
                {
                  Q->point = (L + H) / 2;               //那么就认为这一行的左边线是传进来扫描区间的中点。
                  Q->type = 'W';                        //并且把这一行当作是非正常跳变，边线类型记为W，即无边行。
                  break;                                //跳出循环不找了
                }
                //*********************************
                else                                    //要是扫到最后都没找到，并且扫描区间的中间是黑像素点
                {
                  Q->point = H;                         //那么就认为这一行的左边线是传进来扫描区间的区间上限。
                  Q->type = 'H';                        //并且也把这一行当作是非正常跳变，不过边线类型记为H，即大跳变行。
                  break;                                //跳出循环不找了
                }
            }
        }
    }
    //*******************************************************************************
    else if (type == 'R')                         //如果type是R(Right),则扫描右边线。
    {
        for (i = L; i <= H; i++)                    //从左往右扫
        {
            if (*(p + i) == 1 && *(p + i + 1) != 1)   //如果有黑白跳变    1是白 0是黑
            {
              Q->point = i;                           //那就把这个列记录下来作为右边线
              Q->type = 'T';                          //并且把这一行当作是正常跳变，边线类型记为T，即边线正常。
              break;                                  //找到了就跳出循环不找了
            }
            else if (i == (H - 1))                    //要是扫到最后都没找到
            {
                if (*(p + (L + H) / 2) != 0)            //并且扫描区间的中间是白像素点
                {
                    Q->point = (L + H) / 2;               //那么就认为这一行的右边线是传进来扫描区间的中点。
                    Q->type = 'W';                        //并且把这一行当作是非正常跳变，边线类型记为W，即无边行。
                    break;
                }
                else                                    //要是扫到最后都没找到，并且扫描区间的中间是黑像素点
                {
                    Q->point = L;                         //那么就认为这一行的右边线是传进来扫描区间的区间下限。
                    Q->type = 'H';                        //并且也把这一行当作是非正常跳变，不过边线类型记为H，即大跳变行。
                    break;                                //跳出循环不找了
                }
            }
        }
    }
}

//*******************************************************************************************************************
//图像处理主函数，用于执行所有图像子函数
void Image_Mother_Function()
{
    if(mt9v03x_finish_flag==1)
    {
        //标志位判断
        //图像处理子函数
    }
    mt9v03x_finish_flag=0;//清除标志位以处理下一帧图像
}


