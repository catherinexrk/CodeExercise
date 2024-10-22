#include <stdlib.h>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
//https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-ii/

class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int maxPrice = 0;
		for(int i = 1;i < prices.size();i++){
			//遇到正数就去收集
			maxPrice += max(prices[i] - prices[i - 1],0);
		}
		return maxPrice;
	}
};

class Solution2{
public:
	int maxProfit(vector<int>& prices){
		int result = 0;
		for(int i = 1;i < prices.size();i++){
			result += max(prices[i] - prices[i- 1],0);
		}
		
		return result;
	}
};
