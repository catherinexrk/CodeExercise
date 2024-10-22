#include <stdlib.h>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
//https://leetcode.cn/problems/jump-game/

class Solution {
public:
	bool canJump(vector<int>& nums) {
		/**
		 * 跳跃范围究竟可不可以覆盖到重点
		 */
		
		/**
		 * i每次移动都智能在cover范围内移动，每移动一个元素，cover得到该元素数值的不充，让i继续移动下去
		 * 而cover每次只能取max
		 * 如果cover>=终点下标，此时直接return true即可
		 */
		int cover = 0;
		if(nums.size() == 1) 
			return true;
		
		for(int i = 0;i <= cover;i++){
			cover = max(i + nums[i],cover);
			if(cover >= nums.size() - 1)//此时说明cover可以覆盖到数组最后一位的下标
				return true;
		}
		return false;
	}
};

class Solution2 {
public:
	bool canJump(vector<int>& nums) {
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
};
