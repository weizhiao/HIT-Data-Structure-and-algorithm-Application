#include"institute.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

INSTITUTE MakeInstitute(int*max,int*countinstitute)
{
    *countinstitute=0;
    int n;
    printf("请输入学院的最大个数：\n");
    while(scanf("%d",&n)!=1||n<0||n>20)
    {
        printf("输入错误，请重新输入！\n");
        fflush(stdin);
    }
    *max=n;
    INSTITUTE a=calloc(sizeof(struct institute),n);
    for(int i=0; i<n; i++)
    {
        a[i].BoySum=0;
        a[i].GirlSum=0;
        a[i].L=MakeNull();
    }
    printf("初始化成功！\n");
    return a;
}

int FindInstituteName(char name[],INSTITUTE a,const int countinstitute)
{
    int n=-1;
    for(int i=0; i<countinstitute; i++)
    {
        if(strcmp(name,a[i].name)==0)
        {
            n=i;
        }
    }
    return n;
}

void ShowAllInstituteSum(INSTITUTE a,const int countinstitute)
{
    if(countinstitute==0)
    {
        printf("暂无已创建的学院!\n");
    }
    else
    {
        for(int i=0; i<countinstitute; i++)
        {
            printf("%d  %s的总分为：%d\n",i+1,a[i].name,a[i].BoySum+a[i].GirlSum);
        }
    }
}

void ShowInstitute(struct institute a)
{
    printf("学院的名称为：%s\n",a.name);
    printf("男生项目的总分为：%d\n",a.BoySum);
    printf("女生项目的总分为：%d\n",a.GirlSum);
    printf("所有项目的总分为：%d\n",a.BoySum+a.GirlSum);
}

void ShowAllInstitute(INSTITUTE a,const int countinstitute)
{
    for(int i=0; i<countinstitute; i++)
    {
        printf("%d  ",i);
        ShowInstitute(a[i]);
        printf("\n");
    }
}

INSTITUTE CopyInstitute(INSTITUTE a,const int countinstitute)
{
    INSTITUTE temp=malloc(countinstitute*sizeof(struct institute));
    for(int i=0; i<countinstitute; i++)
    {
        temp[i]=a[i];
    }
    return temp;
}

INSTITUTE SortName(INSTITUTE a,const int countinstitute)
{
    INSTITUTE a1=CopyInstitute(a,countinstitute);
    struct institute temp;
    for(int i=0; i<countinstitute-1; i++)
    {
        for(int j=0; j<countinstitute-i-1; j++)
        {
            if(strcmp(a1[j].name,a1[j+1].name)>0)
            {
                temp=a1[j];
                a1[j]=a1[j+1];
                a1[j+1]=temp;
            }
        }
    }
    return a1;
}

int Compare(int n,struct institute a1,struct institute a2)
{
    if(n==3)
    {
        return (a1.BoySum+a1.GirlSum)<(a2.BoySum+a2.GirlSum);
    }
    else if(n==4)
    {
        return a1.BoySum<a2.BoySum;
    }
    else
    {
        return a1.GirlSum<a2.GirlSum;
    }
}

INSTITUTE SortScore(INSTITUTE a,int n,const int countinstitute)
{
    INSTITUTE a1=CopyInstitute(a,countinstitute);
    {
        for(int i=0; i<countinstitute-1; i++)
        {
            for(int j=0; j<countinstitute-i-1; j++)
            {
                if(Compare(n,a[j],a[j+1]))
                {
                    struct institute temp=a1[j];
                    a1[j]=a1[j+1];
                    a1[j+1]=temp;
                }
            }
        }
    }
    return a1;
}

void ShowSortInstitute(INSTITUTE a,const int countinstitute)
{
    INSTITUTE temp;
    INSTITUTE temp1;
    INSTITUTE temp2;
    INSTITUTE temp3;
    if(countinstitute==0)
    {
        printf("暂无已创建的学院\n");
    }
    else
    {
        printf("请选择学院排序的方式：1、编号 2、名称 3、所有项目总分 4、男生项目总分 5、女生项目总分\n");
        int n;
        while(scanf("%d",&n)!=1||(n!=1&&n!=2&&n!=3&&n!=4&&n!=5))
        {
            printf("输入错误，请重新输入！\n");
            fflush(stdin);
        }
        switch(n)
        {
        case 1:
            ShowAllInstitute(a,countinstitute);
            break;
        case 2:
            temp=SortName(a,countinstitute);
            ShowAllInstitute(temp,countinstitute);
            free(temp);
            break;
        case 3:
            temp1=SortScore(a,3,countinstitute);
            ShowAllInstitute(temp1,countinstitute);
            free(temp1);
            break;
        case 4:
            temp2=SortScore(a,4,countinstitute);
            ShowAllInstitute(temp2,countinstitute);
            free(temp2);
            break;
        case 5:
            temp3=SortScore(a,5,countinstitute);
            ShowAllInstitute(temp3,countinstitute);
            free(temp3);
            break;
        }
    }
}

void AppendInstitute(INSTITUTE a,int *countinstitute,const int max)
{
    fflush(stdin);
    if(*countinstitute<max)
    {
BACK:
        printf("请输入学院%d的名称：\n",*countinstitute+1);
        while(*gets(a[*countinstitute].name)=='\0');
        for(int i=0; i<*countinstitute; i++)
        {
            if(strcmp(a[*countinstitute].name,a[i].name)==0)
            {
                printf("请勿重复输入！\n");
                goto BACK;
            }
        }
        (*countinstitute)++;
        printf("添加成功！\n");
    }
    else
    {
        printf("学院已达到最大数量！\n");
    }
}
