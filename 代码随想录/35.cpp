#include <stdlib.h>
#include <iostream>
#include <vector>

using namespace std;

//https://leetcode.cn/problems/search-insert-position/

int searchInsert(vector<int>& nums, int target) {
	//左闭右闭
	int left = 0;
	int right = nums.size() - 1;
	while(left <= right){
		int mid = left + (right - left)/2;
		if(nums[mid] < target){
			left = mid + 1;
		} else if (nums[mid] > target ){
			right = mid - 1;
		} else {
			return mid;
		}
	}
	//退出循环 此时target不在数组中
	
	//接着对nums进行遍历，挨个找位置？
	//数字比最小值还小
	if(target < nums[0]){
		return 0;
	} 
	//比最大值还大
	if(target > nums[nums.size()-1]){
		return nums.size();
	}
	//在数组中间 已经不包含在数组中的情况了
	int loc = 0;//初始位置
	for(int temp : nums){
		if(target < temp){
			break; //跳出循环
		}
		loc++;
	}
	return loc;
}

int main(){
	vector<int> nums;
	int target;
	int temp = searchInsert(nums,target);
	return 0;
}
