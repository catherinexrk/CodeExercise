#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;
//https://leetcode.cn/problems/subsets-ii/

class Solution {
public:
	vector<vector<int>> result;
	vector<int> path;
	
	void backTracking(vector<int>& nums,int startIndex){
		result.push_back(path);
		if(startIndex >= nums.size()) return;
		
		for(int i = startIndex;i < nums.size();i++){
			//重复元素，不执行下面的操作
			if( i > startIndex && nums[i] == nums[i - 1]) continue; 
			path.push_back(nums[i]);
			backTracking(nums,i + 1);
			path.pop_back();
		}
	}
	
	
	vector<vector<int>> subsetsWithDup(vector<int>& nums) {
		sort(nums.begin(),nums.end());
		backTracking(nums,0);
		return result;
	}
};


class Solution2{
public:
	vector<vector<int>> result;
	vector<int> path;
	
	void backTracking(vector<int> nums,int startIndex){
		result.push_back(path);
		
		if(startIndex >= nums.size()) return;
		
		for(int i = startIndex;i < nums.size();i++){
			if(i > startIndex && nums[i] == nums[i - 1]) continue;
			
			path.push_back(nums[i]);
			backTracking(nums,i + 1);
			path.pop_back();
		}
	}
	
	
	vector<vector<int>> subsetsWithDup(vector<int>& nums) {
		sort(nums.begin(),nums.end());
		backTracking(nums,0);
		return result;
	}
};

class Solution3{
public:
	vector<vector<int>> result;
	vector<int> path;
	
	void backTracking(vector<int> nums,int startIndex){
		result.push_back(path);
		if(startIndex >= nums.size()) return;
		
		unordered_set<int> used;
		for(int i = startIndex;i < nums.size();i++){
			//跳过重复的元素
			if(used.find(nums[i]) != used.end())
				continue;
			
			used.insert(nums[i]);
			path.push_back(nums[i]);
			backTracking(nums,i + 1);
			path.pop_back();
//			used.erase(nums[i]);这个used只在当前递归中使用，因此不需要手动清除
		}
		
	}
	
	
	vector<vector<int>> subsetsWithDup(vector<int>& nums) {
		sort(nums.begin(),nums.end());
		backTracking(nums,0);
		return result;
	}
};
