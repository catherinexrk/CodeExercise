#include <stdlib.h>
#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;
//https://leetcode.cn/problems/squares-of-a-sorted-array/description/

class Solution{
public:
	//使用库函数
//	vector<int> sortedSquares(vector<int>& nums) {
//		for(int damn = 0;damn < nums.size();damn++){
//			nums[damn] = pow(nums[damn],2);
//		}
//		sort(nums.begin(),nums.end());
//		return nums;
//	}
	//使用双指针
	vector<int> sortedSquares(vector<int>& nums) {
		vector<int> result(nums.size());//存储最后结果
		int left = 0,right = nums.size() - 1;
		int loc = right;
		while(left <= right){
			if(nums[left] * nums[left] > nums[right] * nums[right]){
				result[loc--] = nums[left] * nums[left];
				left++;
			} else{
				result[loc--] = nums[right] * nums[right];
				right--;
			}
		}
		return result;
	}
};
