// TrappingRainWater.cpp

/**
 * Given n non-negative integers representing an elevation map where the width of each bar is 1, 
 * compute how much water it is able to trap after raining.

 * For example, 
 * Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.
 */

/** 
 * Here is my idea: instead of calculating area by height*width, we can think it in a cumulative way. 
 * In other words, sum water amount of each bin(width=1). Search from left to right and maintain a max 
 * height of left and right separately, which is like a one-side wall of partial container. 
 * Fix the higher one and flow water from the lower part. For example, if current height of left is lower, 
 * we fill water in the left bin. Until left meets right, we filled the whole container.
 */
#include <iostream>
using namespace std;

class Solution {
public:
    int trap(int A[], int n) {
        int left = 0, right = n-1;
        int res = 0;
        int maxleft = 0, maxright = 0;
        while(left <= right){
            if(A[left] <= A[right]){
                if(A[left] >= maxleft) maxleft = A[left];
                else res += maxleft-A[left];
                left++;
            }
            else{
                if(A[right] >= maxright) maxright = A[right];
                else res += maxright-A[right];
                right--;
            }
        }
        return res;
    }
};


int main(void) {
    Solution so;
    int A[] = {0,1,0,2,1,0,1,3,2,1,2,1};
    cout << so.trap(A, sizeof(A)/sizeof(*A)) << endl;

    return 0;
}
