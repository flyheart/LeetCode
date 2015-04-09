/*
Given a digit string, return all possible letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below.

Input:Digit string "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        static string keymap[] = {"#", "#", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"}; // 0,1数字键不对应任何字母
        vector<string> ret;
        int size = digits.size();
        if (0 == size) return ret;
        vector<string> combin = letterCombinations(digits.substr(1, size - 1));
        string first = keymap[digits[0]-'0'];
        int len = first.size();
        for (int i = 0; i < len; ++i) {
            int csize = combin.size();
            if (csize == 0)
                ret.push_back(first.substr(i, 1));
            else {
                for (int j = 0; j < csize; ++j) {
                    ret.push_back(first[i] + combin[j]);
                }
            }
        }

        return ret;
    }
};

int main(void) {
    Solution so;
    vector<string> ret;
    ret = so.letterCombinations("23");
    for (int i = 0; i < ret.size(); ++i)
        cout << ret[i] << "    " << endl;
    cout << endl;

    return 0;
}