#include <stdlib.h>
#include <iostream>
#include <vector>
#include <string>

using namespace std;
//https://leetcode.cn/problems/fibonacci-number/

class Solution {
public:
	int fibTraversal(int n) {
		if(n == 0)
			return 0;
		if(n == 1)
			return 1;
		return fib(n - 1) + fib( n -2);
	}
	
	int fib(int n){
		if(n <= 1)
			return n;
		vector<int> dp(n + 1);
		dp[0] = 0;
		dp[1] = 1;
		//dp[i] = dp[i - 1] + dp[i - 2];
		
		for(int i = 2;i <= n;i++){
			dp[i] = dp[i - 1] + dp[i - 2];
		}
		
		return dp[n];
	}
};

int main(){
	Solution s;
	int result = s.fib(23);
	cout<<result;
}
