// CounAndSay.cpp
/**
The count-and-say sequence is the sequence of integers beginning as follows:
1, 11, 21, 1211, 111221, ...

1 is read off as "one 1" or 11.
11 is read off as "two 1s" or 21.
21 is read off as "one 2, then one 1" or 1211.
Given an integer n, generate the nth sequence.

Note: The sequence of integers will be represented as a string.
 */

/**
��Ŀ�����Ĳ��Ǻ��������ʵ���ǵ�i+1���ַ����ǵ�i���ַ����Ķ�������һ�ַ���Ϊ ��1��

������ĸ��ַ�����1211�����Ķ����� 1��1��1��2,2��1����˵�����ַ�����111221��

������ַ����Ķ����ǣ�3��1��2��2��1��1����˵������ַ�����312211  
 */

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        string ret;
        if (n <= 0) return ret;
        ret = "1";

        for (int i = 1; i < n; ++i) {
            int size = ret.size();
            char pre = ret[0];
            int count = 1;
            string temp;
            for (int i = 1; i < size; ++i) {
                if (ret[i] == pre)  { ++count; }
                else {
                    temp = temp + to_string((long long)count) + pre;
                    count = 1;
                    pre = ret[i];
                }
            }
            ret = temp + to_string((long long)count) + pre;
        }

        return ret;
    }
};

int main(void) {
    Solution so;

    // cout << so.countAndSay(0) << endl;
    cout << so.countAndSay(1) << endl;
    cout << so.countAndSay(2) << endl;
    cout << so.countAndSay(3) << endl;
    cout << so.countAndSay(4) << endl;
    cout << so.countAndSay(5) << endl;

    return 0;
}