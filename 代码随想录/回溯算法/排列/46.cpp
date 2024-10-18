#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;
//https://leetcode.cn/problems/permutations/


/**
 * 排列问题，for循环的开始不再是startindex，而是0
 */
class Solution {
public:
	vector<vector<int>> result;
	vector<int> path;
	
	void backTracking(vector<int> nums,vector<bool> used){
		if(path.size() == nums.size()){
			result.push_back(path);
			return;
		}
		
		for(int i = 0;i < nums.size();i++){
			if(used[i] == true) continue;//当前元素已经被path收录
			used[i] = true;
			
			path.push_back(nums[i]);
			backTracking(nums,used);
			path.pop_back();
			used[i] = false;
		}
		
	}
	
	vector<vector<int>> permute(vector<int>& nums) {
		vector<bool> used(nums.size());
		backTracking(nums,used);
		return result;
	}
};
