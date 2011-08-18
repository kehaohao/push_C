#include<stdio.h>
#include <stdlib.h>//exit()的头文件；
#include <fcntl.h> //open的头文件；
#include <linux/fb.h>//参数FBIOGET_VSCREENINFO的头文件；
#include <sys/ioctl.h>
#include <sys/mman.h>
#include"happy.h"
fbfcr_t fb_v;
int init_date()
{
    int fd;
    struct fb_var_screeninfo fb_var;
    fd =open("/dev/fb0",O_RDWR);//打开内核里面的内容
    if(fd < 0)
    {
       perror("open fb0");
       exit(0);
    }
    if(ioctl(fd,FBIOGET_VSCREENINFO,&fb_var) < 0)
    {
        perror("ioctl");
	exit(0);
    }
    fb_v.w = fb_var.xres;
    fb_v.h = fb_var.yres;
    fb_v.bpp = fb_var.bits_per_pixel;
    printf("w= %d\t h= %d \t bpp= %d\n",fb_var.xres,fb_var.yres,fb_var.bits_per_pixel);
   // printf("enter the car");
    fb_v.memo = mmap(NULL,fb_v.w*fb_v.h*fb_v.bpp/8,PROT_READ|PROT_WRITE,MAP_SHARED,fd,0);  //fp表示该函数的映射，后面的参数为映射的起始地址；
  /*  if(fb_v.memo == MAP_FAILED)
    {
        perror("memo");
	exit(0);
    }
    while(1);*/
    int i ;
    int j ;
    u32_t *p = fb_v.memo; //直接对该指针指向的内容进行操作；
    for(j = 0; j < fb_v.h ; j ++)
    {
	for(i =0 ; i < fb_v.w ;i ++)
	{
	    p[i + j*fb_v.h] = 0x000000ff;
	}
	for(i =0 ; i < fb_v.h; i ++)
	{
	    p[i*fb_v.w + j*fb_v.w] = 0x00ff0000;

	}
    }
    return 0;
}
