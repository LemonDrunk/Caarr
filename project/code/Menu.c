/*
 * Menu.c
 *
 *  Created on: 2023年10月18日
 *      Author: 23913
 */
#include "zf_common_headfile.h"
#include "pid.h"
#define BEEP                (C13)
    float t=164;
    uint Key_all_flag=0;
    uint8 loop = 0;
    uint8 count_beep = 0;
    key_index_enum key_index_array[KEY_NUMBER] = {KEY_1,KEY_2,KEY_3,KEY_4};
void key_read(void){

    for(loop = 0; loop < 4; loop ++)
    {
        switch(key_get_state(key_index_array[loop]))                        // 获取按键状态
        {
            case KEY_CHECK_SHOCK:
                count_beep = 1;
                break;
            case KEY_SHORT_PRESS:                                           // 短按状态
                if(25 > count_beep)
                {
                    gpio_set_level(BEEP, GPIO_HIGH);                        // BEEP 响
                    *KEY_STATE[loop]=KEY_SHORT_PRESS;

                }
                else
                {
                    gpio_set_level(BEEP, GPIO_LOW);                         // BEEP 停
                    *KEY_STATE[loop]=KEY_RELEASE;
                }
                break;
            case KEY_LONG_PRESS:                                            // 长按状态
                if(50 > count_beep)
                {
                    gpio_set_level(BEEP, GPIO_HIGH);                        // BEEP 响
                    *KEY_STATE[loop]=KEY_LONG_PRESS;

                }
                else
                {
                    gpio_set_level(BEEP, GPIO_LOW);                         // BEEP 停
                    *KEY_STATE[loop]=KEY_RELEASE;
                }
                break;
            default:
                break;
        }
    }
    if( KEY_RELEASE == key_get_state(key_index_array[0]) && \
        KEY_RELEASE == key_get_state(key_index_array[1]) && \
        KEY_RELEASE == key_get_state(key_index_array[2]) && \
        KEY_RELEASE == key_get_state(key_index_array[3]))//如果所有的按键都没有值
    {
        gpio_set_level(BEEP, GPIO_LOW);                                     // BEEP 停

    }
    count_beep = ((count_beep != 100) ? (count_beep + 1) : (1));
    system_delay_ms(5);
}
void KEY_S_Clear(void){
    KEY_1S=0;
    KEY_2S=0;
    KEY_3S=0;
}
void TFT_Init(void){
       tft180_set_dir(TFT180_PORTAIT);
       tft180_set_font(TFT180_8X16_FONT);
       tft180_set_color(RGB565_RED, RGB565_BLACK);
       tft180_init();
}

typedef struct{
    int16 menu_id;
    char func[30];
    void (*menu_action)(float *param, char func[30]);
    float *param;
}menu_item;

menu_item* new_menu=0;
void menu_11(void){
    tft180_clear();
    //执行任务项
}



void menu_action(float *param,char func[30])
{

       char buf[30]; // 存放名称
       char *menu_name = func;
       static int current_level = 0;
       float level[4] = {0.01, 0.1, 1, 10};//调节挡位
//       SEGGER_RTT_printf(0, "\r\n%s: %5.2f", menu_name, *param);
       // 用来传控制台观测
//       tft180_full(RGB565_GRAY);
//       tft180_show_string(0, 16*0, "Change_level:");
//       sprintf(buf, "X%5.2f: ", level[current_level]);
//       //把level[current_level]按格式写到字符数组buf,将会显示“X LEVEL:”
//       tft180_show_string(0, 16*1, buf);

       while (1)
       {
           int clear_once_flag=1;
           tft180_show_string(0, 16*3, "Key4_Level");
           sprintf(buf, "%s: ", menu_name);
           tft180_show_string(0, 16*1, buf);
           sprintf(buf, "%5.2f", *param);
           tft180_show_string(0, 16*2, buf);
               while(KEY_4S>1)
               {

                   tft180_show_string(0, 16*0, "CHANGING LEVEL");
                   tft180_show_float(0, 16*1, level[current_level], 4, 4);
                   if(clear_once_flag==1){
                       tft180_clear();
                       clear_once_flag=0;
                   }

                   if (KEY_1S>1)
                   {
                                  current_level=1;
                                  KEY_1S=0;

                    }
                   if (KEY_2S>1)
                   {
                                  current_level=2;
                                  KEY_2S=0;

                    }
               }

                                                   if (KEY_1S>1)
                                                   {
                                                       *param +=level[current_level];
                                                       KEY_1S=0;
                                                   }
                                                   else if (KEY_2S>1)
                                                   {
                                                       *param -= level[current_level];
                                                       KEY_2S=0;
                                                   }

       }
}


menu_item menus[]={
        {1,"MODE PID",NULL,NULL},
        {2,"Set T",menu_action,&t},
        {11,"Set MotorL_PID",NULL,NULL},
        {12,"Set_MotorR_PID",NULL,NULL},
        {121,"Set RMotor_P",menu_action,&Motor_Right_PID.Kp},
        {122,"Back To Main",NULL,NULL},
        {111,"Set LMotor_P",menu_action,&Motor_Left_PID.Kp},
        {112,"Back To Main",NULL,NULL}
};

bool judge_menu(int menu_id) // 查看是否存在子菜单
{
    for (int i = 0; i < sizeof(menus) / sizeof(menus[0]); i++)
    {
        if (menus[i].menu_id / 10 == menu_id)
        {
            return true;
        }
    }
    return false;
}

int show_sub_menu(int parent_id, int highlight_col) // 显示子菜单，以及当前高亮菜单
{

    int item_idx =0;
    for (int i = 0; i < sizeof(menus) / sizeof(menus[0]); i++)
    {
        if (menus[i].menu_id / 10 == parent_id)//如果有子菜单
        {
            if (item_idx == highlight_col)
            {
                new_menu = &menus[i];
                tft180_set_color(RGB565_RED,RGB565_WHITE);

            }
            else
            {
                tft180_set_color(RGB565_BLACK,RGB565_WHITE);
            }
            tft180_show_string(0, 16*item_idx, menus[i].func);//显示子菜单
            item_idx++;//有子菜单，返回1
        }
    }
    return item_idx;
}

void Menu_Switch(void)
{

   static int parent_menu_id = 0;
   static int highlight_col = 0; // 设定高亮行号
   show_sub_menu(parent_menu_id, highlight_col);
    while ((KEY_3S||KEY_2S||KEY_1S)!=0)
    {

                            if (KEY_1S>1) // 按下按键1增加当前行数
                            {
                                highlight_col=1;
                                KEY_1S=0;
                            }
                            else if (KEY_2S>1) // 按下按键2减少当前行数
                            {
                                highlight_col=0;
                                KEY_2S=0;
                            }
                            else if (KEY_3S>1)
                            {
                                if (judge_menu(new_menu->menu_id))//如果有次级菜单
                                {
                                    highlight_col = 0;
                                    parent_menu_id = new_menu->menu_id;
                                    KEY_3S=0;
                                }
                                else if (strcmp(new_menu->func, "Back to Main") == 0) // 如果当前菜单为“Back to Main”，则返回主界面
//                                    strcmp(new_menu->func, "Back to Main") == 0
                //strcmp:判断两个字符串大小:返  回  值：str1 = str2   则返回0，str1 > str2  则返回大于0的值， str1 < str2  则返回小于0的值
                                {

                                    highlight_col = 0;
                                    parent_menu_id = 0;

                                }
                                else if (new_menu->menu_action)
                                {
                                    tft180_clear();
                                    new_menu->menu_action(new_menu->param, new_menu->func);
                                }


                           }

    }
}
//写着玩
