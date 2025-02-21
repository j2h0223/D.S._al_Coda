#include <stdio.h>
#include <stdlib.h>

#include "CLinkedList.h"

int main(void)
{
    List list;
    int data, nodeNum;

    ListInit(&list);

    LInsertTail(&list, 3);
    LInsertTail(&list, 4);
    LInsertHead(&list, 1);
    LInsertTail(&list, 5);
    LInsertHead(&list, 2);



//     LInsertTail(&list, 3);
//     LInsertTail(&list, 4);
//     LInsertTail(&list, 5);
//     LInsertHead(&list, 2);
//     LInsertHead(&list, 1);

    if (LFirst(&list, &data))
    {
        printf("%d", data);

        for (int i = 0; i < LCount(&list) * 3 - 1; i++)
        {
            if (LNext(&list, &data))
            {
                printf("%d", data);
            }
        }
    }
    printf("\n");

    nodeNum = LCount(&list);
    if (nodeNum != 0)
    {
        LFirst(&list, &data);
        if (data % 2 == 0)
        {
            LRemove(&list);
        }

        for (int i = 0; i < nodeNum - 1; i++)
        {
            LNext(&list, &data);
            if (data % 2 == 0)
            {
                LRemove(&list);
            }
        }
    }

    if (LFirst(&list, &data))
    {
        printf("%d", data);

        for (int i = 0; i < LCount(&list) - 1; i++)
        {
            if (LNext(&list, &data))
            {
                printf("%d", data);
            }
        }
    }

    return 0;
}