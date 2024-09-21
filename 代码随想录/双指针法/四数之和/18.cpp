#include <string.h>
#include <iostream>
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <sstream>
#include <unordered_map>
#include <unordered_set>

using namespace std;
//https://leetcode.cn/problems/4sum/
class Solution {
public:
	vector<vector<int>> fourSum(vector<int>& nums, int target) {
		vector<vector<int>> result;
		sort(nums.begin(),nums.end());
		for(int i = 0;i < nums.size();i++){
//			if(nums[i] > target){
//				break;
//			}
			if(i > 0 and nums[i] == nums[i - 1]){
				continue;//重复元组，跳出循环
			}
			
			for(int j = i + 1;j <nums.size();j++){
				if(j > i + 1 and nums[j] == nums[j - 1]){
					continue;
				}
				int left = j + 1;
				int right = nums.size() - 1;
				
				while(left < right){
					long long temp = nums[i] + nums[j] + nums[left] + nums[right];
					if(temp < target) left++;
					else if(temp > target) right--;
					else{
						result.push_back({nums[i],nums[j],nums[left],nums[right]});
						while(left < right and nums[left] == nums[left + 1]){
							left++;
						}
						while(left < right and nums[right] == nums[right - 1]){
							right--;
						}
						left++;
						right--;
					}
				}
				
			}
			
		}
		return result;
	}
};
