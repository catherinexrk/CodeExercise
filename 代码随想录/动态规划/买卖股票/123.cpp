#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
//https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-iii/

class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int len = prices.size();
		
		vector<vector<int>> dp(len,vector<int>(5,0));
		/**
		 * dp[i][0] 没有操作
		 * dp[i][1]	第一次持有股票
		 * dp[i][2]	第一次不持有股票
		 * dp[i][3]	第二次持有股票
		 * dp[i][4]	第二次不持有股票
		 */
		dp[0][0] = 0;
		dp[0][1] = - prices[0];
		dp[0][2] = 0;
		dp[0][3] = - prices[0];
		dp[0][4] = 0;
		
		for(int i = 1;i < prices.size();i++){
			/**
			 * 第i天没有进行任何操作，那么第i天的最大利润与第i-1天结束时不持有
			 * 股票的最大利润相同
			 */
			dp[i][0] = dp[i - 1][0];
			/**
			 * 在第i天第一次持有股票，选择
			 * 保持第i-1天第一次持有股票的状态dp[i - 1][1]
			 * 或者在第i天买入股票，需要从第i-1天不持有股票的状态下减去第i天股票的价格，表示售卖出去
			 */
			dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
			/**
			 * 保持第i-1天第一次卖出股票后不持有股票的状态dp[i - 1][2]
			 * 在第2天卖出股票，在第i-1天第一次持有股票的状态上加上第i天股票的价格dp[i - 1][1] + prices[i]
			 */
			dp[i][2] = max(dp[i - 1][2], dp[i - 1][1] + prices[i]);
			/**
			 * 保持第i-1天第二次持有股票不售卖的状态dp[i-1][3]
			 * 在第i-1天第一次卖出股票并且不持有股票的状态下dp[i - 1][2]再去买入第i天的股票，需要-prices[i]
			 */
			dp[i][3] = max(dp[i - 1][3], dp[i - 1][2] - prices[i]);
			/**
			 * 不售卖，保持第i-1天第二次售卖完之后不持有的状态dp[i-1][4]
			 * 在第i-1天第二次持有股票的状态dp[i-1][3]的情况下，加上第i天股票的价格prices[i]
			 */
			dp[i][4] = max(dp[i - 1][4], dp[i - 1][3] + prices[i]);
		}
		
		return dp[len - 1][4];
	}
};


