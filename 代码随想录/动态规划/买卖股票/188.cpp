#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
//https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-iv/

class Solution {
public:
	int maxProfit(int k, vector<int>& prices) {
		if(prices.size() == 0)
			return 0;
		
		vector<vector<int>> dp(prices.size(),vector<int>(2 * k + 1,0));
		
		//初始化，表示从不持有股票的状态下买入股票之后，手头有的现金-prices[0]
		for(int i = 1;i < 2 * k;i += 2){
			dp[0][i] = -prices[0];
		}
		/**
		 * 0不操作
		 * 1第一次买入
		 * 2第一次卖出
		 * 3第二次买入
		 * 4第二次卖出
		 */
		
		for (int i = 1;i < prices.size(); i++) {
			for (int j = 0; j < 2 * k - 1; j += 2) {
				//第i天买入
				//1.保持第i-1天结束时进行了j+1次交易的状态dp[i - 1][j + 1]
				//2.在第i天买入，然后从第i-1天结束时进行了j次交易的状态减去第i天的股票价格dp[i - 1][j] - prices[i]
				dp[i][j + 1] = max(dp[i - 1][j + 1], dp[i - 1][j] - prices[i]);
				//第i天卖出
				dp[i][j + 2] = max(dp[i - 1][j + 2], dp[i - 1][j + 1] + prices[i]);
			}
		}
		
		return dp[prices.size() - 1][2 * k];
	}
};
