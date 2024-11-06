#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
//https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/

class Solution {
public:
	int maxProfit(vector<int>& prices, int fee) {
		if(prices.size() == 0)
			return 0;
		
		int n = prices.size();
		vector<vector<int>> dp(n,vector<int>(2,0));
		
		//dp[0][0] 当天持有股票所得最多现金  买入不需要交手续费  包括当天买入或者保持前一天保持股票的状态
		//dp[0][1] 当天不持有股票所得最多现金  卖出需要交手续费
		
		//dp[i][0] = dp[i-1][0]          dp[i-1][1] - prices
		//dp[i][1] = dp[i-1][1]     dp[i-1][0] + prices - fee
		
		dp[0][0] = -prices[0];
		dp[0][1] = 0;
		
		for(int i = 1;i < n;i++){
			dp[i][0] = max(dp[i-1][0],dp[i-1][1] - prices[i]);
			dp[i][1] = max(dp[i-1][1],dp[i-1][0] + prices[i] - fee);
		}
		
		return dp[n-1][1];
	}
};
