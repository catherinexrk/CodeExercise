#include <stdlib.h>
#include <iostream>
#include <vector>
#include <string>

using namespace std;
//https://leetcode.cn/problems/climbing-stairs/

class Solution {
public:
	int climbStairs(int n) {
		if(n == 1)
			return 1;
		//dp[i]:表示爬到第i个楼层  有dp[i]个方法
		vector<int> dp(n + 1);
		dp[1] = 1;
		dp[2] = 2;
		for(int i = 3;i <= n;i++){
			dp[i] = dp[i - 1] + dp[i - 2];
		}
		
		return dp[n];
	}
};
