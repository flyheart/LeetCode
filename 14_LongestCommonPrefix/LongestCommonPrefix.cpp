/*
Write a function to find the longest common prefix string amongst an array of strings.
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        string common;
        int size = strs.size();
        if (0 == size)  return "";
        int len = strs[0].size();
        if (0 == len)   return "";
        int i, j;
        for (i = 0; i < len; ++i) {
            char c = strs[0][i];
            for (j = 1; j < size; ++j) {
                if (c != strs[j][i])    break;
            }
            if (j != size)  break;
        }

        return strs[0].substr(0, i);
    }
};

int main(void) {
    Solution so;
    return 0;
}