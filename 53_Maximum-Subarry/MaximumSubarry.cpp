// MaximumSubarry.cpp

/**
 * Find the contiguous subarray within an array (containing at least one number) which has the largest sum.

 * For example, given the array [−2,1,−3,4,−1,2,1,−5,4],
 * the contiguous subarray [4,−1,2,1] has the largest sum = 6.

 * More practice:
 * If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.
 */

#include <iostream>
using namespace std;

class Solution {
public:
    int maxSubArray(int A[], int n) {
        if (0 == n) return 0;
        int maxSum = A[0];
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            if (sum >= 0) {
                sum += A[i];
            }
            else {
                sum = A[i];
            }
            maxSum = maxSum >= sum ? maxSum : sum;
        }

        return maxSum;
    }
};

int main(void) {
    Solution so;
    int A1[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int A2[] = {-2, 1};

    cout << so.maxSubArray(A1, sizeof(A1)/sizeof(*A1)) << endl;
    cout << so.maxSubArray(A2, sizeof(A2)/sizeof(*A2)) << endl;

    return 0;
}