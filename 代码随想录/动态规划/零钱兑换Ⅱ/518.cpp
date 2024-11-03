#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
//https://leetcode.cn/problems/coin-change-ii/

class Solution {
public:
	int change(int amount, vector<int>& coins) {
		//dp[j]表示凑成总和j有dp[j]种方法
		vector<uint64_t> dp(amount + 1,0);
		
		//总和为0的只有一种方法
		dp[0] = 1;
		//遍历物品
		for(int i = 0;i < coins.size();i++){
			//遍历背包
			for(int j = coins[i];j <= amount;j++){
				dp[j] += dp[j - coins[i]];
			}
		}
		
		return dp[amount];
	}
};
