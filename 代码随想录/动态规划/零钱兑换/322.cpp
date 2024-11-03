#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
//https://leetcode.cn/problems/coin-change/

class Solution {
public:
	int coinChange(vector<int>& coins, int amount) {
		vector<int> dp(amount + 1,INT_MAX);
		//计算最小的组合，那就是112和211是同一组合
		dp[0] = 0;
		
		//遍历物品
		for(int i = 0;i < coins.size();i++){
			//遍历背包
			for(int j = coins[i];j <= amount;j++){
				if(dp[j - coins[i]] != INT_MAX)
					dp[j] = min(dp[j],dp[j - coins[i]] + 1);
			}
		}
		if(dp[amount] == INT_MAX) 
			return -1;
		return dp[amount];
	}
};
