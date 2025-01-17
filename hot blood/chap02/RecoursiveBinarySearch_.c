#include <stdio.h>

int BSearchRecur(int [], int, int, int);
void FailureCheck(int);

int main(void){

    int arr[] = {1,2,3,4,6,7,8,9,10};
    int idx;

    idx = BSearchRecur(arr, 0, sizeof(arr)/sizeof(int)-1, 8);
    FailureCheck(idx);

    idx = BSearchRecur(arr, 0, sizeof(arr)/sizeof(int)-1, 5);
    FailureCheck(idx);

    return 0;
}


int BSearchRecur(int arr[], int first, int last, int target){
    if (first > last){
        return -1;
    }
    else{
        int mid = (first+last)/2;

        if (arr[mid] == target)
            return mid;
        else if (arr[mid] < target)
            return BSearchRecur(arr, mid+1, last, target);
        else
            return BSearchRecur(arr, first, mid-1, target);
    }
}

void FailureCheck(int idx){
    if (idx == -1)
        fputs("타겟 탐색 실패\n", stdout);
    else
        printf("타겟 저장 인덱스 : %d\n", idx);
}