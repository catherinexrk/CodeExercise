#include <iostream>
#include <vector>
#include <algorithm>
//#include <unordered_set>

using namespace std;
//https://leetcode.cn/problems/house-robber-ii/

class Solution {
public:
	int rob(vector<int>& nums) {
		if (nums.size() == 0)
			return 0;
		if (nums.size() == 1)
			return nums[0];
		if (nums.size() == 2)
			return max(nums[0], nums[1]);
		
		// 不偷第一间房屋[1,n-1]
		int notFirst = robRange(nums, 1, nums.size() - 1);
		// 不偷最后一间房屋[0,n-2]
		int first = robRange(nums, 0, nums.size() - 2);
		
		return max(notFirst, first);
	}
	
private:
	int robRange(vector<int>& nums, int start, int end) {
		if (end == start) {
			return nums[start];
		}
		
		vector<int> dp(end - start + 1, 0);
		dp[0] = nums[start];
		dp[1] = max(nums[start], nums[start + 1]);
		
		for (int i = 2; i <= end - start; i++) {
			//dp[i-1]表示不偷当前房间  dp[i-2]+nums[start + i]表示偷当前房间
			dp[i] = max(dp[i - 1], dp[i - 2] + nums[start + i]);
		}
		
		return dp.back();
	}
	
	int func(vector<int>& nums, int start, int end){
		vector<int> dp(end-start+1,0);
		
		dp[0] = nums[start];
		dp[1] = max(nums[start],nums[start]+1);
		
		for(int i = 2;i < end - start;i++){
			dp[i] = max(dp[i-1],dp[i-2] + nums[start+i]);
		}
		return dp.back();
	}
};
