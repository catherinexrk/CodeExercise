#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

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
