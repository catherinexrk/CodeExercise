#include  <stdlib.h>
#include <vector>
#include <iostream>

using namespace std;
//https://leetcode.cn/problems/remove-element/

class Solution {
public:
	int removeElement(vector<int>& nums, int val) {
		int read = 0,write = 0;
		int count = 0;
		int lNums = nums.size();
		while(write < nums.size()){
			if(nums[write] != val){
				nums[read++] = nums[write++];
				count++;
			} else{
				write++;//跳过当前数值
				
			}
		}
		nums.resize(count);
		return count;
	}
};
