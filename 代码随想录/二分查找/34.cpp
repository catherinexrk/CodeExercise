#include <stdlib.h>
#include <iostream>
#include <vector>

using namespace std;
//https://leetcode.cn/problems/find-first-and-last-position-of-element-in-sorted-array/

//vector<int> searchRange(vector<int>& nums, int target) {
//	vector<int> returnArray = {-1,-1}; //表示返回的数组 初始值为-1 -1标识没有匹配target
//	//nums为空 
//	if(nums.size() == 0){
//		return returnArray;
//	}
//	
//	//nums非空
//	//暴力
//	int loc = 0;
//	int flag = 0;
//	for(int temp : nums){
//		if(temp == target && flag == 0){  //第一次匹配成功
//			returnArray[0] = loc;
//			flag++; //flag=1
//		} else if(temp == target && flag == 1){
//			returnArray[1] = loc;
//			flag++;
//		}
//		loc++;
//	}
//	//结束判断
//	if(flag == 1){
//		returnArray[1] = returnArray[0];//表示nums只有一个匹配target
//	}
//	return returnArray;
//}

//暴力
vector<int> searchRange1(vector<int>& nums, int target){
	vector<int> returnArray = {-1,-1}; //初始化返回数组
	//nums为空
	if(nums.size() == 0){
		return returnArray;
	}
	
	//nums不为空
	//暴力
	for(int loc = 0;loc < nums.size();loc++){
		if(nums[loc] == target && returnArray[0] == -1){
			returnArray[0] = loc;//第一次匹配成功
		} else if(nums[loc] == target && returnArray[0] != -1){
			returnArray[1] = loc;
		}
	}
	
	//nums容量为1
	if(returnArray[1] == -1){
		returnArray[1] = returnArray[0];
	}
	
	return returnArray;
}

//二分法
/*
	1.target不在nums的范围中，小于左边界、大于有边界
	2.target在nums的范围中，且nums中有target数值
	3.target在nums的范围中，但是nums中无匹配target数值
*/


class Solution{
public:
	vector<int> searchRange(vector<int>& nums, int target){
		int left = firstBorder(nums,target);
		int right = lastBorder(nums,target);
		return vector<int>{left,right};
		
	}

private:
	//寻找左边第一个边界
	/*
		在原先二分基础上，考虑到nums中存在连续两个数字相连，因此在返回前后边界的时候进行讨论
	*/
	int firstBorder(vector<int>& nums,int target){
		int left = 0,right = nums.size()-1;
		while(left <= right){
			int mid = left + (right - left)/2;
			if(nums[mid] == target){
//				return mid;//直接找到
				//讨论是否连续存在情况
				if(mid == 0 || nums[mid] != nums[mid-1]){
					return mid;//匹配的元素位置在nums数组的头，或者其就是第一个匹配成功到的元素
				} else{
					//二分缩小范围
					right = mid - 1;
				}
			} else if(nums[mid] < target){
				left = mid + 1;
			} else{ //nums[mid] > target
				right = mid - 1;
			}
		}
		return -1;
	}
	
	int lastBorder(vector<int>& nums,int target){
		int left = 0,right = nums.size()-1;
		while(left <= right){
			int mid = left + (right - left)/2;
			if(nums[mid] == target){
//				return mid;//直接找到
				//讨论是否连续存在情况
				if(mid == nums.size() - 1 || nums[mid] != nums[mid + 1]){
					return mid;//匹配的元素位置在nums数组的尾，或者其就是最后一个匹配成功到的元素
				} else{
					//二分缩小范围
					left = mid + 1;
				}
			} else if(nums[mid] < target){
				left = mid + 1;
			} else{ //nums[mid] > target
				right = mid - 1;
			}
		}
		return -1;
	}
};







int main(){
	vector<int> nums = {5,7,7,8,8};
	int target = 8;
	Solution solution;
	vector<int> temp = solution.searchRange(nums,target);
	cout<<temp[0]<<" "<<temp[1]<<endl;
}

