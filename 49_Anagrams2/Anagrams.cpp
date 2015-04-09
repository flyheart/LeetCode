// Anagrams.cpp

/**
 * Given an array of strings, return all groups of strings that are anagrams.
 * Note: All inputs will be in lower-case.

 * For example:
 * Input:　　["tea","and","ate","eat","den"]
 * Output:   ["tea","ate","eat"]
*/

/**
 * idea:
 * http://stackoverflow.com/questions/8538924/given-a-string-array-return-all-groups-of-strings-that-are-anagrams
 * We define an alphabet, which contains every letter we may have in our wordlist. Next, we need a different prime for each of the letters in the alphabet, I recommend using the smallest you can find.

 * That would give us the following mapping: { a => 2, b => 3, c => 5, d => 7, etc }

 * Now count the letters in the word you want to represent as integer, and build your result integer as follows:

 * Pseudocode:

 * result = 1
 * for each letter:
 * ....result *= power(prime[letter], count(letter,word)
 * some examples:

 * aaaa => 2^4

 * aabb => 2^2 * 3^2 = bbaa = baba = ...

 * and so on.

 * So you will have an integer representing each word in your dictionary and the word you want to check will be able to be converted to an integer. So if n is the size of your wordlist and k is the size of the longest word it will take O(nk) to build your new dictionary and O(k) to check a new word.

 * Hackthissite.com has a programming challenge which is: Given a scrambled word, look it up in a dictionary to see if any anagrams of it are in the dictionary. There is a good article on an efficient solution to the problem from which I have borrowed the answer, it also goes into detail on further optimisations.
 */

#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

class Solution {
public:
    vector<string> anagrams(vector<string>& strs) {
        buildPrime();
        vector<string> ret;
        map<int, int> hash;
        int size = strs.size();
        for (int i = 0; i < size; ++i) {
            int ws = strs[i].size();    // ws, word size
            int num = 1;
            for (int j = 0; j < ws; ++j) {
                num *= factor[strs[i][j]];  // 当字符串非常长时，num将越界
            }
            if (0 == hash.count(num)) {
                hash[num] = i;
            }
            else {
                if (-1 != hash[num]) {
                    ret.push_back(strs[hash[num]]);
                    hash[num] = -1;
                }
                ret.push_back(strs[i]);
            }
        }
        return ret;
    }
private:
    static const int LEN = 256;
    int factor[LEN];
    void buildPrime() {
        factor[0] = 1;
        factor[1] = 2;

        int count = 2;
        int num = 3;
        while (count < LEN) {
            int i = 1;
            for (; i < count; ++i) {
                if (0 == num%factor[i])
                    break;
            }
            if (i == count) 
                factor[count++] = num;
            num += 2;
        }
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