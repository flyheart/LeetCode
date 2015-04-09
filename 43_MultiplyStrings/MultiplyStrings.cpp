// MultiplyStrings.cpp
/**
 * Given two numbers represented as strings, return multiplication of the numbers as a string.

 * Note: The numbers can be arbitrarily large and are non-negative.
 */

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        string ret;
        string padding;
        int s1 = num1.size();
        int s2 = num2.size();
        if (s1 < s2)    { swap(num1, num2); }
        s1 = num1.size();
        s2 = num2.size();

        for (int i=s2-1; i>=0; --i) {
            ret = sumString(ret, __multiply(num1, num2[i]-'0')+padding);
            padding += '0';
        }

        return ret;
    }
private:
    string __multiply(string num, int count) {    // return num*count;
        string num1 = "0";
        for (int i = 0; i < count; ++i) {
            num1 = sumString(num1, num);
        }

        return num1;
    }
    string sumString(string num1, string num2) {  // return num1+num2
        int s1 = num1.size();
        int s2 = num2.size();
        if (s1 < s2)    { swap(num1, num2);}
        s1 = num1.size(), s2 = num2.size();

        int carry = 0;
        for (int i = s1-1, j = s2-1; i >= 0; --i, --j) {
            int add;
            if (j >= 0) add = num2[j] - '0';
            else        add = 0;
            int sum = num1[i]-'0' + add + carry;
            carry = sum / 10;
            num1[i] = sum%10 + '0';
        }
        if (carry > 0)
            num1 = to_string((long long)carry)+num1;
        return num1;
    }

    void swapString(string& s1, string& s2) {
        string temp = s1;
        s1 = s2;
        s2 = temp;
    }
};

int main(void) {
    Solution so;
    
    cout << so.multiply("0", "0") << endl;
    cout << so.multiply("9", "9") << endl;
    cout << so.multiply("123", "2") << endl;
    cout << so.multiply("2", "123") << endl;
    cout << so.multiply("123456789", "987654321") << endl;

    return 0;
}