#include <stdio.h>
#include <stdlib.h>

#include "LinkedList.h"

int main(void)
{
    List list;
    initList(&list);

    insertAtHead(&list, 3);
    insertAtHead(&list, 4);
    insertAtHead(&list, 5);

    insertAtTail(&list, 1);

    printList(&list);
    printf("%d\n\n", getNodeCount(&list));

    insertAfter(&list, searchLocation(&list, 2), 7);
    insertAfter(&list, searchKey(&list, 7), 9);

    printList(&list);
    printf("%d\n\n", getNodeCount(&list));

    deleteNode(&list, searchLocation(&list, 2));
    deleteNode(&list, searchKey(&list, 1));

    printList(&list);
    printf("%d\n\n", getNodeCount(&list));

    deleteAtHead(&list);
    deleteAtTail(&list);

    printList(&list);

    deleteList(&list);
    printf("last : ");
    printList(&list);

    return 0;
}