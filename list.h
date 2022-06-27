#ifndef _list_H_
#define _list_H_
struct list
{
    int data;
    struct list *next;
};

typedef struct list * LIST;

LIST MakeNull();
LIST Next(LIST p);
void AppendFirst(LIST L,int data);
void AppendLast(LIST L,int data);
int CountnoHead(LIST L);
LIST AppendLastnoHead(int data, LIST L);
LIST AppendFirstnoHead(int data, LIST L);
LIST End(LIST L);
#endif // _list_H_
