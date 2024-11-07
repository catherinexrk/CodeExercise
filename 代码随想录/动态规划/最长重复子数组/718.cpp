#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
//https://leetcode.cn/problems/maximum-length-of-repeated-subarray/

class Solution {
public:
	int findLength(vector<int>& nums1, vector<int>& nums2) {
		
		//dp[i][j]表示以下标i-1为结尾的a和以下标j-1的b，最长重复子数数组长度为dp[i][j]
		vector<vector<int>> dp(nums1.size()+1,vector<int>(nums2.size()+1,0));
		
		int result = 0;
		
		for(int i = 1;i <= nums1.size();i++){
			for(int j = 1;j <= nums2.size();j++){
				if(nums1[i - 1] == nums2[j - 1])
					dp[i][j] = dp[i - 1][j - 1] + 1;
				
				result = dp[i][j] > result ? dp[i][j] : result;
			}
		}
		
		
		
		return result;
	}
	
	int func(vector<int>& nums1,vector<int>& nums2){
		//dp[i][j]表示以下标为i-1结尾的nnums1和以下标为j-1结尾的nums2，其最长重复数组长度是dp[i][j]
		vector<vector<int>> dp(nums1.size() + 1,vector<int>(nums2.size() + 1,0));
		int result = 0;
		
		for(int i = 1;i < nums1.size();i++){
			for(int j = 1;j < nums2.size();j++){
				if(nums1[i-1] == nums2[j-1]){
					dp[i][j] = dp[i-1][j-1] + 1;
				}
				
				result = dp[i][j] > result ? dp[i][j] : result;
			}
			
		}
		
		return result;
	}
};
