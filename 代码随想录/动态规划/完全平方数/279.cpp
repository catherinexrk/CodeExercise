#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
//https://leetcode.cn/problems/perfect-squares/

class Solution {
public:
	int numSquares(int n) {
		/**
		 * 物品可以无限使用，凑满背包容量为n的最小方法数
		 */
		//数值为n 最小数量dp[n]
		vector<int> dp(n+1,INT_MAX);
		
		dp[0] = 0;
		
//		//遍历物品
//		for(int i = 1;i * i <= n;i++){
//			//遍历背包
//			for(int j = i * i;j <= n;j++){
//				dp[j] = min(dp[j],dp[j - i* i] + 1);
//			}
//		}
		
		//遍历背包
		for(int j = 1;j <= n;j++){
			for(int i = 1;i * i <= n;i++){
				if(j >= i*i){
					dp[j] = min(dp[j],dp[j - i*i] + 1);
				}
			}
		}
		
		return dp[n];
	}
};
