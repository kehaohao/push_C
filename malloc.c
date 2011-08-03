#include<stdio.h>
#include <stdlib.h>//
#include<string.h>
    struct student
    {
        long num;
        char name[20];
        int count;
        char sex;
         float  score;
      //  struct student *h;//表示指向结构体的指针；
       // struct techer  *k;
    };
    typedef struct student STU;
int main(int argc, const char *argv[])
{
    STU m;    
    STU *ptr;
   // int score= 0;
    ptr = malloc(sizeof(STU));
    if(ptr == NULL)
    {
        perror("malloc");
        exit(0);
    }
    ptr->num = 9;
    strcpy(ptr->name , "kehao");
    ptr->score = 100;
    printf("%d",sizeof(m));
    printf("%ld\n%s\n%f\n",ptr->num,ptr->name,ptr->score);

    return 0;
}
