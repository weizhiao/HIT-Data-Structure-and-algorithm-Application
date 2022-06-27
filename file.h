#ifndef file_H
#define file_H
#include"file.h"
#include"list.h"
#include"project.h"
#include"institute.h"

FILE*Open();
void WritetoFile(PROJECT p,INSTITUTE a,int array[]);
void ReadArrayfromFile(int array[],FILE *fp);
void ReadProjectfromFile(const int max,PROJECT p,FILE *fp);
void ReadInstitutefromFile(const int max,INSTITUTE a,FILE *fp);
void RecoverList(INSTITUTE a,PROJECT p,const int countboy,const int countgirl,const int maxboy);

#endif // file_H
