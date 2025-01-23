#include <stdio.h>
#include <stdlib.h>

typedef int Data;

typedef struct _node{
    Data data;
    struct _node * next;
} Node;

int main(void){
    Node * head = NULL;
    Node * tail = NULL;
    Node * cur = NULL;

    Node * newNode = NULL;
    Data readData;

    while(1){ // Loop_input : 데이터를 입력 받는 과정 
        fputs("자연수 입력 : ", stdout);
        scanf("%d", &readData);
        if (readData < 1){
            break;
        }

        // 노드 추가과정
        newNode = (Node *)malloc(sizeof(Node));
        newNode->data = readData;
        newNode->next = NULL;

        if (head==NULL){
            head = newNode;
        }
        else{
            tail->next = newNode;
        }

        tail = newNode;
    } // Loop_input end
    fputs("\n", stdout);

    // 입력 받은 데이터 출력 과정
    fputs("입력 받은 데이터 전체 출력\n", stdout);
    if (head == NULL){
        fputs("데이터가 존재하지 않음\n", stdout);
    }
    else{
        cur = head;
        printf("%d ", cur->data); // 첫 데이터 출력

        while(cur->next!=NULL){ // 두 번째 이후 데이터 출력
            cur = cur->next;
            printf("%d ", cur->data);
        }
    } 
    fputs("\n\n", stdout);

    // 메모리 해제 과정
    if (head==NULL){
        return 0; // 해제할 데이터가 없음
    }
    else{
        Node * delNode = head;
        Node * delNextNode = head->next;

        printf("%d을(를) 삭제합니다.\n", head->data);
        free(delNode); // 첫 노드 삭제

        while(delNextNode!=NULL){  // 두 번째 이후 노드 삭제
            delNode = delNextNode;
            delNextNode = delNode->next;

            printf("%d을(를) 삭제합니다.\n", delNode->data);
            free(delNode); // 첫 노드 삭제
        }
    }

    return 0;
}