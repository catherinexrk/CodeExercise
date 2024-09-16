#include <stdlib.h>
#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

//https://leetcode.cn/problems/group-anagrams/
class Solution {
public:
	vector<vector<string>> groupAnagrams(vector<string>& strs) {
		//数组为空
		if(strs.size() == 0){
			return {};
		} else if(strs.size() == 1){
		return {{strs[0]}};
		}
		
		//创建存储正确序列的数组
		vector<vector<string>> result;
		
		unordered_map<string,vector<string>> record;
		for(int i = 0;i < strs.size();i++){
			string key = strs[i];
			sort(key.begin(),key.end());//排序一下key
			record[key].push_back(strs[i]);//将排序后的key相同的字符串插入到unordered_map中
		}
		
		for(auto temp = record.begin();temp != record.end();temp++){
			result.push_back(temp->second);
		}
		
		
		return result;
	}
};
