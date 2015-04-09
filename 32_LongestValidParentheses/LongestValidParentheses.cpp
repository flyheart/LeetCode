/**
 * Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) 
 * parentheses substring.

 * For "(()", the longest valid parentheses substring is "()", which has length = 2.

 * Another example is ")()())", where the longest valid parentheses substring is "()()", which has length = 4.
 */

/**
 * 总共可以分为两种情况：()()、(())
 */

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        int size = s.size();
        if (0 == size)  return 0;
        int* len = new int[size];
        memset(len, 0, size*sizeof(int));

        int cnt = 0;
        if ('(' == s[0])    ++cnt;
        for (int i = 1; i < size; ++i) {
            if ('(' == s[i])    ++cnt;
            else {
                if (cnt > 0)    { 
                    --cnt; len[i] = 2;
                    if (')' == s[i-1])    len[i] += len[i-1];
                    if (i - len[i] >= 0)
                        len[i] += len[i - len[i]];
                }
            }
        }

        int maxLen = 0;
        for (int i = 0; i < size; ++i) {
            maxLen = maxLen < len[i] ? len[i] : maxLen;
        }

        return maxLen;
    }
};

int main(void) {
    Solution so;
    cout << so.longestValidParentheses("()(()") << endl;
    cout << so.longestValidParentheses("(()(((()") << endl;
    cout << so.longestValidParentheses("()(())") << endl;

    return 0;
}