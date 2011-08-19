#include<stdio.h>
#include"various.h"
/**********************************************************
 * 函数功能：从四个方位检测该棋子的方位上有连续的4可棋子；
 * 参数功能：x,y 
 * 返回值  ：返回who 的值为player 1或2,表示棋局结束，返回0表示棋局没结束；
 ***********************************************************/
int check(int x,int y)
{ 
     int i = 0;
     int j = 0;
     char who = chess_board[x +y*X_NUM];
     int counter = 1;
     if(who == 0)
     {
         return 0;
     }
     
     for(i=1;i < 5;i++)
     {
         if(chess_board[x+i +y*X_NUM] == who)
	 {
	      counter ++;
	 }
	 else
	 {
	     break;
	 }

     }
     if(counter ==5)
     {
           return who;
     }
//////////////////////     
     counter = 1;i = 0;j = 0;
     for(i =1,j = -1;i < 5;i ++,j --)
     {
         if(chess_board[x+i +(y+j)*X_NUM] == who)
	 {
	     counter ++;
	 }
         else
	 {
	     break;
	 }
     }
     if(counter == 5)
     {
         
         return who;
     }
     counter = 1;i =0 ;j = 0;
///////////
     for(j = 1;j < 5; j ++)
     {
         if(chess_board[x+i +(y+j)*X_NUM] == who)
	 {
	     counter ++;
	 }
         else
	 {
	     break;
	 }
     }
     if(counter == 5)
     {
         
         return who;
     }
/////////////// 
     counter = 1;i = 0; j = 0;
     
     for(j = 1,i = 1;j < 5; j ++,i ++)
     {
         if(chess_board[x+i +(y+j)*X_NUM] == who)
	 {
	     counter ++;
	 }
         else
	 {
	     break;
	 }
     }
     if(counter == 5)
     {
         
         return who;
     }
     
     return 0;
}


/***********************************
 * 函数功能：当一个棋子放入之后，保存该棋子的标志值，然后对棋盘范围内虽有的              点进行检测；
 * 参数    ：x,y
 * 返回值  ：winner 表示赢了，0表示还没完
 *************************************/
int chess_put(int x,int y) //save
{
    int i = 0;
    int j = 0;
    int winner = 0;
 
    chess_board[x +y*X_NUM] = player;
   
    //judge winner;
    for(j =0; j < Y_NUM; j ++)
    {
        for(i = 0 ; i < X_NUM ; i++)
	{
	    if((winner = check(i, j)) > 0)//屏幕上的每个点都检查了一遍；
	    {
	        return winner;
	    }
	}
    }
    return 0 ;
}

/**********************************************
 * 函数功能：
 * 参数功能：
 *
 *********************************************/
int chess_doing(void)
{
    int rx = (mx - ST_X)%SPACE ;
    int ry = (my - ST_Y)%SPACE ;
    int cx = mx -rx;
    int cy = my -ry;
    if(mx < ST_X || mx > ST_X +(X_NUM - 1)*SPACE)
    {
        return 0;
    }

    if(my < ST_Y || my > ST_Y +(Y_NUM - 1)*SPACE)
    {
        return 0;
    }

    if(rx >SPACE/2)
    {
        cx += SPACE;
    }
    if(ry >SPACE/2)
    {
        cy += SPACE;
    }
    fb_round(cx,cy,15,current_color);	
    int  winner;

    winner = chess_put((cx - ST_X)/SPACE,(cy -ST_Y)/SPACE);
    if(winner > 0)
    {
        return winner;    
    }

    if(current_color == WHITE)
    {
        current_color = BLACK;
	player = 1;
    }
    else
    {
        current_color = WHITE;
	player  = 2;
    }


    return 0;
}
