#include <stdio.h>
#include "ArrayList.h"

void ListInit(List * plist){
    plist->numOfData = 0;
    // plist->curPosition = 0;
}

void LInsert(List * plist, LData data){
    plist->arr[plist->numOfData] = data;
    plist->numOfData += 1 ;
}

int LFirst(List * plist, LData * pdata){
    plist->curPosition = 0;

    if (plist->numOfData > 0){
        * pdata = plist->arr[plist->curPosition];
        // plist->curPosition += 1;
        return 1;
    }
    else
        return 0;
}

int LNext(List * plist, LData * pdata){
    plist->curPosition += 1;

    if (plist->numOfData - plist->curPosition > 0){
        * pdata = plist->arr[plist->curPosition];
        // plist->curPosition += 1;
        return 1;
    }
    else{
        return 0;
    }
}

LData LRemove(List * plist){
    LData num = plist->arr[plist->curPosition];
    for (int i = plist->curPosition; i < plist->numOfData - 1 ; i++)
    {
        plist->arr[i] = plist->arr[i + 1];
    }
    
    plist->numOfData -= 1;
    plist->curPosition -= 1;

    return num;
}

int LCount(List * plist){
    return plist->numOfData;
}