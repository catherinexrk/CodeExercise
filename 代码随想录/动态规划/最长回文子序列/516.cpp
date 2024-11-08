#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
//https://leetcode.cn/problems/longest-palindromic-subsequence/

class Solution {
public:
	int longestPalindromeSubseq(string s) {
		//dp[i][j]区间在[i,j]范围内的最长回文子序列的长度是dp[i][j]
		vector<vector<int>> dp(s.size(),vector<int>(s.size(),0));
		
		for(int i = 0;i < s.size();i++){
			//单个字符是回文palindrom
			dp[i][i] = 1;
		}
		
		for(int i = s.size() - 1;i >= 0;i--){
			for(int j = i + 1;j < s.size();j++){
				if(s[i] == s[j]){
					dp[i][j] = dp[i+1][j-1] + 2;
				} else{
					//s[i]和s[j]的同时加入，并不能增加区间[i,j]区间回文子序列的长度
					//加入s[i]的回文子序列长度是dp[i+1][j]
					//加入s[j]的回文子序列长度是dp[i][j-1];
					dp[i][j] = max(dp[i+1][j],dp[i][j-1]);
				}
			}
		}
		
		return dp[0][s.size()-1];
	}
};
