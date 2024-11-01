#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
//https://leetcode.cn/problems/partition-equal-subset-sum/

class Solution {
public:
	bool canPartition(vector<int>& nums) {
		/**
		 * 将问题抽象成01背包问题，求能否将容量为sum/2的背包填满，如果可以填满，则说明可以
		 */
		
		int sum = 0;
		for(int temp:nums)
			sum += temp;
		
		if(sum % 2 == 1) return false;
		int target = sum / 2;
		
		//总和不会超过20000，因此背包最大装一半即可10001即可
		vector<int> dp(10001,0);
		
		//遍历背包
		for(int i = 0;i < nums.size();i++){
			//遍历容量
			for(int j = target;j >= nums[i];j--){
				dp[j] = max(dp[j],dp[j - nums[i]] + nums[i]);
			}
		}
		
		//集合中的元素正好凑成target
		if(dp[target] == target) return true;
		return false;
	}
};

class Solution2 {
public:
	bool canPartition(vector<int>& nums) {
		int sum = 0;
		for(int temp:nums)
			sum += temp;
		
		if(sum % 2 == 1) return false;
		int target = sum / 2;
		
		vector<int> dp(10001,0);
		
		for(int i = 0;i < nums.size();i++){
			for(int j = target;j >= nums[i];j--){
				dp[j] = max(dp[j],dp[j - nums[i]] + nums[i]);
			}
		}
		
		if(dp[target] == target) return true;
		return false;
	}
};
