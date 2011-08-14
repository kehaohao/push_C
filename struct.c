#include<stdio.h>//Must be noticed stuct has a whole function;

#include<string.h>

    struct techer
    {
        char name[20];
        int count;
    };
    struct student
    {
        long num;
        char name[20];
        int count;
        char sex;
        float score;
        struct student *h;//表示指向结构体的指针；
        struct techer  *k;
    };
    typedef struct student STU;
    typedef struct techer  TEC;

int main(int argc, const char *argv[])
{
    STU stu_1;
    STU stu_2;
    TEC techer_1;
//   STU *p = &stu_1;
     stu_2.h = &stu_2;
   
   /* student->h = &stu_1;
    p = student->h;*/
    stu_1.num = 10086;
    stu_2.num = 10087;
    strcpy(stu_1.name,"Li Lin");
    strcpy(stu_2.name,"kehao");
    stu_1.sex = 'M';
    stu_2.sex = 'W';
    stu_1.score = 99.8;
    printf("No:%ld\nname: %s\nsex: %c\nscore: %f\n",(*p).num,(*p).name,(*p).sex,(*p).score);
    
    printf("No:%ld\nname: %s\nsex: %c\nscore: %f\npalace: %d\n",p->num,p->name,p->sex,p->score,p->h);
 
   printf("%x\n",p->h);
   printf("No:%ld\n",stu_2.h->num);
   printf("%d\n",sizeof(stu_2));
   printf("%s\n",(*stu_2.h).name);
   printf("%x\n",stu_2.h->h);
   return 0;
}


