#include <stdlib.h>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>


using namespace std;

class Solution{
public:
	/**
	 * @brief 704
	 * 时间复杂度 o(logn)
	 * 空间复杂度 o(1)
	 * @param nums 
	 * @param target 
	 * 
	 * @return 
	 */
	int search(vector<int>& nums, int target) {
		int left = 0,right = nums.size() - 1;
		while(left <= right){
			int mid = (right + (right - left)) / 2;
			if(nums[mid] == target) return mid;
			else if(nums[mid] < target) left = mid + 1;
			else right = mid - 1;
		}
		return -1;
	}
	
	/**
	 * @brief 2529
	 * 两次二分查找
	 * 负数的起始位置为-1，表示数组没有负数
	 * 正数的起始位置为nums.size，表示没有正数
	 * @param nums 
	 * 
	 * @return 
	 */
	int maximumCount(vector<int>& nums) {
		//两次二分法，分别寻找到正数的最小数值位置、负数的最大数值位置
		int left = 0,right = nums.size() - 1;
		int negativeIndex = -1;
		int positiveIndex = nums.size() ;
		
		//找正整数初试位置
		while(left <= right){
			int mid = left + (right - left) / 2;
			if(nums[mid] > 0) {
				positiveIndex = mid;
				right = mid - 1;
			}
			
			else
				left = mid + 1;
		}
		
		left = 0,right = nums.size() - 1;
		//负数的最大值起始位置
		while(left <= right){
			int mid = left + (right - left) / 2;
			if(nums[mid] < 0) {
				negativeIndex = mid;
				left = mid + 1;
			}
			else
				right = mid - 1;
		}
		
		int sumNegative = negativeIndex + 1;
		int sumPositive = nums.size() - positiveIndex;
		return (sumNegative > sumPositive) ? sumNegative : sumPositive;
	}
	
	
	/**
	 * @brief 1351
	 * 
	 * @param grid 
	 * 
	 * @return 
	 */
	int returnSum(const vector<int>& nums) {
		// 求数组中的负数的数目
		int negativeIndex = -1;  // 初始化为 -1，表示没有找到负数
		int left = 0, right = nums.size() - 1;
		
		// 二分查找负数的位置
		while (left <= right) {
			int mid = left + (right - left) / 2;
			if (nums[mid] < 0) {
				negativeIndex = mid; // 记录负数的位置
				left = mid + 1;      // 向右查找继续
			} else {
				right = mid - 1;     // 向左查找
			}
		}
		
		// 负数数量
		return (negativeIndex == -1) ? 0 : (nums.size() - negativeIndex); // 返回负数数量
	}
	
	
	
	int countNegatives(vector<vector<int>>& grid) {
		int sum = 0;
		for(auto temp : grid){
			sum += returnSum(temp);
		}
		return sum;
	}
	
	/**
	 * 35
	 */
	int searchInsert(vector<int>& nums, int target) {
		int left = 0,right = nums.size() - 1;
		while(left <= right){
			int mid = left + (right - left) / 2;
			if(nums[mid] == target){
				return mid;
			} else if(nums[mid] < target){
				left = mid + 1;
			} else{
				right = mid - 1;
			}
		}
		return left;
	}
	
	/**
	 * 278
	 */
	int firstBadVersion(int n) {
		
	}
	
};
