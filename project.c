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
    printf("������������Ŀ��������n��(n<=20)\n");
    while(scanf("%d",&boy)!=1||boy<0||boy>20)
    {
        printf("����������������룡\n");
        fflush(stdin);
    }
    printf("������Ů����Ŀ��������n��(n<=20)\n");
    while(scanf("%d",&girl)!=1||girl<0||girl>20)
    {
        printf("����������������룡\n");
        fflush(stdin);
    }
    *maxboy=boy;
    *maxgirl=girl;
    p=calloc(sizeof(struct project),boy+girl);
    printf("��ʼ���ɹ���\n");
    return p;
}

void ShowProject(PROJECT p,const int countboy,const int countgirl,const int maxboy)
{
    if(countboy==0&&countgirl==0)
    {
        printf("�����Ѵ�������Ŀ\n");
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
                printf("(Ů��)");
            }
            else
            {
                printf("(����)");
            }
            printf("%s  ",p[count].name);
            if(p[count].isinput==1)
            {
                printf("�ɼ�������\n");
            }
            else
            {
                printf("�ɼ�δ����\n");
            }
        }
    }
}

void AppendProject(PROJECT p,int *countboy,int*countgirl,const int maxboy,const int maxgirl)
{
    fflush(stdin);
    int Error=0;
    int* count=malloc(sizeof(int));
    printf("������ӵ���ĿΪ(1��������Ŀ 2��Ů����Ŀ):\n");
    int sex;
    while(scanf("%d",&sex)!=1||(sex!=1&&sex!=2))
    {
        printf("����������������룡\n");
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
    printf("��������Ŀ�����ƣ�\n");
    while(*gets(p[*count].name)=='\0');
    if(sex==1)
    {
        for(int i=0; i<*count; i++)
        {
            if(strcmp(p[*count].name,p[i].name)==0)
            {
                printf("�����ظ����룡\n");
                goto BACK;
            }
        }
    }
    p[*count].isinput=0;
    printf("��ӳɹ���\n");
    free(count);
    if(Error==1)
    {
END:
        printf("��Ŀ�Ѵﵽ���������\n");
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
