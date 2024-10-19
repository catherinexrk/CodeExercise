#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;
//https://leetcode.cn/problems/permutations-ii/

class Solution {
public:
	vector<vector<int>> result;
	vector<int> path;
	
	void backTracking(vector<int> nums,vector<bool> used){
		if(path.size() == nums.size()) {
			result.push_back(path);
			return;
		}
		
		for(int i = 0;i < nums.size();i++){
			
			/**
			 * 这一步关于为什么判断used[i - 1] == false
			 * 因为如果当前used[i-1]不为false，说明在i-1前面的时候就已经出现了当前数值
			 * 当前数值已经被使用了，因此此时i位置的数值不可以使用
			 */
			if(i > 0 && nums[i] == nums[i - 1] && used[i - 1] == false)
				continue;
			
			if(used[i] == true){
				continue;//当前元素已经被使用
			}
			used[i] = true;
			path.push_back(nums[i]);
			backTracking(nums,used);
			path.pop_back();
			used[i] = false;
		}
	}
	
	vector<vector<int>> permuteUnique(vector<int>& nums) {
		sort(nums.begin(),nums.end());
		vector<bool> used(nums.size());
		backTracking(nums,used);
		return result;
	}
};

class Solution2 {
public:
	vector<vector<int>> result;
	vector<int> path;
	
	void backTracking(vector<int>& nums,vector<bool> used){
		if(path.size() == nums.size()){
			result.push_back(path);
			return;
		}
		
		for(int i = 0;i < nums.size();i++){
			if( i > 0 && nums[i] == nums[i - 1] && used[i - 1] == false){
				continue;
			}
			
			if(used[i] == true)
				continue;
			
			used[i] = true;
			path.push_back(nums[i]);
			backTracking(nums,used);
			used[i] = false;
			path.pop_back();
		}
		
	}
	
	vector<vector<int>> permuteUnique(vector<int>& nums) {
		sort(nums.begin(),nums.end());
		vector<bool> used(nums.size(),false);
		backTracking(nums,used);
		
		return result;
	}
};


class Solution3 {
public:
	vector<vector<int>> result;
	vector<int> path;
	
	void backTracking(vector<int>& nums,vector<bool> used){
		if(path.size() == nums.size()){
			result.push_back(path);
			return;
		}
		
		unordered_set<int> uset;
		for(int i = 0;i < nums.size();i++){
			if(i > 0 && nums[i] == nums[i - 1] && used[i - 1] == false)
				continue;
			if(used[i] == true)
				continue;
			if(uset.find(nums[i]) != uset.end())
				continue;
			
			path.push_back(nums[i]);
			used[i] = true;
			uset.insert(nums[i]);
			
			backTracking(nums,used);
			
			path.pop_back();
			used[i] = false;
		}
		
	}
	
	vector<vector<int>> permuteUnique(vector<int>& nums) {
		sort(nums.begin(),nums.end());
		vector<bool> used(nums.size(),false);
		
		backTracking(nums,used);
		
		return result;
	}
};
