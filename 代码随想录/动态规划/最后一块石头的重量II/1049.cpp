#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
//https://leetcode.cn/problems/last-stone-weight-ii/

class Solution {
public:
	int lastStoneWeightII(vector<int>& stones) {
		/**
		 * dp
		 */
		
		//初始化dp背包  dp[j]表示容量为j，最大价值为dp[j]
		vector<int> dp(30*500+1,0);
		
//		dp[j] = max(dp[j],dp[j - nums[i]] + nums[i]);
		int sum = 0;
		for(int i = 0;i < stones.size();i++)
			sum += stones[i];
		
		int target = sum/2;
		
		
		//遍历物品
		for(int i = 0;i < stones.size();i++){
			//遍历背包
			for(int j = target;j >= stones[i];j--){
				dp[j] = max(dp[j],dp[j - stones[i]] + stones[i]);
			}
		}
		
		return (sum - dp[target]) -dp[target];
	}
};

class Solution2 {
public:
	int lastStoneWeightII(vector<int>& stones) {
		vector<int> dp(30*500+1,0);
		
		int sum = 0;
		for(int temp : stones)
			sum += temp;
		
		int target = sum/2;
		
		for(int i = 0;i < stones.size();i++){
			for(int j = target;j >= stones[i];j--){
				dp[j] = max(dp[j],dp[j - stones[i]] + stones[i]);
			}
		}
		
		return sum - dp[target] * 2;
	}
};
