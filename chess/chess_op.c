#include<stdio.h>
#include"various.h"


int chess_put(int x,int y)
{ 
    chess_board[x +y*X_NUM] = player;

    return 0 ;
}


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
    chess_put((cx - ST_X)/SPACE,(cy -ST_Y)/SPACE);
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
