#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

struct Q
{
    struct student
    {
        char name[50];
        int roll;
        int sem;
        char dept[50];
        float gpa;
    }s[10],temp;
    int rear;
    int front;
    int count;
};
void INS(struct Q* a)
{
    if(a->count==SIZE)
        printf("The Queue is Full!\n");
    else
    {
        (a->rear)=((a->rear)+1)%SIZE;
            printf("Enter your name: ");
            getchar();
            gets(a->s[a->rear].name);
            printf("Enter your Roll No: ");
            scanf("%d",&a->s[a->rear].roll);
            printf("Enter your semester: ");
            scanf("%d",&a->s[a->rear].sem);
            printf("Enter your department: ");
            getchar();
            gets(a->s[a->rear].dept);
            printf("Enter your GPA: ");
            scanf("%f",&a->s[a->rear].gpa);
            for(int i=0;i<=a->rear;i++)
            {
                for(int j=i+1;j<=a->rear;j++)
                {
                    if(a->s[j].gpa > a->s[i].gpa)
                    {
                        a->temp=a->s[j];
                        a->s[j]=a->s[i];
                        a->s[i]=a->temp;
                    }
                }
            }
            (a->count)++;
    }
}
void DEL(struct Q* a)
{
    if(a->count==0)
        printf("No student is there!\n");
    else
    {

        printf("The student is requested to choose your Subject!\nName: ");
        puts(a->s[a->front].name);
        printf("Roll No.: %d\nSemester: %d\nDepartment: ",a->s[a->front].roll,a->s[a->front].sem);
        puts(a->s[a->front].dept);
        printf("GPA: %4.2f\n",a->s[a->front].gpa);
        a->front=((a->front)+1)%SIZE;
        (a->count)--;
    }
}
void display(struct Q* a)
{
    if(a->count==0)
        printf("No Student has applied yet!\n");
    else
    {
        printf("The GPA Sorted Students:\n");
        int i= a->front;
        int c=0;
        while(c++<a->count)
        {
            printf("Name: ");
            puts(a->s[i].name);
            printf("Roll No.: %d\nSemester: %d\nDepartment: ",a->s[i].roll,a->s[i].sem);
            puts(a->s[i].dept);
            printf("GPA: %4.2f\n",a->s[i].gpa);
            i=(i+1)%SIZE;
        }
    }
    printf("\n");
}
int main()
{
    struct Q a;
    a.rear=-1;
    a.front=0;
    a.count=0;
    int ch;
    do
    {
        printf("1.Enroll now(Insertion)\n2.Ask for result(Deletion)\n3.Display the sorted list\n0.Exit\nEnter your choice: ");


        scanf("%d",&ch);
        switch(ch)
        {
        case 1:
            INS(&a);
            break;
        case 2:
            DEL(&a);
            break;
        case 3:
            display(&a);
            break;
        case 0:
            printf("Thank you!\n");
            exit(0);
        default:
            printf("Sorry, try again!\n");
        }
    }while(ch);
}
