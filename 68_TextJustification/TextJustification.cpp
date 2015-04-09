// TestJustification.cpp

/** 
 * Given an array of words and a length L, format the text such that each line has exactly L characters and is fully (left and right) justified.

 * You should pack your words in a greedy approach; that is, pack as many words as you can in each line. Pad extra spaces ' ' when necessary so that each line has exactly L characters.

 * Extra spaces between words should be distributed as evenly as possible. If the number of spaces on a line do not divide evenly between words, the empty slots on the left will be assigned more spaces than the slots on the right.

 * For the last line of text, it should be left justified and no extra space is inserted between words.

 * For example,
 * words: ["This", "is", "an", "example", "of", "text", "justification."]
 * L: 16.

 * Return the formatted lines as:
 * [
 *    "This    is    an",
 *    "example  of text",
 *    "justification.  "
 * ]
 * Note: Each word is guaranteed not to exceed L in length.

 * click to show corner cases.

 * Corner Cases:
 * A line other than the last line might contain only one word. What should you do in this case?
 * In this case, that line should be left-justified.
 */

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int L) {
        vector<string> ret;
        int size = words.size();
        if (0 == size) {
            string temp(L, ' ');
            ret.push_back(temp);
            return ret;
        }

        int i = 0;
        while (i < size) {
            int chars = words[i].size();
            string line;

            int j = 1;
            while (i+j<size && chars+words[i+j].size() < L)  {                 
                chars = chars + words[i+j].size() + 1; // 1, 空格,保证两个word间至少一个空格
                ++j;
            }

            if (1 == j) {
                line = words[i++];
                string empty(L-line.size(), ' ');
                line += empty;
            }
            else if (i+j < size){
                int avg = (L-chars+(j-1)) / (j-1);  // (chars-(j-1)),表示实际单词的字符数
                string empty(avg, ' ');
                int remain = (L-chars+(j-1)) % (j-1);
                line = words[i];
                int k = i;
                for (++i; i < k+j; ++i) {
                    line += empty;
                    if (remain-- > 0) { line += ' '; }
                    line += words[i];
                }
            }
            else {  // i+j == size;
                line = words[i];
                int k = i;
                for (++i; i < k+j; ++i) {
                    line += ' ';
                    line += words[i];
                }
                string empty(L-line.size(), ' ');
                line += empty;
            }

            ret.push_back(line);
        }

        return ret;
    }
};

int main(void) {
    Solution so;
    vector<string> str;
    str.push_back("This");
    str.push_back("is");
    str.push_back("an");
    str.push_back("example");
    str.push_back("of");
    str.push_back("text");
    str.push_back("justifica");
    str.push_back("j.");

    vector<string> str1 = so.fullJustify(str, 16);

    for (int i = 0; i < str1.size(); ++i)
        cout << str1[i] << endl;

    return 0;
}