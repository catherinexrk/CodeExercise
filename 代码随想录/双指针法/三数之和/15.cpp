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
//https://leetcode.cn/problems/3sum/

class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		vector<vector<int>> result;
		//先是排序一下数组
		sort(nums.begin(),nums.end());
		//此时的链表顺序是有序的
		for(int i = 0;i < nums.size();i++){
			if(nums[i] > 0){
				break;
			}
			
			//去除重复的元组
			if(i > 0 and nums[i] == nums[i - 1]){
				continue;
			}
			int left = i + 1;
			int right = nums.size() - 1;
			while(left < right){
				if(nums[i] + nums[left] + nums[right] > 0){
					right--;
				} else if(nums[i] + nums[left] + nums[right] < 0){
					left++;
				}else{
					result.push_back({nums[i],nums[left],nums[right]});
					
					//此时再对left和right进行去重判断
					while(right > left and nums[right] ==nums[right - 1]){
						right--;
					}
					while(right > left and nums[left] == nums[left + 1]){
						left++;
						
					}
					//找到答案后，移动指针
					right--;
					left++;
				}
			}
		}
		return result;
	}
};
