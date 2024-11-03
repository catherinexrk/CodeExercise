#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
//https://leetcode.cn/problems/combination-sum-iv/

class Solution {
public:
	int combinationSum4(vector<int>& nums, int target) {
		vector<uint64_t> dp(target + 1,0);
		
		dp[0] = 1;
		
		//求得是组合数 1,1,2  2,1,1是同一个组合
//		for(int i = 0;i < nums.size();i++){
//			for(int j = nums[i];j <= target;j++){
//				dp[j] += dp[j - 1];
//			}
//		}
		
		//求排列不同的组合 1,1,2  1,2,1是不同排列
		
		//遍历背包
		for(int j = 1;j <= target;j++){
			//遍历物品
			for(int i = 0;i < nums.size();i++){
				if(j - nums[i] >= 0 ){ //只有当j>=nums[i] 才可以继续塞元素
					dp[j] += dp[j - nums[i]];
				}
			}
		}
		
		return dp[target];
	}
};
