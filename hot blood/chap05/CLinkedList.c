#include <stdio.h>
#include <stdlib.h>

#include "CLinkedList.h"

void ListInit(List *plist)
{
    plist->tail = NULL;
    plist->cur = NULL;
    plist->before = NULL;

    plist->numOfNode = 0;
}

void LInsertTail(List *plist, Data data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (plist->tail == NULL)
    {
        plist->tail = newNode;
        newNode->next = newNode;
    }
    else
    {
        newNode->next = plist->tail->next;
        plist->tail->next = newNode;
        plist->tail = newNode;
    }

    (plist->numOfNode)++;
}

void LInsertHead(List *plist, Data data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (plist->tail == NULL)
    {
        plist->tail = newNode;
        newNode->next = newNode;
    }
    else
    {
        newNode->next = plist->tail->next;
        plist->tail->next = newNode;
    }

    (plist->numOfNode)++;
}

int LFirst(List *plist, Data *pdata)
{
    if (plist->numOfNode < 1)
    {
        return FALSE;
    }

    plist->before = plist->tail;
    plist->cur = plist->tail->next;

    *pdata = plist->cur->data;
    return TURE;
}

int LNext(List *plist, Data *pdata)
{
    if (plist->numOfNode < 1)
    {
        return FALSE;
    }

    plist->before = plist->cur;
    plist->cur = plist->cur->next;

    *pdata = plist->cur->data;
    return TURE;
}

Data LRemove(List *plist)
{
    if (plist->tail == plist->cur)
    {
        if (plist->tail == plist->tail->next)
        {
            plist->tail = NULL;
        }
        else
        {
            plist->tail = plist->before;
        }
    }

    Node *delNode = plist->cur;

    plist->before->next = plist->cur->next;
    plist->cur = plist->before;

    Data delData = delNode->data;
    free(delNode);

    (plist->numOfNode)--;

    return delData;
}

int LCount(List *plist)
{
    return plist->numOfNode;
}