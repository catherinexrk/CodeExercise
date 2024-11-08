#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
//https://leetcode.cn/problems/distinct-subsequences/

class Solution {
public:
	int numDistinct(string s, string t) {
		//s里面有多少个t
		//dp[i][j]表示以i-1结尾的s子序列中出现以j-1结尾的t的子序列出现的个数
		vector<vector<uint64_t>> dp(s.size()+1,vector<uint64_t>(t.size()+1));
		
		//t为空串，s中只有一个空串子序列
		for(int i = 0;i < s.size() + 1;i++)
			dp[i][0] = 1;
		
		//s为空串，t中没有空串
		for(int j = 1;j < t.size() + 1;j++)
			dp[0][j] = 0;
		
		for(int i = 1;i <= s.size();i++){
			for(int j = 1;j <= t.size();j++){
				if(s[i - 1] == t[j - 1])
					//
					dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
				else
					//不相等时，模拟在s中删除当前元素，t中不删除
					dp[i][j] = dp[i - 1][j];
			}
		}
		
		return dp[s.size()][t.size()];
	}
	
	
	bool isSubsequence(string s, string t) {
		//s是否为t的子序列
		if(t.size() < s.size())
			return false;
		
		vector<vector<int>> dp(s.size()+1,vector<int>(t.size()+1,0));
		
		int result = 0;
		for(int i = 1;i <= s.size();i++){
			for(int j = 1;j <= t.size();j++){
				if(s[i-1] == t[j-1])
					dp[i][j] = dp[i-1][j-1] + 1;
				else
					dp[i][j] = dp[i][j-1];
				
				result = max(result,dp[i][j]);
			}
		}
		if(result == s.size())
			return true;
		return false;
	}
};
