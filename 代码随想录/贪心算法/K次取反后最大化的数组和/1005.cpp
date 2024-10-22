#include <stdlib.h>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
//https://leetcode.cn/problems/maximize-sum-of-array-after-k-negations/

class Solution {
private:
	static bool cmp(int a,int b){
		return abs(a) > abs(b);
	}
	
public:
	int largestSumAfterKNegations(vector<int>& nums, int k) {
		/**
		 * 首先是找出所有的负数，全部转化为0
		 * 转化完成之后如果k还是大于0，则将找出最小值进行-nums操作
		 * 
		 */
		
		sort(nums.begin(),nums.end(),cmp);
		for(int i = 0;i < nums.size();i++){
			//找出负数并且此时k>0
			if(nums[i] < 0 && k >0){
				nums[i] *= -1;
				k--;
			}
		}
		//如果k是奇数的时候，对最后一个数字进行反复取反
		if(k % 2 == 1){
			//对最小的正数进行取反
			nums[nums.size() - 1] *= -1;
		}
		
		int result = 0;
		for(int temp : nums)
			result += temp;
		
		return result;
	}
};

class Solution2 {
	
//private:
//	static bool cmp(int a,int b){
//		return abs(a) > abs(b);
//	}
public:
	static bool cmp(int a,int b){
		return abs(a) > abs(b);
	}
	
	int largestSumAfterKNegations(vector<int>& nums, int k) {
		
		sort(nums.begin(),nums.end(),cmp);
		
		for(int i = 0;i < nums.size();i++){
			if(nums[i] < 0 && k >0){
				nums[i] *= -1;
				k--;
			}
		}
		
		if(k % 2 ==1)
			nums[nums.size() - 1] *= -1;
		
		int result = 0;
		for(int temp : nums)
			result += temp;
		return result;	
	}
};
