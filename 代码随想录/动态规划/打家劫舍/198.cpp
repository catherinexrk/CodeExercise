#include <iostream>
#include <vector>
#include <algorithm>
//#include <unordered_set>

using namespace std;
//https://leetcode.cn/problems/house-robber/

class Solution {
public:
	int rob(vector<int>& nums) {
		if(nums.size() == 0)
			return 0;
		if(nums.size() == 1)
			return nums[0];
		
		//dp[i]表示从0到当前i的房间，偷窃的最大价值是dp[i]
		vector<int> dp(nums.size());
		dp[0] = nums[0];
		dp[1] = max(nums[0],nums[1]);
		
		for(int i = 2;i < nums.size();i++){
			dp[i] = max(dp[i-1],dp[i-2] + nums[i]);
		}
		
		return dp[nums.size() - 1];
	}
};
