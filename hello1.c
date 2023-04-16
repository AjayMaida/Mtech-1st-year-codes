#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
struct student
{
    int rollno;
    int age;
    struct student *next;
};
struct student *start =NULL;
char ch;
struct student * nn(int rollno,int age)
{
    struct student *p1=(struct student *)malloc(sizeof(struct student));
    p1->rollno=rollno;
    p1->age=age;
    p1->next=NULL;
    return p1;
}
void add()
{
    int rollno,age;
    
    do
    {
        printf("enter rollno");
        scanf("%d",&rollno);
        printf("enter age");
        scanf("%d",&age);
        struct student *temp=nn(rollno,age);
        struct student *t1=start;
        if(t1==NULL)
        {
            start=temp;
        }
        else
        {
            while(t1->next!=NULL)
            {
                t1=t1->next;
            }
            t1->next=temp;
        }
        printf("enter choice (y/n)");
        scanf("%c",&ch);
        printf("%c",ch);
    }while(ch=='y');
    
}

void display()
{
    struct student *t1=start;
    if(t1==NULL)
    {
        printf("LL is empty");
    }
    else
    {
        while(t1!=NULL)
        {
            printf("%d->%d\n",t1->rollno,t1->age);
            t1=t1->next;
        }
    }
}
int main()
{
    add();
    display();
}