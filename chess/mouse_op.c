#include<stdio.h>
#include"various.h"
#include<fcntl.h>//open的头文件
#include<unistd.h>//write read 的头文件
#include <stdlib.h>//exit的头文件
#define BORD   0x0000ffff
#define X___   0x000fffff
#define T___   0x00000000
#define C_W    10
#define C_H    17

char press_do ;//按键设置位
u32_t bg[C_H*C_W] = {0};

static u32_t curser_pixel[C_W*C_H] = 
{
    BORD,T___,T___,T___,T___,T___,T___,T___,T___,T___,
    BORD,BORD,T___,T___,T___,T___,T___,T___,T___,T___,
    BORD,X___,BORD,T___,T___,T___,T___,T___,T___,T___,
    BORD,X___,X___,BORD,T___,T___,T___,T___,T___,T___,
    BORD,X___,X___,X___,BORD,T___,T___,T___,T___,T___,

    BORD,X___,X___,X___,X___,BORD,T___,T___,T___,T___,
    BORD,X___,X___,X___,X___,X___,BORD,T___,T___,T___,
    BORD,X___,X___,X___,X___,X___,X___,BORD,T___,T___,
    BORD,X___,X___,X___,X___,X___,X___,X___,BORD,T___,
   
    BORD,X___,X___,X___,X___,X___,X___,X___,X___,BORD,
    BORD,X___,X___,X___,X___,X___,BORD,BORD,BORD,BORD,
    BORD,X___,X___,BORD,X___,X___,BORD,T___,T___,T___,
    BORD,X___,BORD,T___,BORD,X___,X___,BORD,T___,T___,
    BORD,BORD,T___,T___,BORD,X___,X___,BORD,T___,T___,
    T___,T___,T___,T___,T___,BORD,X___,X___,BORD,T___,
   
    T___,T___,T___,T___,T___,BORD,X___,X___,BORD,T___,
    T___,T___,T___,T___,T___,T___,BORD,BORD,T___,T___,
};

int draw_cursorint(int x,int y)
{
       int i = 0;
       int j = 0;
       save_bg(x,y);
       for(i = 0;i < C_H;i ++)
       {
            for(j = 0;j < C_W; j ++)
	    {
	        fb_one_pixel(x+j, y+i, curser_pixel[j+i*C_W]);
	    }
       }
      return 0;

}

int save_bg(int x ,int y)//保存当前的背景；
{
     int i ;
     int j ;
     for(j =0; j < C_H; j ++)
     {
         for(i = 0; i < C_W; i ++)
	 {
	      bg[i + j*C_W] =*((u32_t *)fb_v.memo + x +i + (y +j)*fb_v.w );
	 }
     }
     return 0;
}

int restore_bg(int x,int y)
{
      
       int i = 0;
       int j = 0;
       for(i = 0;i < C_H;i ++)
       {
            for(j = 0;j < C_W; j ++)
	    {
	         
	        fb_one_pixel(x+j, y+i, bg[j+i*C_W]);//将原来的背景恢复；
	    }
       }
      return 0;
}

int get_mouse_info(int fd,mouse_event *p)
{
    char buf[8];
    int n = 0;
    n = read(fd,buf,3);
    if(n > 0)
    {
        p->dx = buf[1];
	p->dy = -buf[2];
	p->button = (buf[0] & 0x07);
    }
    return n;
}

int mouse_doing(void)
{
    int fd = 0;

    mouse_event  m_e;
    fd = open("/dev/input/mice",O_RDWR|O_NONBLOCK);
    if(fd == -1)
    {

         perror("mice");
	 exit(0);
    }
     
    mx = fb_v.w/3;
    my = fb_v.h/2;

     
    draw_cursorint(mx,my);

    while(1)
    {
        if(get_mouse_info(fd,&m_e) > 0)
	{
	    restore_bg(mx,my);

	    mx += m_e.dx;
	    my += m_e.dy;

	    if(mx < 0)
	    {
	       mx = 0;
	    }
	    if(mx > (fb_v.w - C_W))
	    {
		mx = fb_v.w - C_W;
	    }

	    if(my < 0)
	    {
	       my= 0;
	    }
	    if(my > (fb_v.h - C_H))
	    {
		my = fb_v.h - C_H;
	    }
    
	  //  save_bg(mx,my);
	   switch(m_e.button)
	   {
	       case 0:
	       if(press_do == 1)
	       {
	           press_do = 0;
		   chess_doing();
		 //  fb_round(mx,my,15,0x0000ff00);
	       }
	       if(press_do == 2)
	       {
	           press_do = 0;
		   fb_round(mx,my,15,0x00ffffff);
	       }
               if(press_do == 3)
	       {
	           press_do = 0;
                    fb_round(mx,my,15,0x000000ff);
	       } 
	       break;

	       case 1:  
	            press_do = 1;  break;
	       case 2: press_do = 2;break;
	       case 3: press_do = 3;break;
	       default : break; 
	   }
	   draw_cursorint(mx,my);//确保鼠标最后放置；
	}
    }
    return 0;
}






