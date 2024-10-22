#include <stdlib.h>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
//https://leetcode.cn/problems/jump-game-ii/

class Solution {
public:
	int jump(vector<int>& nums) {
		if(nums.size() == 1) return 0;
	
		int curDistance = 0;//当前覆盖最远距离下标
		int ans = 0;//记录走的最大步数
		int nextDistance = 0;//记录下一步覆盖最远距离的下标
		
		for(int i = 0;i < nums.size();i++){
			nextDistance = max(nums[i] + i,nextDistance);//更新下一步覆盖最远距离
			if(i == curDistance){ //遇到当前覆盖最远距离下标
				ans++;//需要走下一步
				curDistance = nextDistance;//更新当前覆盖最远距离下标
				if(nextDistance >= nums.size() - 1)
					break;//当前覆盖最远距离达到了集合的重点位置
			}
		}
		
		return ans;
	}
};

class Solution2 {
public:
	int jump(vector<int>& nums) {
		if(nums.size() == 1) return 0;
		
		int cur = 0;
		int next = 0;
		int ans = 0;//步数
		for(int i = 0;i <= cur;i++){
			next = max(i + nums[i],next);
			
			if(i == cur){
				cur = next;
				ans++;
				if(cur >= nums.size() - 1)
					break;
			}
		}
		
		return ans;
	}
};
