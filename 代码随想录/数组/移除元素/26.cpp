#include <stdlib.h>
#include <iostream>
#include <vector>

using namespace std;
//https://leetcode.cn/problems/remove-duplicates-from-sorted-array/description/

class Solution {
public:
	int removeDuplicates1(vector<int>& nums) {
		//双指针思想 read && wriet
		int write = 0;
		int flag = 0;
		vector<int> tempArr(nums.size());
//		for(int read = nums.size() - 1;read > 0;read--){
//			//考虑read和read的上一位位置的元素是否相同
//			if(nums[read] == nums[read - 1]){
//				
//			}
//		}
		int read;
		for(read = 0;read < nums.size() - 1;read++){
			if(nums[read] != nums[read + 1]){//前后元素不相同
				tempArr[write++] = nums[read];//tempArr成功更新元素，此时read指针不自己提前移动，等待循环第四步进行自然移动
				flag++;
			} else{//前后元素相同
				tempArr[write++] = nums[read++];//tempArr更新完成之后，nums中的read自动跳过下一个重复元素
				flag++;
			}
		}
		if(nums[read] == nums[read - 1]){//比较最后一个元素与前一个元素书否相同
			
		} else{
			tempArr[write] = nums[read];
		}
		//此时tempArr中的元素全部是有序且无重复的存在，flag为所有无重复数字的数量
		tempArr.resize(flag);
		nums.resize(flag);
		int damn = 0;
		for(int temp : tempArr){
			nums[damn++] = temp;
		}
		return flag;
	}
	
	
	int removeDuplicates(vector<int>& nums){
		if(nums.empty()){ //为空直接返回0
			return 0;
		}
		//从第二个元素开始写，因为第一个默认会被保存下来
		int write = 1;
		for(int read = 1;read < nums.size();read++){
			if(nums[read] != nums[read - 1]){//如果当前位置read的元素与前一个元素不等，则写进去
				nums[write++] = nums[read];
			} 
		}
		
		return write;
	}
};
