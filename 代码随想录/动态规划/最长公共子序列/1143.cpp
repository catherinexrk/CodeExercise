#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
//https://leetcode.cn/problems/longest-common-subsequence/

class Solution {
public:
	int longestCommonSubsequence(string text1, string text2) {
		/**
		 * 说下思路吧
		 * 我想到的是逐字遍历text1和text2
		 * 然后如果相等的话，记录当前dp[i][j]的长度
		 * dp[i][j]表示当前text1 0到i-1，text2 0搭配j-1 的字符串的公共子序列长度为dp[i][j]
		 */
		
		vector<vector<int>> dp(text1.size()+1,vector<int>(text2.size()+1,0));
		
		int result = 0;
		
		for(int i = 1;i <= text1.size();i++){
			for(int j = 1;j <= text2.size();j++){
				//当字符匹配的时候我们应当将这个相等的字符串加入其中
				if(text1[i - 1] == text2[j - 1]){
					dp[i][j] = dp[i - 1][j - 1] + 1;
				} else{
					//当前两个字符不相等的时候，要么删除text1中的当前字符，看看dp[i-1][j]中的最长公共子序列
					//要么删除text2中的字符，看看dp[i][j-1]中的最长公共子序列
					dp[i][j] = max(dp[i - 1][j],dp[i][j - 1]);
				}
				
				result = dp[i][j] > result ? dp[i][j] : result;
			}
		}
		
		return result;
	}
};
