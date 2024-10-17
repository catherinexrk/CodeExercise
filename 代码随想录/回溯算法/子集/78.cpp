#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;
//https://leetcode.cn/problems/subsets/

/**
 * 子集问题不同于切割问题和组合问题，子集问题是要遍历所有节点，而后两个则是遍历叶子节点
 */
class Solution {
public:
	vector<vector<int>> result;
	vector<int> path;
	
	void backTracking(vector<int>& nums,int startIndex){
		result.push_back(path);
		if(startIndex >= nums.size()){
			return;
		}	
		
		for(int i = startIndex;i < nums.size();i++){
			path.push_back(nums[i]);
			
			backTracking(nums,i + 1);//从i+1开始，元素不重复
			path.pop_back();
		}
	}
	
	
	vector<vector<int>> subsets(vector<int>& nums) {
		backTracking(nums,0);
		return result;
	}
};
