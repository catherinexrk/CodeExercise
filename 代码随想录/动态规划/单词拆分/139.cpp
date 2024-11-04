#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;
//https://leetcode.cn/problems/word-break/

class Solution {
public:
	/**
	 * 检测s能否由wordDict中的字符进行拼接组成
	 */
	bool wordBreak(string s, vector<string>& wordDict) {
		unordered_set<string> wordSet(wordDict.begin(),wordDict.end());
		
		vector<bool> dp(s.size() + 1,false);
		dp[0] = true;
		
		//求得是排列数 字符的排序对最终的结果存在一定的影响 先遍历背包再遍历物品
		//遍历背包
		for(int i = 1;i <= s.size();i++){
			//遍历物品
			for(int j = 0;j < i;j++){
				string word = s.substr(j,i - j);//(起始位置，截取的长度)
				if(wordSet.find(word) != wordSet.end() && dp[j] == true){
					dp[i] = true;
				}
			}
		}
		
		return dp[s.size()];
	}
};

class Solution2 {
public:
	bool wordBreak(string s, vector<string>& wordDict) {
		//将wordDDict中的所有单词存储刀set集合中
		unordered_set<string> wordSet(wordDict.begin(),wordDict.end());
		
		vector<bool> dp(s.size() + 1);
		dp[0] = true;
		
		//遍历背包
		for(int i = 1;i <= s.size();i++){
			//遍历物品
			for(int j = 0;j < i;j++){
				string word = s.substr(j,i - j);
				if(wordSet.find(word) != wordSet.end() && dp[i] == true){
					dp[j] = true;
				}
			}
		}
		
		return dp[s.size()];
	}
};
