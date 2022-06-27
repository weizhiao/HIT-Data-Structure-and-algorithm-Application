#include<stdio.h>
#include<stdlib.h>
#include "list.h"

LIST MakeNull()
{
    LIST L = malloc(sizeof(struct list));
    L->next = NULL;
    return L;
}

LIST Next(LIST p)
{
    p=p->next;
    return p;
}

void AppendFirst(LIST L,int data)
{
    LIST temp=malloc(sizeof(struct list));
    temp->next=L->next;
    temp->data=data;
    L->next=temp;
}
void AppendLast(LIST L,int data)
{
    while(L->next!=NULL)
    {
        L=Next(L);
    }
    L->next=malloc(sizeof(struct list));
    L->next->next=NULL;
    L->next->data=data;
}

int CountnoHead(LIST L)
{
    int count = 0;
    LIST ptr = L;
    while (ptr != NULL)
    {
        count++;
        ptr = Next(ptr);
    }
    return count;
}

LIST AppendLastnoHead(int data, LIST L)
{
    if (L == NULL)
    {
        L = malloc(sizeof(struct list));
        L->data = data;
        L->next = NULL;
    }
    else
    {
        LIST ptr = L;
        while ((ptr->next) != NULL)
        {
            ptr = Next(ptr);
        }
        LIST temp = malloc(sizeof(struct list));
        ptr->next = temp;
        temp->next = NULL;
        temp->data = data;
    }
    return L;
}

LIST AppendFirstnoHead(int data, LIST L)
{
    if (L == NULL)
    {
        L = malloc(sizeof(struct list));
        L->data = data;
        L->next = NULL;
    }
    else
    {
        LIST temp = malloc(sizeof(struct list));
        temp->next = L;
        temp->data = data;
        L = temp;
    }
    return L;
}

LIST End(LIST L)
{
    while (L->next != NULL)
    {
        L = Next(L);
    }
    return L;
}
