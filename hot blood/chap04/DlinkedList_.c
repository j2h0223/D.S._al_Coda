#include <stdio.h>
#include <stdlib.h>
#include "DlinkedList.h"

void ListInit(List *plist)
{
    Node * dummyNode = (Node *)malloc(sizeof(Node));
    // dummyNode->data = NULL;
    dummyNode->next = NULL;

    plist->head = dummyNode;
    plist->cur = NULL;
    plist->before = NULL;
    plist->numOfData = 0;
    plist->comp = NULL;
}

void LInsert(List *plist, LData data)
{
    Node *newNode;
    newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    newNode->next = plist->head->next;
    plist->head->next = newNode;

    // if (plist->head == NULL)
    // {
    //     plist->head = newNode;
    //     newNode->next = NULL;
    // }
    // else
    // {
    //     newNode->next = plist->head;
    //     plist->head = newNode;
    // }

    (plist->numOfData)++;
}

int LFirst(List *plist, LData *pdata)
{
    if (plist->numOfData < 1)
    {
        return FALSE;
    }
    else
    {
        plist->cur = plist->head->next;
        *pdata = plist->cur->data;
        // plist->cur = plist->cur->next;
        return TRUE;
    }
}
int LNext(List *plist, LData *pdata)
{
    if (plist->cur->next == NULL)
    {
        // fputs("\nList end", stdout);
        return FALSE;
    }
    else
    {
        plist->cur = plist->cur->next;
        *pdata = plist->cur->data;

        return TRUE;
    }
}

LData LRemove(List *plist)
{
    if (plist->numOfData < 1)
    {
        return FALSE;
    }

    Node *delNode;
    LData tempData;

    // plist->before = plist->cur;
    // tempData = plist->before->data;
    // free
    
    tempData = plist->head->next->data;
    delNode = plist->head->next;
    plist->head->next = plist->head->next->next;
    free(delNode);

    plist->numOfData--;
    return tempData;

    // while (plist->head->next != NULL){
    //     delNode = plist->head;
    //     plist->head = plist->head->next;
    //     free(delNode);
    //     plist->numOfData--;

    //     return tempData;
    // }
}

int LCount(List *plist)
{
    return plist->numOfData;
}

void SetSortRule(List *plist, LData (*comp)(LData d1, LData d2))
{

}