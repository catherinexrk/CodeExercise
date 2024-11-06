#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
//https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-with-cooldown/

class Solution {
public:
	int maxProfit(vector<int>& prices) {
		if(prices.size() == 0)
			return 0;
		
		//dp[i][0]当天持有股票的状态
		//dp[i][1]当天保持前一天卖出股票的状态
		//dp[i][2]当天卖出股票的状态
		//dp[i][3]冷冻期不可以进行股票操作
		
		vector<vector<int>> dp(prices.size(),vector<int>(4,0));
		/**
		 * dp[i][0] = max{   dp[i-1][0]  dp[i-1][3]-prices  dp[i-1][1]-prices     }
		 * 
		 * dp[i][1] = dp[i-1][1]  dp[i-1][3]
		 * 
		 * dp[i][2] = dp[i-1][0] + prices
		 * 
		 * dp[i][3] = dp[i-1][2]
		 */
		
		dp[0][0] = -prices[0];
		dp[0][1] = 0;
		dp[0][2] = 0;
		dp[0][3] = 0;
		
		for(int i = 1;i < prices.size();i++){
			dp[i][0] = max(max(dp[i-1][0],dp[i-1][3] - prices[i]),dp[i-1][1] - prices[i]);
			dp[i][1] = max(dp[i-1][1],dp[i-1][3]);
			dp[i][2] = dp[i-1][0] + prices[i];
			dp[i][3] = dp[i-1][2];
		}
		
		int n = prices.size();
		return max(dp[n-1][3],max(dp[n-1][2],dp[n-1][1]));
	}
};
