#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
//https://leetcode.cn/problems/edit-distance/

class Solution {
public:
	int minDistance(string word1, string word2) {
		//将word1转换成word2
		vector<vector<int>> dp(word1.size()+1,vector<int>(word2.size()+1));
		
		for(int i = 0;i <= word1.size();i++){
			dp[i][0] = i;
		}
		
		for(int j = 0;j <= word2.size();j++){
			dp[0][j] = j;//word1子序列为空，为了变成word2子序列，每次循环插入j个元素
		}
		
		for(int i = 1;i <= word1.size();i++){
			for(int j = 1;j <= word2.size();j++){
				if(word1[i - 1] == word2[j - 1]){
					dp[i][j] = dp[i - 1][j - 1];
				} else {
//					//word1删除一个元素 
//					dp[i][j] = dp[i - 1][j] + 1;
//					
//					//word2删除一个元素，相当于word1添加一个元素
//					dp[i][j] = dp[i][j - 1] + 1;
//					
//					//word1修改当前元素，使得word1[i-1] = word2[j-1]，执行一次替换操作即可，即在dp[i-1][j-1]基础上+1
//					dp[i][j] = dp[i - 1][j - 1] + 1;
					
					dp[i][j] = min({dp[i - 1][j] + 1,dp[i][j - 1] + 1,dp[i - 1][j - 1] + 1});
				}
			}
		}
		
		return dp[word1.size()][word2.size()];
	}
};
