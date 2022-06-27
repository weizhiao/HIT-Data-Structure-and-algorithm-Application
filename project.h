#ifndef _project_H_
#define _project_H_
#include"institute.h"
struct project
{
    int count;
    int isinput;
    char name[10];
    int Institute[5];
};

typedef struct project* PROJECT;
PROJECT MakeProject(int*maxboy,int*maxgirl,int*countboy,int*countgirl);
void AppendProject(PROJECT p,int *countboy,int*countgirl,const int maxboy,const int maxgirl);
void ShowProject(PROJECT p,const int countboy,const int countgirl,const int maxboy);
void AppendInstitute(INSTITUTE a,int *countinstitute,const int max);
int Rank(struct project p,int n);
#endif // _project_H_
