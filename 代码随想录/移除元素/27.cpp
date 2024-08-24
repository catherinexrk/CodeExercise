#include <stdlib.h>
#include <iostream>
#include <vector>

using namespace std;

//https://leetcode.cn/problems/remove-element/description/

class Solution{
public:
	int removeElement(vector<int>& nums, int val) {
		int write = 0;//写指针
		for(int read = 0;read < nums.size();read++){
			if(nums[read] != val){
				nums[write] = nums[read];
				write++;
			}
		}
		return write;
	}
};
