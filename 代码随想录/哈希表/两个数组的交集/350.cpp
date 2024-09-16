#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <vector>
#include <set>

using namespace std;
//https://leetcode.cn/problems/intersection-of-two-arrays-ii/

class Solution {
public:
	vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
		multiset<int> result;
		multiset<int> arr;
		for(int temp : nums1){
			arr.insert(temp);
		}
		
		for(int temp : nums2){
			auto it = arr.find(temp);
			if(it != arr.end()){
				result.insert(temp);
				arr.erase(it);//删除已找到的元素，这样可以保证最终在元素交集里面的元素出现次数最少
			}
		}
		
		return vector<int>(result.begin(),result.end());
	}
};
