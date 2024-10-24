#include <stdlib.h>
#include <iostream>
#include <vector>
#include <string>

using namespace std;
//https://leetcode.cn/problems/integer-break/

class Solution {
public:
	int integerBreak(int n) {
		vector<int> dp(n + 1);//dp[i]：拆分数字i的最大乘积
		dp[2] = 1;
//		dp[i] = max(j * (i - j),j * dp[i - j]);
		for(int i = 3;i <= n;i++){
			for(int j = 1;j <= i/2;j++){
				/**
				 * j * (i - j) 将i拆分成两份，一个是j，一个是i-j
				 * i * dp[i - j] 将i-j继续拆分
				 */
				dp[i] = max(dp[i],max(dp[i - j] * j,j * (i - j)));
			}
		}
		
		return dp[n];
	}
	
	int integerBrak(int n){
		if(n == 2) return 1;
		if(n == 3) return 2;
		if(n == 4) return 4;
		int result = 1;
		while(n > 4){
			result *= 3;
			n -= 3;
		}
		result *= n;
		return result;
	}
};
