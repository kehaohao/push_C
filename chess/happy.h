#ifndef _HAPPY_H_			
#define _HAPPY_H_
#define u8_t unsigned char
#define u32_t unsigned int 
#define Y_NUM  24
#define X_NUM  29
#define ST_X   30
#define ST_Y   30
#define SPACE  30

#define BLACK 0x00000fff
#define WHITE 0x00ffffff
typedef struct
{
    int w;
    int h;
    int bpp;
    void *memo;//可以指向任何类型的指针
}fbfcr_t;

typedef struct
{
    int dx;
    int dy;
    char button;
}mouse_event;

int init_date(void);
int fb_one_pixel(int x,int y,u32_t color);
int fb_line(int x1,int y1,int x2,int y2,u32_t color);
int fb_round(int x0,int y0,int r,u32_t color);
void print_board(u32_t color);
int draw_cursorint(int x,int y);
int save_bg(int x ,int y);
int restore_bg(int x,int y);
int mouse_doing(void);
int chess_doing(void);
int chess_put(int x,int y);
#endif
