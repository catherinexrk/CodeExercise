#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
//https://leetcode.cn/problems/palindromic-substrings/

class Solution {
public:
	int countSubstrings(string s) {
		//dp[i][j]表示下标i-1到下标j-1这个区间里面的字符串是否为回文串
		vector<vector<bool>> dp(s.size(),vector<bool>(s.size(),false));
		
		int result = 0;
		
		//从下往上，从左往右
		for(int i = s.size() - 1;i >= 0;i--){
			for(int j = i;j < s.size();j++){
				if(s[i] == s[j]){
					if(j - i <= 1){
						//aa或者a的情况
						result++;
						dp[i][j] = true;
					} else{
						if(dp[i + 1][j - 1]){
							result++;
							dp[i][j] = true;
						}
					}
				}
			}
		}
		
		return result;
	}
	
	int countSubstrings1(string s){
		vector<vector<bool>> dp(s.size(),vector<bool>(s.size(),false));
	
		int result = 0;
		
		for(int i = s.size() - 1;i >= 0;i--){
			for(int j = i;j < s.size();j++){
				if(s[i] == s[j]){
					if(j - i <= 1){
						result++;
						dp[i][j] = true;
						
					} else{
						if(dp[i+1][j-1]){
							result++;
							dp[i][j] = true;
						}
					}
				}
			}
		}
		
		return result;
	}
};
