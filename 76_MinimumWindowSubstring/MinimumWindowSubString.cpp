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

// !!!!!! LTE (Long Time Exceed)

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string minWindow(string S, string T) {
        const int LEN = 256;
        string ret;
        int sLen = S.size();
        int tLen = T.size();
        if (0==sLen || 0==tLen) return ret;
        int* hash = new int[LEN];
        memset(hash, 0, LEN*sizeof(int));
        int* hash2 = new int[LEN];
        memset(hash2, 0, LEN*sizeof(int));
        for (int i = 0; i < tLen; ++i) {
            hash[T[i]]++;
            hash2[T[i]]++;
        }

        for (int i = 0; i < sLen; ++i) {
            while (i<sLen && 0==hash[S[i]])    ++i;
            int len = tLen;
            int k = i;
            for (; k < sLen; ++k) {
                if (hash[S[k]] > 0) {
                    --hash[S[k]];
                    --len;
                }
                if (0 == len)   break;
            }
            if (k==sLen)   return ret;
            if (0 == ret.size()) ret = S.substr(i, k-i+1);
            else if (k-i+1 < ret.size()) ret = S.substr(i, k-i+1);
            memcpy(hash, hash2, LEN*sizeof(int));
        }

        delete []hash;
        delete []hash2;

        return ret; 
    }
};

int main(void) {
    Solution so;

    cout << so.minWindow("ADOBECODEBANC", "ABC") << endl;

    return 0;
}