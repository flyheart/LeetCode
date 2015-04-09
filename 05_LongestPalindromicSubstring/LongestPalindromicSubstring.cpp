/*
Given a string S, find the longest palindromic substring in S. You may assume that the maximum length of S is 1000, 
and there exists one unique longest palindromic substring.
*/

#include <iostream>
#include  <string>
using namespace std;

class Solution {
public:
    string longestPalindrom(string s) {
        string T = preProcess(s);
        unsigned int len = T.size();
        int* P = new int[len];
        memset(P, 0, sizeof(int)*len);
        int C = 0;
        int R = C + P[0];

        for (unsigned int i = 1; i < len-1; ++i) {
            if (i <= R)
                P[i] = min(R-i, P[2*C - i]);
            while (/*i-P[i]-1 >= 0 && i+P[i]+1 < len && */T[i-P[i]-1] == T[i+P[i]+1]) {
                P[i]++;
            }
            if (i+P[i] >= R) {
                C = i;
                R = C + P[i];
            }
        }

        int maxLen = 0;
        int index = 0;
        for (unsigned int j = 0; j < len; ++j) {
            if (P[j] > maxLen) {
                maxLen = P[j];
                index = j;
            }
        }
        delete []P;
        
       return s.substr((index-1-maxLen)/2, maxLen);
    }

private:
    int min(int a, int b) { return a <= b ? a : b; }
    string preProcess(string s) {
        string ret = "^";
        int len = s.size();
        if (0 == len) return "^$";
        for (int i = 0; i < len; ++i) {
            ret = ret + "#" + s[i];
        }
        ret += "#$";

        return ret;
    }
};

int main(void) {
    string str = "abacd";
    Solution so;
    cout << so.longestPalindrom(str) << endl;

    return 0;
}