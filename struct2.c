#include<stdio.h>
struct 
{
    char name[20];
    int count;
}student[3] = {"guojiao",0,"kehao",0,"wangpan",0};
int main(int argc, const char *argv[])
{
    char student_1[20];
    int i = 0;
    int j = 0;
    for(i =0 ; i < 10; i ++)
    { 
        scanf("%s",student_1);
        for(j =0 ;j < 3; j ++)
        {
            if( strcmp(student_1,student[j].name) == 0)
            {
                student[i].count ++;
            }

        }
        printf("\n");
    }
    for(i =0 ; i < 10 ; i ++)
    {
         printf("guojiao: %2d\nkehao: %2d\n wanngpan: %2d\n ",student[0].count,student[1].count,student[2].count );
    }
    return 0;
}
