#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
//https://leetcode.cn/problems/longest-increasing-subsequence/

class Solution {
public:
	int lengthOfLIS(vector<int>& nums) {
		if(nums.size() <= 1)
			return nums.size();
		
		//dp[i] 表示i之前的以nums[i]为结尾的最长递增子序列长度
		//dp[i]表示以当前nums[i]为结尾的最长递增子序列的长度
		vector<int> dp(nums.size(),1);
		int result = 0;
		
		for(int i = 1;i < nums.size();i++){
			for(int j = 0;j < i;j++){
				if(nums[i] > nums[j])
					dp[i] = max(dp[i],dp[j] + 1);
			}
			
			if(dp[i] > result)
				result = dp[i];
		}
		
		return result;
	}
	
	int func(vector<int>& nums){
		if(nums.size() <= 1)
			return nums.size();
		
		vector<int> dp(nums.size(),1);
		
		int result = 0;
		
		for(int i = 1;i < nums.size();i++){
			for(int j = 0;j < i;j++){
				if(nums[i] > nums[j])
					dp[i] = max(dp[j] + 1,dp[i]);
			}
			
			result = result > dp[i] ? result:dp[i];
		}
		
		return result;
	}
};
