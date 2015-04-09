/**
 * Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

 * If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).

 * The replacement must be in-place, do not allocate extra memory.

 * Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
 * 1,2,3 → 1,3,2
 * 3,2,1 → 1,2,3
 * 1,1,5 → 1,5,1
 */

// 具体讲解见Evernote中LeetCode/NextPermutation

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int> &num) {
        int size = num.size();
        int i;
        for (i = size - 1; i >= 1; --i) {
            if (num[i - 1] < num[i])    break;
        }
        if (0 == i) reverse(num.begin(), num.end() - 1);
        else {
            i--;
            int j = size - 1;
            while (num[j] <= num[i])    --j;
            swap(num[i], num[j]);
            reverse(num.begin() + i + 1, num.end() - 1);
        }
    }
private:
    void reverse(vector<int>::iterator it, vector<int>::iterator end) {
        while (it < end) swap(*it++, *end--);
    }
    void swap(int& a, int& b) {
        a = a^b;
        b = a^b;
        a = a^b;
    }
};

int main(void) {
    vector<int> v;
    v.push_back(7);
    v.push_back(6);
    v.push_back(5);
    v.push_back(4);
    v.push_back(3);
    v.push_back(2);
    v.push_back(1);

    Solution so;
    so.nextPermutation(v);
    for (int i = 0; i < v.size(); ++i)
        cout << v[i] << " ";
    cout << endl;

    return 0;
}