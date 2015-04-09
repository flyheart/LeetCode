// Anagrams.cpp

/**
 * Given an array of strings, return all groups of strings that are anagrams.
 * Note: All inputs will be in lower-case.

 * For example:
 * Input:¡¡¡¡["tea","and","ate","eat","den"]
 * Output:   ["tea","ate","eat"]
*/

/**
 * idea:
 * http://stackoverflow.com/questions/8538924/given-a-string-array-return-all-groups-of-strings-that-are-anagrams
 * For each word in the vector, sort the word in dictoray order.
 */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

class Solution {
public:
    vector<string> anagrams(vector<string>& strs) {
        vector<string> ret;
        int size = strs.size();
        map<string, vector<int>> hash;
        for (int i = 0; i < size; ++i) {
            string word = strs[i];
            sort(word.begin(), word.end());
            hash[word].push_back(i);
        }
        
        map<string, vector<int>>::iterator it = hash.begin();
        for (; it != hash.end(); ++it) {
            int lsize = it->second.size();
            if (lsize < 2) continue;
            for (int i = 0; i < lsize; ++i)
                ret.push_back(strs[(it->second)[i]]);
        }

        return ret;
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