#include <iostream>
#include <stdlib.h>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <math.h>

using namespace std;
//https://leetcode.cn/problems/4sum-ii/description/

class Solution1 {
public:
	int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
		unordered_map<int,int> sum1;//存储nums1和nums2的之和
		unordered_map<int,int> sum2;//存储nums3和nums4的之和
		
		int count = 0;//记录符合条件的此时，初始化为0
		for(int i = 0;i < nums1.size();i++){
			for(int j = 0;j < nums2.size();j++){
				int sum = nums1[i] + nums2[j];
				sum1[sum]++;
			}
		}
		
		for(int i = 0;i < nums3.size();i++){
			for(int j = 0;j < nums4.size();j++){
				int sum = nums3[i] + nums4[j];
				sum2[- sum]++;
			}
		}
		for(auto pair : sum1){
//			int damn = -(it->first);
//			for(auto pair : sum1){
//				if(pair.first == damn){
//					count += pair.second * sum2[pair.first];
//				}
//			}
			int complement = -pair.first; // 目标和是 -pair.first
			if (sum2.count(complement)) {
				count += pair.second * sum2[complement];
			}
		}
		return count;	
	}
};

class Solution {
public:
	int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
		unordered_map<int,int> sum;
		for(int a : nums1){
			for(int b : nums2){
				sum[a + b]++;
			}
		}
		
		int count = 0;
		for(auto c : nums3){
			for(auto d : nums4){
				if(sum.find(0 - (c + d)) != sum.end()){
					count += sum[0 - (c + d)];
				}
			}
		}
		return count;
		//时间复杂度o(n2))
	}
};
