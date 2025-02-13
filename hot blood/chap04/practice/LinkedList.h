/*
 * @file LinkedList.h
 * @brief 리스트 자료구조의 헤더
 * @details
 */

/*
 * @author 진준형
 * @date 2024-02-06
 * @version 1.0.0
 */

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

// 노드 구조체 정의
typedef struct _Node
{
    int data;
    struct _Node *next;
} Node;

// 연결 리스트 구조체 정의
typedef struct _LinkedList
{
    Node *head; // 리스트의 헤드 포인터
    int numOfNode;
} LinkedList;
typedef LinkedList List;

// 함수 원형 선언

// 리스트 초기화
void initList(List *list);

// 노드 생성
Node *createNode(ElementType data);

// 노드 삽입
void insertAtHead(List *list, ElementType data);
void insertAtTail(List *list, ElementType data);
void insertAfter(List *list, Node *prevNode, ElementType data);

// 노드 삭제
void deleteNode(List *list, Node *prevNode);
void deleteAtHead(List *list);
void deleteAtTail(List *list);
void deleteList(List *list);

// 리스트 검색
Node *searchLocation(List *list, ElementType location);
Node *searchKey(List *list, ElementType key);

// 노드 개수 출력
int getNodeCount(List *list);

// 리스트 출력
void printList(List *list);

#endif