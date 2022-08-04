// temp.cpp

// 寻找插入位置
/**
 * Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

 * You may assume no duplicates in the array.

 * test

 * Here are few examples.
 * [1,3,5,6], 5 → 2
 * [1,3,5,6], 2 → 1
 * [1,3,5,6], 7 → 4
 * [1,3,5,6], 0 → 0
 */

// 用mid = start + (end-start)/2 代替mid=(start+end)/2以避免溢出

#include <iostream>
using namespace std;

class Solution {
public:
    int searchInsert(int A[], int n, int target) {
        int index = binarySearch(A, target, 0, n-1);
        /*if (A[index] == target) return index;
        else if (A[index] < target) return index+1;
        else {
            if (0 == index) return 0;
            else            return index-1;
        }*/
        return index;
    }
private:
    int binarySearch(int A[], int target, int start, int end) {
        if (start > end)   return start;
        int mid = (start+end)/2;
        if (target < A[mid])        return binarySearch(A, target, start, mid-1);
        else if (target > A[mid])   return binarySearch(A, target, mid+1, end);
        else                        return mid;
    }
};

int main(void) {
    Solution so;
    int A[] = {0, 1, 2};
    // just for run
    cout << so.searchInsert(A, sizeof(A)/sizeof(*A), 4) << endl;
    cout << so.searchInsert(A, sizeof(A)/sizeof(*A), -1) << endl;

}
