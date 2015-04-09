/*
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:

"((()))", "(()())", "(())()", "()(())", "()()()"
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        parenthesis(n, 0, 0, "");

        return vstr;
    }
private:
    vector<string> vstr;
    void parenthesis(int n, int lnum, int rnum, string str) {
        if (lnum > rnum) {
            parenthesis(n, lnum, rnum+1, str+")");
        }
        if (lnum < n) {
            parenthesis(n, lnum+1, rnum, str+"(");
        }
        if (rnum == n)
            vstr.push_back(str);
    }
};

int main(void) {
    Solution so;
    vector<string> str = so.generateParenthesis(3);
    for (int i = 0; i < str.size(); ++i)
        cout << str[i] << ", ";
    cout << endl;

    return 0;
}