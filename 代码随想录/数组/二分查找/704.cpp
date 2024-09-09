#include <stdlib.h>
#include <iostream>
#include <vector>
using namespace std;

//https://leetcode.cn/problems/binary-search

//int search(vector<int>& nums, int target) {
//	int left = 0; //左区间
//	int right = nums.size()-1; //右区间
//	
//	//左闭右闭情况
//	while(left <= right){
//		int mid = left + (right - left)/2; //中间标杆
//		
//		if(nums[mid] < target){
//			left = mid + 1;
//		} else if(nums[mid] > target){
//			right = mid - 1; //mid已经不在范围，并且在合法区间中，因此mid-1顺位
//		} else {
//			return mid;
//		}
//	}
//	
//	return -1; //没有找到，返回-1
//}

int search(vector<int>& nums, int target){
	//左闭右开
	int left = 0;
	int right = nums.size();
	while(left < right){
		int mid = left + (right - left)/2;
		
		if(nums[mid] < target){
			left = mid + 1;
		} else if(nums[mid] > target){
			right = mid;
		} else{
			return mid;
		}
	}
	return -1;
}




int main(){
	vector<int> nums={-1,0,3,5,9,12};
	int target=0;
	int loc = search(nums,target);
	cout<<loc<<endl;
	return 0;
}
