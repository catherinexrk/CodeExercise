#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
//https://leetcode.cn/problems/longest-continuous-increasing-subsequence/

class Solution {
public:
//	int findLengthOfLCIS(vector<int>& nums) {
//		if(nums.size() <= 1)
//			return nums.size();
//		
//		//dp[i]表示以nums[i]为结尾的序列其最长递增子序列长度
//		vector<int> dp(nums.size(),1);
//		
//		int result = 0;
//		
//		for(int i = 1;i < nums.size();i++){
//			for(int j = 0;j < i;j++){
//				dp[i] = max(dp[j] + 1,dp[i]);
//			}
//			
//			result = dp[i] > result ? dp[i] : result;
//		}
//		
//		return result;
//	}
	
	int findLengthOfLCIS(vector<int>& nums) {
		if(nums.size() <= 1)
			return nums.size();
		
		//当前以nums[i]为结尾的连续递增子序列长度
		vector<int> dp(nums.size(),1);
		
		int result = 1;
		
		for(int i = 1;i < nums.size();i++){
			//比较nums[i]和nums[i-1]进行连续之间的数字进行比较
			if(nums[i] > nums[i - 1])
				dp[i] = dp[i - 1] + 1;
			
			result = dp[i] > result ? dp[i] : result;
		}
		
		return result;
	}
};
