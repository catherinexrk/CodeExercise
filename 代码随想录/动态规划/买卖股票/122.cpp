#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
//https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-ii/

class Solution {
public:
	int maxProfitGreed(vector<int>& prices) {
		int profit = 0;
		for(int i = 1;i < prices.size();i++){
			profit += max(prices[i] - prices[i - 1],0);
		}
		
		return profit;
	}
	
	int maxProfitDP(vector<int>& prices) {
		int len = prices.size();
		
		vector<vector<int>> dp(len,vector<int>(2));
		
		dp[0][0] = -prices[0];//持有股票所得到的最多现金
		dp[0][1] = 0;//不持有股票所得到的最多现金
		
		for(int i = 1;i < len;i++){
			dp[i][0] = max(dp[i - 1][0],dp[i - 1][1] - prices[i]);//可以多次卖
			dp[i][1] = max(dp[i - 1][0] + prices[i],dp[i - 1][1]);
		}
		
		return dp[len - 1][1];
	}
};
