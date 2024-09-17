#include <iostream>
#include <stdlib.h>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <math.h>
#include <algorithm>

using namespace std;
//https://leetcode.cn/problems/4sum/

class Solution {
public:
	vector<vector<int>> fourSum(vector<int>& nums, int target) {
		vector<vector<int>> result;
		sort(nums.begin(),nums.end());
		for(int i = 0;i < nums.size();i++){
			//针对排序好的数组，先是判断第一个元素是否满足条件
//			if(nums[i] > target){
//				break;
//			}
			if(i > 0 and nums[i] == nums[i - 1]){
				continue;
			}
			
			for(int j = i + 1;j < nums.size();j++){
				if(j > i + 1 and nums[j] == nums[j - 1]){
					continue;//跳过第二个数字的重复
				}
				
				int left = j + 1;
				int right = nums.size() - 1;
				while(right > left){
					long long damn = static_cast<long long>(nums[i]) + nums[j] + nums[left] + nums[right];
					
					if(damn > target) right--;
					else if(damn < target) left++;
					else{
						result.push_back({nums[i],nums[j],nums[left],nums[right]});
						
						while(right > left and nums[left] == nums[left + 1]) left++;
						while(right > left and nums[right] == nums[right - 1]) right--;
						
						left++;
						right--;
					}
				}
			}
		}
		return result;
	}
};
