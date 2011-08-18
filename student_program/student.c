#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct student
{
    int num;
    char name[20];
    struct student *next;
};
typedef struct student STU;

STU *delete_node(STU *head)
{
    STU *p = head;
    STU *ptr = NULL;
    ptr = malloc(sizeof(STU));
    if(NULL == ptr)
    {
        perror("error");
        exit(0);
    }
    printf("please enter the delete num:\n");
    scanf("%d",&ptr->num);

    getchar();
    if(p == NULL)
    {
        printf("empty");
        return head;
    }
    if(ptr->num == p->num)
    {
        p = p->next;
        return p;
    }
    while(p->next != NULL)
    {
        if(ptr->num == p->next->num)
        {
            break;
        }
        p = p->next;
    }
    if(p->next == NULL)
    {
        printf("no this number\n");
        return head;
    }
    ptr = p->next;
    p->next = p->next->next;
    free(ptr);
    return head;

}

STU *Delete_Node(STU *head)
{
    STU *p = head;
    STU *ptr = NULL;
    int number = 0;
    printf("please delete the num:\n");
    scanf("%d",&number);
    getchar();
    if(p == NULL)
    {
        printf("empty \n");
        return head;
    }
    if(number == p->num)
    {
        p = p->next;
        return p;
    }
    while( (p->next !=NULL) &&(p->next->num != number))
    {
        p = p->next;
    }
    if( p->next == NULL)
    {
        printf("no this number\n");
        return head;
    }
    ptr = p->next;
    p->next = p->next->next;
    free(ptr);
    return head;
    

}

STU *read_link(void)
{
    STU *head = NULL;
    STU *p1 = NULL;   
    int number = 0;
    char iname[20];
    FILE *fp = fopen("1.txt","r+");  //
    if(NULL == fp)
    {
        perror("error!");
        exit(0);
    }
    if(fscanf(fp,"%s%d",iname,&number) == EOF)
    {
        return NULL;
    } 
    head = p1 = malloc(sizeof(STU));
    if(NULL == head)
    {
        perror("error");
	exit(0);
    }
    head->num = number;
    strncpy(head->name,iname,19);
    p1->next = NULL;
    
    while(fscanf(fp,"%s%d",iname,&number) != EOF)
    {
        p1->next = malloc(sizeof(STU));
	if(NULL == p1->next)
	{
	    perror("error");
	    exit(0);
	}
	p1->next->num = number;
        strncpy(p1->next->name,iname,19);
	p1->next->next = NULL;
        p1 = p1->next;
	
    }
    fclose(fp);
    return head;

    
}

STU *add_node(STU *head)
{
   
    STU *p = NULL;
    STU *ptr = head;
    p =  malloc(sizeof(STU));
    if(NULL == p)
    { 
        perror("error");
        exit(0);
    }

    printf("please enter a num:\n");
    scanf("%d",&p->num);
    printf("please enter a name:\n");
    scanf("%s",p->name);

    getchar(); //值得注意，

    if(head == NULL)
    {
         head = p;
        return head;
    }
    if(p->num < head->num)
    {
        p->next = head;
        return p;
    }
    while((ptr->next !=NULL) && (p->num > ptr->next->num))
    {
        ptr = ptr->next;
    }
    p->next = ptr->next;
    ptr->next = p;
    return head;

}


void show_link(STU *p)
{
    if(p == NULL)
    {
        printf("empty\n");
    }
    while(p != NULL)
    {
        printf("%5d  %s\n",p->num,p->name);
        p = p->next;
    }
}


void save_link(STU *p)             //将链表中的数据存入硬盘中；
{
    FILE *fp = fopen("1.txt","w+");//打开一个文件；
    if(NULL == fp)
    {
        perror("error");
        exit(0);
    }
    while(NULL != p)
    {
         fprintf(fp,"%5d  %s\n",p->num,p->name);//向该指针所知向的文件中写入数据；
         p = p->next;
    }
    fclose(fp);                   //关闭该指针指向的文件；
}

void menu()
{
    puts("please enter your choice:");
    puts("1.add_node");
    puts("2.delete_node");
    puts("3.show_link");
    puts("4.save_link");
    puts("5.exit program");
}

int main(int argc, const char *argv[])
{
    STU *head = NULL;
    char choice = 0;
    char  flag = 1;

    head = read_link();
    while(flag > 0)
    {
        menu();              
        choice = getchar();//get date from slowarea
        getchar();   //读缓从区中的数据
        printf("%d\n",choice);
        switch(choice)
        {
           case '1':head = add_node(head);break;//开辟一个指针，建立一个节点
           case '2':head = Delete_Node(head);break;
           case '3': show_link(head);break;
           case '4': save_link(head); break;
           case '5':flag = 0;break;
           default :break;

        }
       // print_link(rear);
    }
    return 0;
}
