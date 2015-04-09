/*
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
*/

#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
bool isValid(string s) {
        stack<char> sc;
        sc.push('#');   // guard character
        int size = s.size();
        for (int i = 0; i < size; ++i) {
            switch(s[i]) {
            case '(':
                sc.push(s[i]);
                break;
            case ')':
                if ('(' != sc.top())
                    return false;
                sc.pop();
                break;
            case '{':
                sc.push(s[i]);
                break;
            case '}':
                if ('{' != sc.top())
                    return false;
                sc.pop();
                break;
            case '[':
                sc.push(s[i]);
                break;
            case ']':
                if ('[' != sc.top())
                    return false;
                sc.pop();
                break;
            default:
                break;
            }
        }
        if ('#' != sc.top() && 1 != sc.size())
            return false;
        return true;
    }
};

int main(void) {
    Solution so;
    cout << so.isValid("[[]]()") << endl;
    cout << so.isValid("[[]]{)") << endl;
    cout << so.isValid(")") << endl;

    return 0;
}