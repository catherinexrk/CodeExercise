#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <vector>

using namespace std;
//https://leetcode.cn/problems/intersection-of-two-arrays/

class Solution {
public:
	vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
		unordered_set<int> damn;//保存nums1中的元素
		unordered_set<int> result;//存储最终的相交且不重复的元素
		
		for(int i = 0;i < nums1.size();i++){
			damn.insert(nums1[i]);//插入元素，同时去除重复元素
		}
		
		for(int i = 0;i < nums2.size();i++){
			if(damn.find(nums2[i]) != damn.end()){
				result.insert(nums2[i]);
			}
		}
		
	
		return vector<int>(result.begin(),result.end());
	}
};

	//时间复杂度o(m+n)

