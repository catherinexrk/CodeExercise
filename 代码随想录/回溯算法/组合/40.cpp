#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;
//https://leetcode.cn/problems/combination-sum-ii/


class Solution {
public:
	vector<vector<int>> result;
	vector<int> path;
	int sum = 0;
	
	void backTracking(vector<int>& candidates,int target,int startIndex){
		if(sum > target) return;
		if(sum == target){
			result.push_back(path);
			return;
		}
		for(int i = startIndex;i < candidates.size() && sum + candidates[i] <= target;i++){
			if(i > startIndex && candidates[i] == candidates[i - 1]){
				continue;//跳出当前循环
			}
			sum += candidates[i];
			path.push_back(candidates[i]);
			backTracking(candidates,target,i + 1);
			sum -= candidates[i];
			path.pop_back();
		}
		
	}
	
	vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
		sort(candidates.begin(),candidates.end());
		backTracking(candidates,target,0);
		return result;
	}
};
