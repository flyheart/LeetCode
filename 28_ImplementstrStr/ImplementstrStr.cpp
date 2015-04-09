/**
 * Implement strStr().
 * Returns the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.
 */

#include <iostream>
using namespace std;

class Solution {
public:
    int strStr(char* haystack, char* needle) {
        // // Method 1:
        // int len_a = strlen(haystack);
        // int len_b = strlen(needle);
        // if (len_a < len_b)  return -1;
        // for (int i = 0; i < len_a-len_b; ++i) {
        //     int j = 0;
        //     while (haystack[i+j] == needle[i+j])    ++j;
        //     if (j == len_b) return i;
        // }
        // return -1;
        // // Method 2:
        // if (NULL == haystack || NULL == needle) return -1;
        // if (0 == *needle)   return 0;
        // int len = 0;
        // char* temp = needle;
        // while (*temp++)   ++len;
        // int* next = new int[len];
        // getNext(needle, next);
        // int i = 0, j = 0;
        // while (haystack[i] && j < len) {    // 由于j可能等于-1,故不可采用0==needle[j]判断是否到达结尾
        //     if (-1 == j || haystack[i] == needle[j]) { ++i; ++j; }
        //     else { j = next[j]; }
        // }
        // if (0 == needle[j]) return i-len;
        // else                return -1;

        // Method 3: dfa
        int len = strlen(needle);
        const int R = 256;
        int** dfa = new int* [R];
        for (int i = 0; i < R; ++i)
            dfa[i] = new int[len];
        for (int i = 0; i < R; ++i)
            dfa[i][0] = 0;
        dfa[needle[0]][0] = 1;
        int X = 0;  // 起始状态
        int i = 1;
        while (needle[i]) {
            int j = 0;
            for (; j < R; ++j)
                dfa[j][i] = dfa[j][X];
            dfa[needle[i]][i] = i + 1;
            X = dfa[needle[i]][X];
            ++i;
        }

        int k = 0;
        int m = 0;
        while (haystack[k] && m < len) {
            m = dfa[haystack[k++]][m];
        }
        if (m == len) return k-m;
        else    return -1;
    }
private:
    void getNext(char* pat, int* next) {
        int i = 0, j = -1;
        next[0] = -1;
        while (0 != pat[i]) {
            if (-1 == j || pat[j] == pat[i]) {
                ++i; ++j;  
                next[i] = j;
            }
            else    j = next[j];
        }
    }
};

int main(void) {
    Solution so;
    cout << so.strStr("mississippi", "issipi") << endl;

    return 0;
}