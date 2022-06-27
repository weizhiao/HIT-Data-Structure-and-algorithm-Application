#include"project.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

PROJECT MakeProject(int*maxboy,int*maxgirl,int*countboy,int*countgirl)
{
    *countboy=0;
    *countgirl=0;
    int boy,girl;
    PROJECT p;
    printf("请输入男子项目的最大个数n：(n<=20)\n");
    while(scanf("%d",&boy)!=1||boy<0||boy>20)
    {
        printf("输入错误，请重新输入！\n");
        fflush(stdin);
    }
    printf("请输入女子项目的最大个数n：(n<=20)\n");
    while(scanf("%d",&girl)!=1||girl<0||girl>20)
    {
        printf("输入错误，请重新输入！\n");
        fflush(stdin);
    }
    *maxboy=boy;
    *maxgirl=girl;
    p=calloc(sizeof(struct project),boy+girl);
    printf("初始化成功！\n");
    return p;
}

void ShowProject(PROJECT p,const int countboy,const int countgirl,const int maxboy)
{
    if(countboy==0&&countgirl==0)
    {
        printf("暂无已创建的项目\n");
    }
    else
    {
        for(int i=0; i<(countboy+countgirl); i++)
        {
            int count=i;
            printf("%d  ",i+1);
            if(i>=countboy)
            {
                count=i+maxboy-countboy;
                printf("(女生)");
            }
            else
            {
                printf("(男生)");
            }
            printf("%s  ",p[count].name);
            if(p[count].isinput==1)
            {
                printf("成绩已输入\n");
            }
            else
            {
                printf("成绩未输入\n");
            }
        }
    }
}

void AppendProject(PROJECT p,int *countboy,int*countgirl,const int maxboy,const int maxgirl)
{
    fflush(stdin);
    int Error=0;
    int* count=malloc(sizeof(int));
    printf("您想添加的项目为(1、男生项目 2、女生项目):\n");
    int sex;
    while(scanf("%d",&sex)!=1||(sex!=1&&sex!=2))
    {
        printf("输入错误，请重新输入！\n");
        fflush(stdin);
    }
    if(sex==1)
    {
        if(*countboy==maxboy)
        {
            Error=1;
            goto END;
        }
        *count=*countboy;
        (*countboy)++;
    }
    else
    {
        if(*countgirl==maxgirl)
        {
            Error=1;
            goto END;
        }
        *count=*countgirl+maxboy;
        (*countgirl)++;
    }
    getchar();
BACK:
    printf("请输入项目的名称：\n");
    while(*gets(p[*count].name)=='\0');
    if(sex==1)
    {
        for(int i=0; i<*count; i++)
        {
            if(strcmp(p[*count].name,p[i].name)==0)
            {
                printf("请勿重复输入！\n");
                goto BACK;
            }
        }
    }
    p[*count].isinput=0;
    printf("添加成功！\n");
    free(count);
    if(Error==1)
    {
END:
        printf("项目已达到最大数量！\n");
    }
}

int Rank(struct project p,int n)
{
    int rank=-1;
    for(int i=0; i<p.count; i++)
    {
        if(n==p.Institute[i])
        {
            rank=i;
        }
    }
    return rank+1;
}
