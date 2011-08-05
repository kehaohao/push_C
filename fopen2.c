
#include<stdio.h>
#include<stdlib.h>

int main(int argc, const char *argv[])
{
   
    FILE *fp = NULL;
    char prgre[1024] ={0} ;
    int x = 0;
    char arry[1024] = " best\nkehao";
    fp = fopen("hh.c","w+");
    // printf(arry);
    if(fp == NULL)
    {
        perror("error");
        exit(0);
    }
   // fscanf(stdin,"%s",prgre);
   // fprintf(stdout,"%s\n",prgre);
               
   //   fgets(prgre,1023,stdin);
    //  fputs(prgre,stdout);
    int i = 0;
    while(arry[i] != '\0')
    { 
        putc(arry[i],fp);
        i ++;
    }
    rewind(fp);  //指示器复位
    i = 0;
   // fp = fopen("hh.c","r");
    while((prgre[i] = getc(fp)) != EOF)
    {
        i ++; 
    }
    prgre[i] = '\0';
  //  printf("%s\n",prgre);
    
    puts(prgre);
   // fputs(arry,fp);
    // fscanf(fp,"%s\n",prgre);
    // x = fgetc(fp);
    //  printf("%d\n",x);
   // fclose(fp);
   // fp = fopen("hh.c","r+");
   // fgets(prgre,1023,fp);
     
 //     gets(prgre);
 //     fputs(prgre,fp);
 //    puts(prgre);
 //    puts(arry);
      
   // printf("%s\n",prgre);
    // fprintf(fp,"%s\n",arry);
    //  fputs(arry,fp);
    //  printf("%s\n",prgre);
    fclose(fp);
    return 0;
}


