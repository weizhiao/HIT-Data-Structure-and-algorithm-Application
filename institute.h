#ifndef institute_H
#define institute_H
struct institute
{
    char name[10];
    int GirlSum;
    int BoySum;
    struct list*L;
};

typedef struct institute* INSTITUTE;

INSTITUTE MakeInstitute(int*max,int*countinstitute);
int FindInstituteName(char name[],INSTITUTE a,const int countinstitute);
void ShowAllInstituteSum(INSTITUTE a,const int countinstitute);
void ShowSortInstitute(INSTITUTE a,const int countinstitute);
void ShowInstitute(struct institute a);
void ShowAllInstitute(INSTITUTE a,const int countinstitute);
INSTITUTE SortName(INSTITUTE a,const int countinstitute);
INSTITUTE SortScore(INSTITUTE a,int n,const int countinstitute);
INSTITUTE CopyInstitute(INSTITUTE a,const int countinstitute);
int Compare(int n,struct institute a1,struct institute a2);
#endif // institute_H
