#include <stdlib.h>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
//https://leetcode.cn/problems/maximum-subarray/

class Solution {
public:
	
	//暴力解法
	int maxSubArrayBF(vector<int>& nums){
		
		int result = INT_MIN;
		int count = 0;
		for(int i = 0;i < nums.size();i++){
			count = 0;	
			for(int j = i;j < nums.size();j++){
				count += nums[j];
				result = count > result ? count : result;
			}
		}
		return result;
	}
	
	int maxSubArray(vector<int>& nums){
		int result = INT_MIN;
		int count = 0;
		
		for(int i = 0;i < nums.size();i++){
			count += nums[i];
			
			if(count > result) 
				result = count;
			if(count <= 0) 
				count = 0;//重置当前最大子序列和
		}
		return result;
	}
};
