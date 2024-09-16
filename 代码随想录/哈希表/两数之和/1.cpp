#include <iostream>
#include <stdlib.h>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>

using namespace std;
//https://leetcode.cn/problems/two-sum


class Solution1 {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		//使用set
		unordered_set<int> result;
		for(int i = 0;i < nums.size() - 1;i++){
			for(int j = i + 1;j < nums.size();j++){
				if(nums[i] + nums[j] == target){
					result.insert(i);
					result.insert(j);
				}
			}
		}
		
		return vector<int>(result.begin(),result.end());
	}
};

class Solution2{
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		unordered_map<int,int> result;
		for(int i = 0;i < nums.size();i++){
			result.insert({nums[i],i});
		}
		
		for(int i = 0;i < nums.size();i++){
			auto it = result.find(target - nums[i]);
			if(it != result.end()){
				int j = result[target - nums[i]];
				return {i,j};
			}
		}
	}
};

class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		unordered_map<int,int> result;
		for(int i = 0;i < nums.size();i++){
			int complement = target - nums[i];
			auto it = result.find(complement);
			if(it != result.end()){
				return {i,result[complement]};
			} else{
				result[nums[i]] = i;
			}
		}
		return {};
	}
};

//时间复杂度o(n) n是nums的长度

