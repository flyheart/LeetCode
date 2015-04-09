// PermutationSequence.cpp

/**
 * The set [1,2,3,…,n] contains a total of n! unique permutations.

 * By listing and labeling all of the permutations in order,
 * We get the following sequence (ie, for n = 3):

 * "123"
 * "132"
 * "213"
 * "231"
 * "312"
 * "321"
 * Given n and k, return the kth permutation sequence.

 * Note: Given n will be between 1 and 9 inclusive.
 */

#include <iostream>
#include <string>
#include <cassert>
using namespace std;

class Solution {
public:
    string getPermutation(int n, int k) {
        assert(n>0 && k>=0 && k<=factorial(n));
        string ret(n, 0);
        int s;
        int *A = new int[n];
        for (int i = 0; i < n; ++i) {
            A[i] = i+1;
        }
        --k;
        for (int i = 0; i < n; ++i) {
            s = factorial(n-i-1);
            ret[i] = '0' + A[i+k/s];
            permutationArray(A, i+k/s, i, n);
            k = k%s;
        }
        delete []A;

        return ret;
    }
private:
    int factorial(int n) {
        if (0==n || 1==n) return 1;
        int sum = 1;
        for (int k = 2; k <= n; ++k) {
            sum *= k;
        }

        return sum;
    }

    // 数组A的长度为n，将第i个元素移至位置j，i>=j
    void permutationArray(int* A, int i, int j, int n) {
        int t = A[i];
        for (int k = i-1; k >= j; --k) {
            A[k+1] = A[k] ;
        }
        A[j] = t;
    }
};

int main(void) {
    Solution so;

    cout << so.getPermutation(3, 4) << endl;

    return 0;
}