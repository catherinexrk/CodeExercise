#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
//https://leetcode.cn/problems/target-sum/

class Solution {
public:
	int findTargetSumWays(vector<int>& nums, int target) {
		//left = (target + sum)/2
		//问题转换为在nums中找出和为left的组合
		int sum = 0;
		for(int i = 0;i < nums.size();i++)
			sum += nums[i];
		
		if(abs(target) > sum) //数组中没有数可以相加超过target
			return 0;
		
		if((target + sum) % 2 == 1) //不可能将这数组分为和相等的子集
			return 0;
		
		int bagSize = (target + sum) / 2;//这是背包的总容量bagSize
		vector<int> dp(bagSize + 1,0);
		dp[0] = 1;//将其初始化为1，背包容量为0，有一种方法
		
		for(int i = 0;i < nums.size();i++){
			for(int j = bagSize;j >= nums[i];j--){
				//方法的累加
				dp[j] += dp[j - nums[i]];
			}
		}
		return dp[bagSize];
	}
};

class Solution2 {
public:
	int findTargetSumWays(vector<int>& nums, int target) {
		int sum = 0;
		for(int temp : nums)
			sum += temp;
		
		if(abs(target) > sum)
			return 0;
		if((target + sum) % 2 == 1)
			return 0;
		
		int bigSize = (sum + target)/2;
		vector<int> dp(bigSize+1,0);
		
		dp[0] = 1;//背包容量为0，有一种存储方法，即啥都不放
		for(int i = 0;i < nums.size();i++){
			for(int j = bigSize;j >= nums[i];j--){
				/**
				 * dp[j]为背包容量为j，有多少种存储方案即组合数
				 * nums[i]为当前的数字，及nums[i]的容量
				 * j - nums[i]表示当前的背包容量
				 * dp[j - nums[i]]表示容量为j - nums[i]时，有dp[j - nums[i]]的组合数
				 */
				dp[j] += dp[j - nums[i]];
			}
		}
		
		return dp[bigSize];
	}
};
