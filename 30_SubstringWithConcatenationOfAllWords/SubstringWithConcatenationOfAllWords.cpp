/**
 * You are given a string, S, and a list of words, L, that are all of the same length. 
 * Find all starting indices of substring(s) in S that is a concatenation of each word in 
 * L exactly once and without any intervening characters.

 * For example, given:
 * S: "barfoothefoobarman"
 * L: ["foo", "bar"]

 * You should return the indices: [0,9].
 * (order does not matter).
 */

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <list>
using namespace std;

class Solution {
public:
    vector<int> findSubstring(string S, vector<string> &L) {
        int size = L.size();
        if (0 == S.size() || 0 == size) return ret;
        for (int i = 0; i < size; ++i) {
            int count = hash.count(L[i]);
            if (0 == count) hash[L[i]] = 1;
            else            hash[L[i]] += 1;
        }
        int word_len = L[0].size();
        for (int i = 0; i < word_len; ++i) {
            serachString(S, i, word_len, size);
        }

        return ret;
    }
private:
    vector<int> ret;
    unordered_map<string, int> hash;    // ��L�е�Ԫ��ӳ�䵽hash����
    void  serachString(string str, int start, int word_len, int size) { // ˼·�� 03Longest Substring Without Repeating Characters����
        int len = size; // ָʾδƥ�����ĳ���
        unordered_map<string, list<int> > index;
        int i = start;
        // ����ת��Ϊint��������Ĭ��Ϊunsigned int���������������ʽ����Ϊunsigned int ���ͣ���
        // str.size() < word_len,�����������ã�0��ȴ�����һ�������ֵ
        for (int j = start; j <= (int)str.size() - word_len; j += word_len) {   
            string word = str.substr(j, word_len);
            if (hash.count(word) > 0) {
                for (int k = 0; k < index[word].size(); ++k) {
                    if (index[word].front() < i)  { 
                        index[word].erase(index[word].begin()); 
                    }
                    else            break;
                }
                if (hash[word] > index[word].size()) {
                    index[word].push_back(j);
                    --len;
                }
                else {  
                    len += (index[word].front() - i);
                    i = index[word].front() + word_len;
                    index[word].erase(index[word].begin());
                    index[word].push_back(j);
                }
                if (0 == len) {
                    ret.push_back(i);
                    i += word_len;
                    ++len;
                }
            }
            else {
                i = j + word_len;
                len = size;
            }
        }
    }
};

int main(void) {
    Solution so;
    vector<string> str;
    str.push_back("bb");
    str.push_back("aa");
    str.push_back("bb");
    str.push_back("aa");
    str.push_back("bb");
    vector<int> ret = so.findSubstring("aabbaabbaabb", str);
    for (int i = 0; i < ret.size(); ++i)
        cout << ret[i] << '\t';
    cout << endl;

    return 0;
}