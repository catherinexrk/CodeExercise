#include <stdlib.h>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

//https://leetcode.cn/problems/group-anagrams/
class Solution {
public:
	vector<vector<string>> groupAnagrams(vector<string>& strs) {
		//特殊情况判断
		if(strs.size() == 0){
			return {};
		} else if(strs.size() == 1){
			return {{strs[0]}};
		}
		vector<vector<string>> result;
		
		
		
		
		return result;
	}
};
