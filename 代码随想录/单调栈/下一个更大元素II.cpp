#include <stdlib.h>
#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
#include <vector>

using namespace std;
//https://leetcode.cn/problems/next-greater-element-ii/

class Solution {
public:
	vector<int> nextGreaterElements(vector<int>& nums) {
		//将两个nums拼接
		vector<int> nums1(nums.begin(),nums.end());
		nums.insert(nums.end(),nums1.begin(),nums1.end());
		
		//
		vector<int> result(nums.size(),-1);
		if(nums.size() == 0)
			return result;
		
		stack<int> st;
		st.push(0);
		
		for(int i = 1;i < nums.size();i++){
			if(nums[i] <= nums[st.top()]){
				st.push(i);
			} else {
				while(!st.empty() && nums[i] > nums[st.top()]){
					result[st.top()] = nums[i];
					st.pop();
				}
				st.push(i);
			}
		}
		
		//将result数组resize到正常大小
		result.resize(nums.size() / 2);
		return result;
	}
	
	vector<int> damn(vector<int>& nums){
		//拼接两个nums
		vector<int> nums1(nums.begin(),nums.end());
		nums.insert(nums.end(),nums1.begin(),nums1.end());
		
		vector<int> result(nums.size(),-1);
		if(nums.size() == 0)
			return result;
		
		stack<int> st;
		st.push(0);
		
		for(int i = 1;i < nums.size();i++){
			if(nums[i] <= nums[st.top()]){
				st.push(i);
			} else {
				while(!st.empty() && nums[i] > nums[st.top()]){
					result[st.top()] = nums[i];
					st.pop();
				}
				st.push(i);
			}
		}
		
		result.resize(nums.size() / 2);
		return result;
	}
	
	vector<int> damn1(vector<int>& nums){
		vector<int> result(nums.size(),-1);
		
		if(nums.size() == 0)
			return result;
		
		stack<int> st;
		st.push(0);
		
		for(int i = 1;i < nums.size() * 2;i++){
			if(nums[i % nums.size()] <= nums[st.top()]){
				st.push(i % nums.size());
			} else{
				while(!st.empty() && nums[i % nums.size()] > nums[st.top()]){
					result[st.top()] = nums[i % nums.size()];
					st.pop();
				}
				st.push(i % nums.size());
			}
		}
		
		return result;
	}
};
