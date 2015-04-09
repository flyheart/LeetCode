// WildcardMatching.pp

/**
 * Implement wildcard pattern matching with support for '?' and '*'.

 * '?' Matches any single character.
 * '*' Matches any sequence of characters (including the empty sequence).

 * The matching should cover the entire input string (not partial).

 * The function prototype should be:
 * bool isMatch(const char *s, const char *p)

 * Some examples:
 * isMatch("aa","a") ¡ú false
 * isMatch("aa","aa") ¡ú true
 * isMatch("aaa","aa") ¡ú false
 * isMatch("aa", "*") ¡ú true
 * isMatch("aa", "a*") ¡ú true
 * isMatch("ab", "?*") ¡ú true
 * isMatch("aab", "c*a*b") ¡ú false
 */

#include <iostream>
using namespace std;

class Solution {
public:
    bool isMatch(const char* s, const char* p) {
        if (NULL==s || NULL==p) return false;
        const char *star=NULL, *ss=NULL;

        while (0 != *s) {
            if (*s==*p || '?'==*p)      { ++s; ++p; continue; }
            if ('*' == *p)              { star = p++; ss = s; continue; }
            if (NULL != star)           { s = ss+1; ss = s; p = star+1; continue; }
            return false;
        }
        while ('*' == *p) ++p;
        return 0==*p;
    }
};

int main(void) {
    Solution so;
    cout << so.isMatch("aab", "c*b") << endl;
    cout << so.isMatch("aa", "?*") << endl;
    cout << so.isMatch("a", "?*??a*") << endl;  // false
    cout << so.isMatch("", "?a*") << endl;  // false
    cout << so.isMatch("a", "ab*") << endl;
    cout << so.isMatch("aabc", "a*ab*") << endl;
    cout << so.isMatch("aaabbbaabaaaaababaabaaabbabbbbbbbbaabababbabbbaaaaba", "a*******b") << endl;

    return 0;
}