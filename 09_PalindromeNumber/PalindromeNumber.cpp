/*
Determine whether an integer is a palindrome. Do this without extra space.

click to show spoilers.

Some hints:
Could negative integers be palindromes? (ie, -1)

If you are thinking of converting the integer to string, note the restriction of using extra space.

You could also try reversing an integer. However, if you have solved the problem "Reverse Integer", you know that the reversed integer might overflow. 
How would you handle such case?

There is a more generic way of solving this problem.
*/
#include <iostream>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        /*
        // Might overflow!!
        if (INT_MIN == x)
            return false;
        x = x < 0 ? -x : x;

        int reverse = 0;
        int x1 = x;
        while (x1 != 0) {
            reverse = reverse*10 + x1 % 10;
            x1 /= 10;
        }

        return x1 == reverse; */

        if (x < 0)  return false;
        int len = 1;    // xÓÐ¼¸Î»
        int x1 = x;
        while (x1 >= 10) {
            x1 /= 10;
            len *= 10;
        }
        
        while (0 != len) {
            if ((x/len)%10 != x%10) {
                return false;
            }
            len /= 100;
            x /= 10;
        }
        return true;
    }
};

int main(void) {
    Solution so;
    cout << so.isPalindrome(1021) << endl;

    return 0;
}