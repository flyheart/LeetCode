// SimplifyPath.cpp

/**
 * Given an absolute path for a file (Unix-style), simplify it.

 * For example,
 * path = "/home/", => "/home"
 * path = "/a/./b/../../c/", => "/c"
 * click to show corner cases.

 * Corner Cases:
 * Did you consider the case where path = "/../"?
 * In this case, you should return "/".
 * Another corner case is the path might contain multiple slashes '/' together, such as "/home//foo/".
 * In this case, you should ignore redundant slashes and return "/home/foo".
 */

#include <iostream>
#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        string ret;
        stack<string> st;
        int size = path.size();
        if (0 == size)  return ret;
        int i = 0;
        string p;   // path
        if ('/' == path[i]) {
            p.append(1, path[i]);
            st.push(p);
            p.clear();
            ++i;
            while (i<size && '/'==path[i])  ++i;
        }
        while (i < size) {
            while (i<size && '/'!=path[i]) {
                p.append(1, path[i++]);
            }
            while (i<size && '/'==path[i])  ++i;
            if (".." == p) {
                if (st.size() > 1)  st.pop();
            }
            else if ("." != p) {
                if (i!=size) { p.append(1, '/'); }
                st.push(p);
            }
            p.clear();
        }
        
        traverse(st, ret);
        if (ret.size()>1 && '/'==ret[ret.size()-1])
            ret.erase(ret.size()-1, 1);
        return ret;
    }
private:
    void traverse(stack<string>& st, string& ret) {
        if (0 == st.size()) return;
        string temp = st.top();
        st.pop();
        traverse(st, ret);
        ret += temp;
    }
};

int main(void) {
    Solution so;

    cout << so.simplifyPath("/.") << endl;
    cout << so.simplifyPath("/") << endl;
    cout << so.simplifyPath("/..") << endl;
    cout << so.simplifyPath("///a/./b/../../c/.") << endl;
    cout << so.simplifyPath("/a/./b/../../c/..") << endl;
    cout << so.simplifyPath("/a/./b/../../c//") << endl;
    cout << so.simplifyPath("/a/./b//..//../c//") << endl;
    cout << so.simplifyPath("/a/./..//../c//") << endl;

    return 0;
}