#include <stdlib.h>
#include <vector>
#include <iostream>
#include <cstdint>
using namespace std;

//https://leetcode.cn/problems/minimum-size-subarray-sum/description/

class Solution {
public:
	//暴力
//	int minSubArrayLen(int target, vector<int>& nums) {
//		int result = INT32_MAX;//暂存result，表示返回序列的最小长度
//		int sum = 0;//子序列之和
//		int length = 0;//子序列长度
//		for(int i = 0;i < nums.size();i++){
//			sum = 0;//每一轮都清空sum进行新的计算
//			for(int j = i;j < nums.size();j++){
//				sum += nums[j];
//				if(sum >= target){
//					length = j - i + 1;//表示子序列的长度 
//					result = result < length ? result : length;
//					break;//结束一层循环，接着去找别的序列
//				}
//			}
//		}
//		return result == INT32_MAX ? 0 : result;
//		
//	}
	
	int minSubArrayLen(int target, vector<int>& nums) {
		//滑动窗口
		int result = INT32_MAX;//最终存储最小序列长度
		int sum = 0;//表示子序列之和
		int subLength = 0;//子序列长度之和
		int i = 0;//区间的初始位置
		for(int j = 0;j < nums.size();j++){
			//j表示最终位置，因为考虑使用都滑动窗口去解决，因此只需要保证移动最终位置去找到满足区间，找到区间之后再去移动初始位置不断逼近即可
			sum += nums[j];//累加求和
			while(sum >= target){
				subLength = j - i + 1;
				result = result < subLength ? result : subLength;//更新最短子序列长度
				sum -= nums[i++]; //此时确定好区间之后，开始移动初始位置，以此去求最短子序列
			}
		}
		return result == INT32_MAX ? 0 : result;
	}
};
