// MinimumWindowSubstring.cpp

/**
 * Given a string S and a string T, find the minimum window in S which will contain all the characters 
 * in T in complexity O(n).

 * For example,
 * S = "ADOBECODEBANC"
 * T = "ABC"
 * Minimum window is "BANC".

 * Note:
 * If there is no such window in S that covers all characters in T, return the emtpy string "".

 * If there are multiple such windows, you are guaranteed that there will always be only one unique 
 * minimum window in S.
 */

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string minWindow(string S, string T) {
        string ret;
        const int LEN = 256;
        int hash[LEN] = {0};
        int hash2[LEN] = {0};

        int sLen = S.size();
        int tLen = T.size();
        if (0==sLen || 0==tLen)  return ret;

        for (int m = 0; m < tLen; ++m) {
            ++hash[T[m]];
            ++hash2[T[m]];
        }

        int start = 0;
        int len = tLen;
        while (start<sLen && 0==hash[S[start]]) ++start;
        if (start == sLen)  return ret;
        --hash[S[start]]; --len;
        if (0==len)  return S.substr(start, 1);
        int i = start+1;
        while (i < sLen) {
            while (i<sLen && 0!=len) {
                if (hash[S[i]] > 0) {
                    --len;
                }
                if (hash2[S[i]] > 0) {
                    --hash[S[i]]; 
                }
                if (0 == len)   break;
                ++i;
            }
            if (i == sLen)  return ret;
            if (0==ret.size() || i-start+1 < ret.size()) {
                ret = S.substr(start, i-start+1);
            }

            int temp = start;
            hash[S[start++]]++;
            ++len;
            while (0 == hash2[S[start]])    ++start;
            if (hash[S[temp]] <= 0) len = 0;
            else    ++i;
        }

        return ret;
    }
};

int main(void) {
    Solution so;

    cout << so.minWindow("aaaa", "a") << endl;
    cout << so.minWindow("a", "a") << endl;
    cout << so.minWindow("a", "aa") << endl;
    cout << so.minWindow("aaaabc", "abc") << endl;
    cout << so.minWindow("abbbbc", "abc") << endl;
    cout << so.minWindow("abbbdcabc", "abc") << endl;
    cout << so.minWindow("abbbadcabc", "abc") << endl;

    return 0;
}