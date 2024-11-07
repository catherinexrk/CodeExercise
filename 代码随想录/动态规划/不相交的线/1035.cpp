#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
//https://leetcode.cn/problems/uncrossed-lines/

class Solution {
public:
	int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
		vector<vector<int>> dp(nums1.size()+1,vector<int>(nums2.size()+1,0));
		//dp[i][j]表示num1下标0到i-1和nums2下标0到j-1的线条总数
		
		int result = 0;
		
		for(int i = 1;i <= nums1.size();i++){
			for(int j = 1;j <= nums2.size();j++){
				if(nums1[i - 1] == nums2[j - 1]){
					dp[i][j] = dp[i - 1][j - 1] + 1;
				} else{
					dp[i][j] = max(dp[i - 1][j],dp[i][j - 1]);
				}
				
				result = max(dp[i][j],result);
			}
		}
		
		return result;
	}
};
