#include<stdio.h>
#include<string.h>
#include <stdlib.h>//exit()的头文件；
#include <fcntl.h> //open的头文件；
#include <linux/fb.h>//参数FBIOGET_VSCREENINFO的头文件；
#include <sys/ioctl.h>
#include <sys/mman.h>
#include"happy.h"
fbfcr_t fb_v;

int mx;
int my;

char chess_board[X_NUM*Y_NUM];
char player;
u32_t current_color;


int init_date()
{
    int fd;
    struct fb_var_screeninfo fb_var; 
    fd =open("/dev/fb0",O_RDWR);//打开内核里面屏幕设备文件中的内容
    if(fd < 0)
    {
       perror("open fb0");
       exit(0);
    }
    if(ioctl(fd,FBIOGET_VSCREENINFO,&fb_var) < 0)//将返回值为fd的设备文件中的信息映射到内存缓从区&fb_var中；如果映射成功，返回值大于0;
    {
        perror("ioctl");
	exit(0);
    }
    fb_v.w = fb_var.xres;
    fb_v.h = fb_var.yres;
    fb_v.bpp = fb_var.bits_per_pixel;
    printf("w= %d\t h= %d \t bpp= %d\n",fb_var.xres,fb_var.yres,fb_var.bits_per_pixel);
   // printf("enter the car");
    fb_v.memo = mmap(NULL,fb_v.w*fb_v.h*fb_v.bpp/8,PROT_READ|PROT_WRITE,MAP_SHARED,fd,0);  //fp表示该函数的映射，后面的参数为映射的起始地址,NULL表示内存有系统来开辟，2.内存映射函数；
    if(fb_v.memo == MAP_FAILED)
    {
        perror("memo");
	exit(0);
    }
    memset(fb_v.memo,0,fb_v.w*fb_v.h*fb_v.bpp/8);//0表示清屏的背景色为黑色
    memset(chess_board,0,X_NUM*Y_NUM);

    current_color = BLACK;
    player = 1;
// while(1);
//    int j ;
  //  for(j = 0; j < fb_v.h ; j = j + 50)
   // }

    return 0;
}
