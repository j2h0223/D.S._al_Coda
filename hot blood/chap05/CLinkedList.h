#ifndef __C_LINKED_LIST_H__
#define __C_LINKED_LIST_H__

#define TURE 1
#define FALSE 0

typedef int Data;

typedef struct _Node
{
    Data data;
    struct _Node *next;
} Node;

typedef struct _CLinkedList
{
    Node *tail;
    Node *cur;
    Node *before;
    int numOfNode;
} CList;
typedef CList List;

void ListInit(List *plist);
void LInsertTail(List *plsit, Data data);
void LInsertHead(List *plist, Data data);

int LFirst(List *plist, Data *pdata);
int LNext(List *plist, Data *pdata);
Data LRemove(List *plist);
int LCount(List *plist);

#endif