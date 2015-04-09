/**
 * Suppose a sorted array is rotated at some pivot unknown to you beforehand.

 * (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

 * You are given a target value to search. If found in the array return its index, otherwise return -1.

 * You may assume no duplicate exists in the array.
 */

/**
 * 根据本解题思路，start,end应该分属与pivot的两侧，然而如果mid==pivot 或者mid+1 == pivot时，
 * 将破坏此假设，因此必须将此两种情况单独对待。
 */

#include <iostream>
using namespace std;

class Solution {
public:
    int search(int A[], int n, int target) {
        if (NULL == A)  return -1;
        int start = 0; int end = n - 1;
        int pivot = -1;

        if (A[start] < A[end])  pivot = end;
        else {
            while (start <= end) {
        	    if (A[start] > A[start+1] && A[start] > A[start - 1]) { pivot = start; break; }
        	    int mid = (start + end) / 2;
        	    if (A[mid] >= A[start]) {
                    if (mid+1 <= end && A[mid] > A[mid+1]) { pivot = mid; break; }
                    start = mid + 1;

                }
        	    if (A[mid] < A[end]) { 
                    if (mid-1 >= start && A[mid] < A[mid-1]) { pivot = mid - 1; break;}
                    end = mid - 1; 
                }
        	}
        }

        if (target < A[0]) return binarySearch(A, target, pivot+1, n - 1);
        return binarySearch(A, target, 0, pivot);
    }
private:
    int binarySearch(int A[], int target, int start, int end) {
        if (start > end)    return -1;
        int mid = (start+end)/2;
        if (A[mid] == target)   return mid;
        else if (A[mid] > target)   binarySearch(A, target, start, mid-1);
        else                        binarySearch(A, target, mid+1, end);
    }
};

int main(void) {
    int A[] = {4, 5, 6, 0, 1, 2};
    int A2[] = {1, 3, 1};
    int A3[] = {4,5,6,7,8,1,2,3};
    int A4[] = {3, 5, 1};
    int A5[] = {6,7,8,1,2,3,4,5};
    Solution so;
    //cout << so.search(A3, 8, 8) << endl;
    //cout << so.search(A4, 3, 1) << endl;
    cout << so.search(A5, 8, 6) << endl;

    return 0;
}