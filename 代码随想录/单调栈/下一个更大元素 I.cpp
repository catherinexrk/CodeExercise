#include <stdlib.h>
#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
#include <vector>

using namespace std;
//https://leetcode.cn/problems/next-greater-element-i/

class Solution {
public:
	vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
		//存储最终返回的nums2中的下标
		vector<int> result(nums1.size(),-1);
		
		stack<int> st;
		unordered_map<int,int> map;//key数值，value元素下标
		for(int i = 0;i < nums1.size();i++){
			map[nums1[i]] = i;
		}
		
		st.push(0);
		for(int i = 1;i <nums2.size();i++){
			if(nums2[i] <= nums2[st.top()]){
				st.push(i);
			} else {
				while(!st.empty() && nums2[i] > nums2[st.top()]){
					if(map.count(nums2[st.top()]) > 0){ //查看map中是否存在当前元素
						int index = map[nums2[st.top()]];//根据map找到nums2[st.top]在nums1中的下标
						result[index] = nums2[i];
					}
					st.pop();
				}
				st.push(i);
			}
		}
		return result;
	}
	
	vector<int> damn(vector<int>& nums1, vector<int>& nums2){
		vector<int> result(nums1.size(),-1);
		stack<int> st;
		unordered_map<int,int> map;
		for(int i = 0;i < nums1.size();i++){
			map[nums1[i]] = i;
		}
		
		st.push(0);
		for(int i = 1;i < nums2.size();i++){
			if(nums2[i] <= nums2[st.top()]){
				st.push(i);
			} else{
				while(!st.empty() && nums2[i] > nums2[st.top()]){
					//查找nums1中是否有对应的nums2[st.top]
					if(map.find(nums2[st.top()]) != map.end()){
						//找到了对应的nums2[st.top]元素，此时nums2[i]便是其右边第一个大于的元素
						int index = map[nums2[st.top()]];
						result[index] = nums2[i];
					}
					st.pop();
				}
				st.push(i);
			}
		}
		
		return result;
	}
	
	vector<int> bf(vector<int>& nums1, vector<int>& nums2){
		vector<int> result(nums1.size(),-1);
		
		for(int i = 0;i < nums1.size();i++){
			for(int j = 0;j < nums2.size();j++){
				if(nums1[i] == nums2[j]){
					for(int k = j + 1;k < nums2.size();k++){
						if(nums2[k] > nums1[i]){
							result[i] = nums2[k];
							break;
						}
					}
				}
			}
		}
		
		return result;
	}
};
