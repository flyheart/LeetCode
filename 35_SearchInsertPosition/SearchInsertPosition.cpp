// SearchInsertPosition.cpp

/**
 * Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

 * You may assume no duplicates in the array.

 * Here are few examples.
 * [1,3,5,6], 5 ¡ú 2
 * [1,3,5,6], 2 ¡ú 1
 * [1,3,5,6], 7 ¡ú 4
 * [1,3,5,6], 0 ¡ú 0
 */
#include <iostream>
using namespace std;

class Solution {
public:
    int searchInsert(int A[], int n, int target) {
        if (0 == n) return 0;
        int index = binarySearch(A, target, 0, n-1);
        if (A[index] == target) return index;
        else if (A[index] < target) return index+1;
        else {
            // if (0 == index) return 0;
            // else            return index;
            return index;
        }
    }
private:
    int binarySearch(int A[], int target, int start, int end) {
        if (start >= end)   return start;   // >= !!
        int mid = (start+end)/2;
        if (target < A[mid])        return binarySearch(A, target, start, mid-1);
        else if (target > A[mid])   return binarySearch(A, target, mid+1, end);
        else                        return mid;
    }
};

class Solution2 {
public:
    int searchInsert(int A[], int n, int target) {
        int start = 0, end = n-1, mid;
        while (start <= end)  {
            mid = start + (end-start) /2;
            if (A[mid] == target)   return mid;
            if (target > A[mid]) start = mid + 1;
            else end = mid - 1;
        }
        
        return start;
    }
};

class Solution3 {
public:
    int searchInsert(int A[], int n, int target) {
        return binarySearch(A, target, 0, n-1);
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
    int A[] = {1, 3, 5, 6};
    int A2[] = {1, 3};
    cout << so.searchInsert(A, sizeof(A)/sizeof(*A), 5) << endl;
    cout << so.searchInsert(A, sizeof(A)/sizeof(*A), 2) << endl;
    cout << so.searchInsert(A, sizeof(A)/sizeof(*A), 7) << endl;
    cout << so.searchInsert(A, sizeof(A)/sizeof(*A), 0) << endl;
    cout << so.searchInsert(A2, sizeof(A2)/sizeof(*A2), 2) << endl;

    Solution2 so2;
    int B[] = {0, 1, 2};
    int B2[] = {1, 3};
    cout << so.searchInsert(B, sizeof(B)/sizeof(*B), 4) << endl;
    cout << so.searchInsert(B2, sizeof(B2)/sizeof(*B2), 2) << endl;

    return 0;
}