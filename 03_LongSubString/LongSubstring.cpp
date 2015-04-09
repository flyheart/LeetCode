/*
Given a string, find the length of the longest substring without repeating characters. 
For example, the longest substring without repeating letters for "abcabcbb" is "abc", 
which the length is 3. For "bbbbb" the longest substring is "b", with the length of 1.
*/

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		int hash[256];
		memset(hash, -1, sizeof(int)*256);
		int index = 0;	// �Ӵ�����ʼλ��
		int length = 0;	// ����Ӵ�����

		for (int i = 0; i < s.size(); ++i) {
			if (hash[s[i]] >= index) {	// �������ظ��ַ�������indexλ��
				index = hash[s[i]] + 1;
			}
			if (i - index + 1 > length) {
				length = i - index + 1;
			}
			hash[s[i]] = i;
		}

		return length;
	}
};

int main() {
	Solution so;
	cout << so.lengthOfLongestSubstring("abcabd") << endl;

	return 0;
}