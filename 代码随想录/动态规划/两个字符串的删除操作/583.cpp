#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
//https://leetcode.cn/problems/delete-operation-for-two-strings/

class Solution {
public:
	int minDistance(string word1, string word2) {
		//dp[i][j]表示 以i-1结尾的word1和以j-1结尾的word2，想要达到相等，所需要删除元素的最少次数
		vector<vector<int>> dp(word1.size() + 1,vector<int>(word2.size() + 1));
		
		for(int i = 0;i <= word1.size();i++){
			dp[i][0] = i;
		}
		
		for(int j = 0;j <= word2.size();j++){
			dp[0][j] = j;
		}
		
		for(int i = 1;i <= word1.size();i++){
			for(int j = 1;j <= word2.size();j++){
				if(word1[i - 1] == word2[j - 1])
					dp[i][j] = dp[i - 1][j - 1];
				else
					//删word1[i - 1]，最少操作次数为dp[i - 1][j] + 1
					//删word2[j - 1]，最少操作次数为dp[i][j - 1] + 1
					//同时删word1[i - 1]和word2[j - 1]，操作的最少次数为dp[i - 1][j - 1] + 2
					dp[i][j] = min(min(dp[i - 1][j] + 1,dp[i][j - 1] + 1),dp[i - 1][j - 1] + 2);
			}
		}
		
		return dp[word1.size()][word2.size()];
	}
	
	int minDistance2(string word1, string word2){
		vector<vector<int>> dp(word1.size()+1,vector<int>(word2.size()+1,0));
		
		//求最长子序列长度
		for(int i = 1;i <= word1.size();i++){
			for(int j = 1;j <= word2.size();j++){
				if(word1[i-1] == word2[j-1])
					dp[i][j] = dp[i-1][j-1] + 1;
				else
					dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
			}
		}
		
		int damn = word1.size() + word2.size() - dp[word1.size()][word2.size()] * 2;
		return damn;
	}
};
