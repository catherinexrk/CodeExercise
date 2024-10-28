#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
	int findContentChildren(vector<int>& g, vector<int>& s) {
		//g是胃口 s是饼干尺寸
		sort(g.begin(),g.end());//升序
		sort(s.begin(),s.end());
		
		int count = 0;
		
		for(int i = g.size() - 1,j = s.size() - 1; i >= 0;i--){
			if(j >=0 && s[j] >= g[i]){
				count++;
				j--;
			}
		}
		
		return count;
	}
};

class Solution2 {
public:
	int maxSubArray1(vector<int>& nums) {
		int result = INT_MIN;//总和
		int count = 0;//当前和
		
		for(int i = 0;i < nums.size();i++){
			count += nums[i];
			
			if(count > result)
				result = count;
			if(count <= 0)
				count = 0;
		}
		
		return result;
	}
	
	int maxSubArray(vector<int>& nums){
		int cur = nums[0];
		int result = nums[0];
		
		for(int i = 1;i < nums.size();i++){
			cur = max(nums[i],cur + nums[i]);
			
			if(result < cur){
				result = cur;
			}
		}
		
		return result;
	}
};

class Solution3 {
public:
	int maxProfit(vector<int>& prices) {
		//最短间隔就是第一天买，第二天卖
		int result = 0;
		for(int i  = 1;i < prices.size();i++){
			int profit = prices[i] - prices[i - 1];
			if(profit > 0)
				result += profit;
		}
		
		return result;
	}
};

class Solution4{
public:
	bool canJump1(vector<int>& nums) {
		int cover = 0;
		if(nums.size() == 1)
			return true;
		
		for(int i = 0;i <= cover;i++){
			cover = max(i + nums[i],cover);
			
			if(cover >= nums.size() - 1)
				return true;
		}
		
		return false;
	}
	
	//只用查看覆盖范围即可
	bool canJump(vector<int>& nums){
		int cover = 0;//覆盖范围
		if(nums.size() == 1)
			return true;
		
		for(int i = 0;i <= cover;i++){
			//更新cover可以覆盖的范围
			cover = max(cover,i + nums[i]);
			
			//覆盖范围可以覆盖整个nums数组
			if(cover >= nums.size() - 1)
				return true;
		}
		
		return false;
	}
	
	bool canJump2(vector<int>& nums){
		if(nums.size() == 1)
			return true;
		
		int cover = 0;
		
		for(int i = 0;i <= cover;i++){
			cover = max(i + nums[i],cover);
			
			if(cover >= nums.size() - 1)
				return true;
		}
		
		return false;
	}
};


class Solution5{
public:
//	int jump(vector<int>& nums) {
//		int cover = 0;
//		
//		if(nums.size() == 1)
//			return 1;
//		for(int i = 0;i <= cover;i++){
//			cover = max(i + nums[i],cover);
//			
//			if(cover >= nums.size() - 1)
//				return 1;
//		}
//		
//		return 0;
//	}
	
	int jump(vector<int>& nums){
		
	}
};
