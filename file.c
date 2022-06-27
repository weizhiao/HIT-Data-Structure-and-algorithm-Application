#include<stdio.h>
#include<stdlib.h>
#include"file.h"

FILE*Open()
{
    FILE *fp;
    if((fp=fopen("data.txt","r"))==NULL)
    {
        printf("Failure to open data.txt!\n");
        system("pause");
        exit(0);
    }
    return fp;
}

void ReadArrayfromFile(int array[],FILE *fp)
{
    for(int i=0; !feof(fp)&&i<6; i++)
    {
        fread(&array[i],sizeof(int),1,fp);
    }
}

void ReadProjectfromFile(const int max,PROJECT p,FILE *fp)
{
    for(int i=0; !feof(fp)&&i<max; i++)
    {
        fread(&p[i],sizeof(struct project),1,fp);
    }
}

void ReadInstitutefromFile(const int max,INSTITUTE a,FILE *fp)
{
    for(int i=0; !feof(fp)&&i<max; i++)
    {
        fread(&a[i],sizeof(struct institute),1,fp);
        a[i].L=MakeNull();
    }
}

void WritetoFile(PROJECT p,INSTITUTE a,int array[])
{
    FILE *fp;
    if((fp=fopen("data.txt","w"))==NULL)
    {
        printf("Failure to open data.txt!\n");
        exit(0);
    }
    fwrite(array,sizeof(int),6,fp);
    fwrite(p,sizeof(struct project),array[0]+array[1],fp);
    fwrite(a,sizeof(struct institute),array[2],fp);
    fclose(fp);
    printf("文件写入完成！\n");
}

void RecoverList(INSTITUTE a,PROJECT p,const int countboy,const int countgirl,const int maxboy)
{
    for(int i=0; i<(countboy+countgirl); i++)
    {
        int count=i;
        if(i>=countboy)
        {
            count=i+maxboy-countboy;
        }
        if(p[count].isinput==1)
        {
            for(int j=0; j<p[count].count; j++)
            {
                AppendLast(a[p[count].Institute[j]].L,count);
            }
        }
    }
}
