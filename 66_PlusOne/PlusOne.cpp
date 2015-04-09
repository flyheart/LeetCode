// PlusOne.cpp

/**
 * Given a non-negative number represented as an array of digits, plus one to the number.

 * The digits are stored such that the most significant digit is at the head of the list.
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 1;
        int size = digits.size();
        for (int i = size - 1; i >= 0; --i) {
            int sum = digits[i] + carry;
            digits[i] = sum % 10;
            carry = sum / 10;
        }
        if (1 == carry)
            digits.insert(digits.begin(), carry);
        return digits;
    }
};

int main(void) {
    Solution so;
    vector<int> digits;
    for (int i = 0; i < 6; ++i) {
        digits.push_back(9);
    }

    so.plusOne(digits);
    for (int i = 0; i < digits.size(); ++i) {
        cout << digits[i];
    }
    cout << endl;

    return 0;
}