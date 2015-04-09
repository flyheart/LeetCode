// Anagrams.cpp

/**
 * Given an array of strings, return all groups of strings that are anagrams.
 * Note: All inputs will be in lower-case.

 * For example:
 * Input:¡¡¡¡["tea","and","ate","eat","den"]
 * Output:   ["tea","ate","eat"]
*/


#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
using namespace std;

class Solution {
public:
    size_t hashValue(string str) {
        sort(str.begin(), str.end());
        int power = 1;
        size_t result = 0;
        for (char c : str) {
            result += (c - 'a' + 1)  * power;
            power *= 26;
        }
        return result;
    }

    vector<string> anagrams(vector<string> &strs) {
        vector<string> result;
        unordered_map<size_t, vector<string>> mp;

        for (string &str : strs) {
            size_t value = hashValue(str);
            mp[value].push_back(str);
        }

        for (auto it = mp.begin(); it != mp.end(); ++it) {
            if (it->second.size() >= 2) {
                for (string s : it->second)
                    result.push_back(s);
            }
        }
        return result;
    }
};

int main(void) {
    Solution so;
    vector<string> input;
    input.push_back("tea");
    input.push_back("and");
    input.push_back("ate");
    input.push_back("eat");
    input.push_back("den");

    vector<string> ret = so.anagrams(input);
    for (int i = 0; i < ret.size(); ++i)
        cout << ret[i] << " ";
    cout << endl;

    return 0;
}