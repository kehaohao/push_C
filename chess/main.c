#include<stdio.h>
#include"happy.h"
#include"various.h"
#include<unistd.h>
int main(int argc, const char *argv[])
{       
        init_date();
	int i ,j;
//	int W = 0;
//	int H = 0;
	for(i =0 ;i < fb_v.w;i ++)
	{
	    for(j =0;j < fb_v.h; j ++)
	    {
	        fb_one_pixel(i,j,0xff000000);
	    }
	}
/*	fb_line(0,0,fb_v.w-1,fb_v.h-1,0x000000ff);
	fb_line(fb_v.w -1,0,0,fb_v.h-1,0x000000ff);

       fb_line(fb_v.w - 700,0,0,fb_v.h-1,0x00ff0000);
*/ /*    int lan;
       for(lan = 0;lan < fb_v.w; lan += 30)
       {
           fb_line(0+lan,0,0+lan,fb_v.w-1,0x0000ff00);
       }
     *///  fb_round(500,300,100,0x0000ff00);
        
        print_board(0x0000f00);
/*	puts("please  place the location:\n");
	scanf("%4d %4d",&W,&H);
	fb_round(W,H,15,0x0000ff00);
       // fb_round(30*5,30*10,15,0x00ffffff);*/
      /*  save_bg(300,150);
        draw_cursorint(300,150);
	sleep(1);
	restore_bg(300,150);
        draw_cursorint(600,300); */
        mouse_doing();

          	
	return 0;
}
