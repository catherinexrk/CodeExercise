#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;
//https://leetcode.cn/problems/combination-sum/

/**
 * void backTracking(){
 * 		if(){
 * 		}
 * 		for(){
 * 		}
 * }
 */
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
		for(int i = startIndex;i < candidates.size();i++){
			sum += candidates[i];
			path.push_back(candidates[i]);
			//为什么startIndex = i，因为可以包括自己本身，因此每次都要把自己再开始操作一遍
			backTracking(candidates,target,i);
			sum -= candidates[i];
			path.pop_back();
		}
		
	}
	
	void backTrackingPruning(vector<int>& candidates,int target,int startIndex){
		if(sum > target) return;
		if(sum == target){
			result.push_back(path);
			return;
		}
		for(int i = startIndex;i < candidates.size() && sum + candidates[i] <= target;i++){
			sum += candidates[i];
			path.push_back(candidates[i]);
		
			//为什么startIndex = i，因为可以包括自己本身，因此每次都要把自己再开始操作一遍
			backTracking(candidates,target,i);
			sum -= candidates[i];
			path.pop_back();
		}
	}
	
	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
//		backTracking(candidates,target,0);
		sort(candidates.begin(),candidates.end());
		backTrackingPruning(candidates,target,0);
			
		return result;
	}
};


