#include <stdio.h>
#include "DlinkedList.h"

int main(void)
{

    List list;
    LData inputData;
    LData tempData;

    ListInit(&list); // 리스트 초기화

    while (1)
    { // Loop_input : 데이터를 입력 받는 과정
        fputs("자연수 입력", stdout);
        scanf("%d", &inputData);
        if (inputData < 1)
        {
            break;
        }

        LInsert(&list, inputData);
    } // Loop_input end
    fputs("\n", stdout);

    // 입력 받은 데이터 출력 과정
    fputs("입력 받은 데이터 전체 출력\n", stdout);
    if (LFirst(&list, &tempData))
    {
        printf("%d", tempData);

        while (LNext(&list, &tempData))
        {
            printf(", %d", tempData);
        }
    }
    else
    {
        fputs("Empty list", stdout);
    }
    fputs("\n출력 완료\n\n", stdout);

    printf("Number of list : %d\n\n", LCount(&list));

    // 메모리 해제 과정
    fputs("메모리 해제\n", stdout);
    // if (LFirst(&list, &tempData))
    // {
    //     tempData = LRemove(&list);
    //     printf("%d", tempData);

    //     while (LNext(&list, &tempData))
    //     {
    //         tempData = LRemove(&list);
    //         printf(", %d", tempData);
    //     }
    // }
    do
    {
        tempData = LRemove(&list);
        if (tempData == FALSE)
        {
            printf("\nEmpty list. \n메모리 해제 완료");
            break;
        }
        printf("%d, ", tempData);
    } while (tempData);

    fputs("\n\n", stdout);
    printf("Number of list : %d", LCount(&list));
    fputs("\n\n", stdout);

    return 0;
}