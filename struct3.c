#include<stdio.h>
#include<string.h>

    struct midir
    {
        long num;
        char name[20];
        int count;
    };
    struct techer
    {
        long num; 
        char name[20];
        int count;
        struct midir *gg;
    };
    struct student
    {
        long num;
        char name[20];
        int count;
       // char sex;
       // float score;
        struct techer *h;//表示指向结构体的指针；
      //  struct techer  *k;
    };
    typedef struct student STU;
    typedef struct techer  TEC;
    typedef struct midir  MID;
int main(int argc, const char *argv[])
{
    STU m;
    TEC n;
    MID b;
    STU *ptr = NULL;
    ptr = &m;
    ptr->h = &n;
    ptr->h->gg = &b;

    ptr->num = 8;
    strcpy(ptr->name,"kehao");
    ptr->h->count = 10;
    strcpy(ptr->h->name,"xumeng");

    ptr->h->gg->num = 11;
    strcpy(ptr->h->gg->name,"liangpengcheng");

    printf("%ld\n%s\n",ptr->num,ptr->name);
    printf("%d\n%s\n",ptr->h->count,ptr->h->name);
    printf("%d\n%s\n",ptr->h->gg->num,ptr->h->gg->name);
    printf("%d\n%d\n%d\n",sizeof(m),sizeof(n),sizeoof(b));

    return 0;
}
