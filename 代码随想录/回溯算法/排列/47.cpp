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
