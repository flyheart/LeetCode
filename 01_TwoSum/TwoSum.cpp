/*
Given an array of integers, find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.

You may assume that each input would have exactly one solution.

Input: numbers={2, 7, 11, 15}, target=9
Output: index1=1, index2=2
*/
#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
	vector<int> twoSum(vector<int> &numbers, int target) {
		vector<int> res;	// ´æ´¢Êä³ö½á¹û
		map<int, int> hmap;
		int n = numbers.size();
		for (int i = 0; i < n; ++i) {
			if (!hmap.count(numbers[i]))
				hmap[numbers[i]] = i;

			if (hmap.count(target - numbers[i])) {
				int k = hmap[target - numbers[i]];
				if (k < i) {
					res.push_back(k+1);
					res.push_back(i+1);

					return res;
				}
			}
		}
	}
};

int main() {
	vector<int> num;
	num.push_back(3);
	num.push_back(2);
	num.push_back(4);

	Solution so;
	vector<int> res = so.twoSum(num, 6);
	cout << res[0] << res[1] << endl;
}