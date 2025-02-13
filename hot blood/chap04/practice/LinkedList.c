/*
 * @file LinkedList.c
 * @brief 리스트 자료구조의 헤더(LinkedList.h) 구현
 * @details
 */

/*
 * @author 진준형
 * @date 2024-02-06
 * @version 1.0.0
 */

#include <stdio.h>
#include <stdlib.h>

#include "LinkedList.h"

void initList(List *list) // 리스트 초기화
{
    list->numOfNode = 0;

    Node *dummyNode = (Node *)malloc(sizeof(Node));
    list->head = dummyNode; // 초기화 시 더미노드 생성
    // dummyNode->data = 999;
}

Node *createNode(ElementType data) // 노드 생성
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    return newNode;
}

void insertAtHead(List *list, ElementType data) // 노드 head 삽입
{
    Node *newNode = createNode(data);

    newNode->next = list->head->next;
    list->head->next = newNode;

    (list->numOfNode)++;
}

void insertAtTail(List *list, ElementType data) // 노드 tail 삽입
{
    Node *newNode = createNode(data);
    Node *tail = list->head;

    while (tail->next != NULL)
    {
        tail = tail->next;
    }

    tail->next = newNode;
    (list->numOfNode)++;
}

void insertAfter(List *list, Node *prevNode, ElementType data) // 특정 노드 위치 뒤에 삽입
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;

    newNode->next = prevNode->next;
    prevNode->next = newNode;

    (list->numOfNode)++;
}

void deleteNode(List *list, Node *prevNode) // 특정 위치의 노드 삭제
{
    Node *delNode = prevNode->next;

    prevNode->next = delNode->next;

    free(delNode);
    (list->numOfNode)--;
}
void deleteAtHead(List *list) // head 위치 노드 삭제
{
    Node *delNode = list->head->next;

    list->head->next = delNode->next;

    free(delNode);
    (list->numOfNode)--;
}

void deleteAtTail(List *list) // tail 위치 노드 삭제
{
    Node *delNode = list->head;
    Node *prevDelNode = NULL;

    while (delNode->next != NULL)
    {
        prevDelNode = delNode;
        delNode = delNode->next;
    }

    free(delNode);
    prevDelNode->next = NULL;
    (list->numOfNode)--;
}

void deleteList(List *list) // list 전체 삭제
{
    Node *delNode = list->head;
    while (list->numOfNode >= 0)
    {
        // printf("%d\n", delNode->data);
        list->head = delNode->next;
        free(delNode);
        (list->numOfNode)--;
        delNode = list->head;
    }
}

Node *searchLocation(List *list, ElementType location) // 특정 위치 노드 찾기(location번째)
{
    if (list->numOfNode < 1)
    {
        printf("Empty list");
        return NULL;
    }
    else if (list->numOfNode < location)
    {
        printf("Out of Bounds");
        return NULL;
    }

    Node *current = list->head;

    for (int i = 0; i < location - 1; i++)
    {
        current = current->next;
    }

    return current;
}

Node *searchKey(List *list, ElementType key) // 특정 값을 가진 첫번째 노드 반환
{
    if (list->numOfNode < 1)
    {
        printf("Empty list");
        return NULL;
    }

    Node *current = list->head;
    for (int i = 0; i < list->numOfNode; i++)
    {
        if (current->next->data == key)
        {
            return current;
        }
        current = current->next;
    }

    printf("can't find key");
    return NULL;
}

int getNodeCount(List *list) // 리스트 개수 출력
{
    return list->numOfNode;
}

void printList(List *list) // 리스트 출력
{
    if (list->numOfNode < 1)
    {
        printf("Empty list");
        return;
    }

    Node *current = list->head->next;
    while (current != NULL)
    {
        printf("%d, ", current->data);
        current = current->next;
    }
    printf("\n");
}