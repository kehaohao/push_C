#include<stdio.h>
#include"various.h"

void set_backgrond(u32_t color)//设置背景颜色；
{
    int i = 0;
    int j = 0;
    for(i =20 ; i < fb_v.h -30 ; i ++)
    {
         for(j = 0;j < fb_v.w ; j ++)
	 {
	   
             fb_one_pixel(j,i,color);
	 }
    }
}

void print_board(u32_t color)
{
    int i = 0;
    set_backgrond(YELLOW);
    for(i =0 ;i < Y_NUM; i ++)
    {
         fb_line(ST_X,ST_Y + i*SPACE,ST_X +(X_NUM - 1)*SPACE,ST_Y + i*SPACE, color);
    }
    for(i = 0; i < X_NUM ; i ++)
    {
        fb_line(ST_X + i*SPACE ,ST_Y, ST_X + i*SPACE, ST_Y +(Y_NUM - 1)*SPACE,color);
    }
}
