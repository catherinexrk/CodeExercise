#include <stdlib.h>
#include <iostream>
#include <vector>
#include <string>

using namespace std;
//https://leetcode.cn/problems/min-cost-climbing-stairs/

class Solution {
public:
	int minCostClimbingStairs(vector<int>& cost) {
		//dp[i]表示到达第i台阶所花费的最小体力为dp[i]
		vector<int> dp(cost.size() + 1);
		dp[0] = 0;
		dp[1] = 0;
		//dp[i]表示到达i台阶所需要的最小的体力
		
//		dp[i] = min((dp[i - 1] + cost[i]),(dp[i - 2] + cost[i - 2]));
		
		for(int i = 2;i <= cost.size();i++){
			dp[i] = min(dp[i - 1] + cost[i - 1],dp[i - 2] + cost[i - 2]);
		}
		
		return dp[cost.size()];
	}
	
	int damn(vector<int>& cost){
		vector<int> dp(cost.size() + 1);
		//dp表示到达i层台阶所需要的最小体力
		
		//到达i台阶，只能由i-1或者i-2上来，因此存在
		//dp[i] = min(dp[i-1] + cost[i - 1],dp[i - 2] + cost[i - 2])
		dp[0] = 0;
		dp[1] = 0;
		
		for(int i = 2;i <= cost.size();i++){
			dp[i] = min(dp[i - 1] + cost[i - 1],dp[i - 2] + cost[i - 2]);
		}
		
		return dp[cost.size()];
	}
};
