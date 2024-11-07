#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
//https://leetcode.cn/problems/is-subsequence/

class Solution {
public:
	bool isSubsequence(string s, string t) {
		//判断s是否为t的子序列
		if(t.size() < s.size())
			return false;	
		//dp[i][j] 表示以下标i-1为结尾的字符串s，和以下标j-1为结尾的字符串t，相同子序列的长度为dp[i][j]
		vector<vector<int>> dp(s.size()+1,vector<int>(t.size()+1,0));
		
		int result = 0;
		
		for(int i = 1;i <= s.size();i++){
			for(int j = 1;j <=t.size();j++){
				if(s[i-1] == t[j-1])
					dp[i][j] = dp[i-1][j-1] + 1;
				else
					//只能是删除t的当前字符，我们不可以改变s的长度
					dp[i][j] = dp[i][j-1];
				
				result = max(result,dp[i][j]);
			}
		}
		
		if(result == s.size())
			return true;
		return false;
	}
};
