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
//https://leetcode.cn/problems/3sum/

class Solution {
public:
	//双指针法
	vector<vector<int>> threeSum(vector<int>& nums) {
		vector<vector<int>> result;
		sort(nums.begin(),nums.end());
		//找出a+b+c
		//a=nums[i],b=nums[j],c=-(a+b)
		for(int i = 0;i < nums.size();i++){
			//排序好后的数组
			//检查排序后的第一个元素，如果元素>0，直接排除
			if(nums[i] > 0){
				break;
			}
			if(i > 0 && nums[i] == nums[i - 1]){
				continue;//此处对第一个元素a进行去重操作
			}
			
			int left = i + 1;
			int right = nums.size() - 1;
			while(right > left){
				if(nums[i] + nums[left] + nums[right] > 0){
					right--;
				} else if(nums[i] + nums[left] + nums[right] < 0){
					left++;
				} else{
					result.push_back(vector<int>{nums[i],nums[left],nums[right]});
					
					//去重逻辑应该放到在找到一个三元组之后，对a和b进行去重
					while(right > left && nums[right] == nums[right - 1]){
						right--;
					}
					while(right > left && nums[left] == nums[left + 1]){
						left++;
					}
					
					//找到答案后，对right和left进行调整
					right--;
					left++;
				}
			}
		}
		return result;
	}
};

class Solution2 {
public:
	//双指针法
	vector<vector<int>> threeSum(vector<int>& nums){
		vector<vector<int>> result;
		sort(nums.begin(),nums.end());
		for(int i = 0;i < nums.size();i++){
			//排序好的数组，如果第一个元素都大于0，直接break
			if(nums[i] > 0){
				break;
			}
			
			//对第一个元素nums[i]进行去重操作
			if(i > 0 and nums[i] == nums[i - 1]){
				continue;//跳过后续一切操作，避免出现重复的三元组
			}
			
			int left = i + 1;
			int right = nums.size() - 1;
			while(right > left){
				if(nums[i] + nums[left] + nums[right] > 0) right--;
				else if(nums[i] + nums[left] + nums[right] < 0) left--;
				else{
					result.push_back({nums[i],nums[left],nums[right]});
					
					while(right > left and nums[left] == nums[left + 1]) left++;
					while(right > left and nums[right] == nums[right - 1]) right--;
					
					left++;
					right--;
				}
				
			}
		}
		return result;
	}
};
