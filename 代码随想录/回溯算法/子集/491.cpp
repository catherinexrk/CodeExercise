#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;
//https://leetcode.cn/problems/non-decreasing-subsequences/

class Solution {
public:
	vector<vector<int>> result;
	vector<int> path;
	void backTracking(vector<int>& nums,int startIndex){
		if(path.size() >= 2) 
			result.push_back(path);
		if(startIndex >= nums.size()) return;
		
		unordered_set<int> used;//记录使用过的元素，避免重复
		for(int i = startIndex;i < nums.size();i++){
			//当前nums[i]  < path末尾元素
			if(!path.empty() && path.back() > nums[i]) 
				continue;
			
			
			
			if(used.find(nums[i]) != used.end())
				continue;//找到了重复元素，跳过
			
			used.insert(nums[i]);
			path.push_back(nums[i]);
			backTracking(nums,i + 1);
			path.pop_back();
		}
	}
	
	vector<vector<int>> findSubsequences(vector<int>& nums) {
		backTracking(nums,0);
		return result;
	}
};
