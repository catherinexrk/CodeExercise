#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
//https://leetcode.cn/problems/maximum-subarray/

class Solution {
public:
	int maxSubArray1(vector<int>& nums) {
		int result = INT_MIN;
		int count = 0;
		for(int i = 0;i < nums.size();i++){
			count += nums[i];
			
			if(count > result)
				result = count;
			if(count < 0)
				count = 0;
		}
		
		return result;
	}
	
	int maxSubArrayGreedy2(vector<int>& nums){
		int result = nums[0];
		int cur = nums[0];
		
		for(int i = 1;i < nums.size();i++){
			cur = max(nums[i],nums[i] + cur);
			
			result = max(result,cur);
		}
		
		return result;
	}

	int maxSubArray(vector<int>& nums) {
		if(nums.size() == 0)
			return nums[0];
		//dp[i]表示下标i（以nums[i]）结尾的最大连续子序列之和为dp[i]
		vector<int> dp(nums.size());
		//dp[i] = dp[i-1] + nums[i]
		//dp[i] = nums[i]
		dp[0] = nums[0];
		
		int result = dp[0];
		
		for(int i =1;i < nums.size();i++){
			dp[i] = max(dp[i-1] + nums[i],nums[i]);
			
			result = max(result,dp[i]);
		}
		
		return result;
	}
};
