/**
 * Given a sorted array of integers, find the starting and ending position of a given target value.

 * Your algorithm's runtime complexity must be in the order of O(log n).

 * If the target is not found in the array, return [-1, -1].

 * For example,
 * Given [5, 7, 7, 8, 8, 10] and target value 8,
 * return [3, 4].
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        vector<int> ret;
        int index = binarySearch(A, target, 0, n-1);
        int start = index, end = index;
        while (start > 0) {
            if (A[start-1] == target)   --start;
            else                        break;
        }
        while (end < n - 1) {
            if (A[end+1] == target)     ++end;
            else                        break;
        }
        ret.push_back(start);
        ret.push_back(end);

        return ret;
    }
private:
    int binarySearch(int* A, int target, int start, int end) {
        if (start > end)    return -1;
        int mid = (start + end) / 2;
        if (target > A[mid])        return binarySearch(A, target, mid+1, end);
        else if (target < A[mid])   return binarySearch(A, target, start, mid-1);
        else                        return mid;
    }
};

int main(void) {
    // int A[] = {5, 7, 7, 8, 8, 10};
    int A[] = {1};
    Solution so;
    vector<int> ret = so.searchRange(A, sizeof(A)/sizeof(*A), 0);
    for (int i = 0; i < ret.size(); ++i)
        cout << ret[i] << '\t';
    cout << endl;

    return 0;
}