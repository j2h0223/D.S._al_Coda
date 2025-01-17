#include <stdio.h>

int BSearchRecur(int [], int, int, int);

int main(void){

    int arr[] = {1,2,3,4,6,7,8,9,10};
    int result;

    result = BSearchRecur(arr, 0, sizeof(arr)/sizeof(int)-1, 8);

    return 0;
}

int BSearchRecur(int arr[], int first, int last, int target){
    if (first < last){
        return -1;
    }
    else{
        int mid = (first+last)/2;

        if (arr[mid] == target)
            return target;
        else if (arr[mid] > target)
            return BSearchRecur(arr, mid+1, last, target);
        else
            return BSearchRecur(arr, first, last-1, target);
    }
}