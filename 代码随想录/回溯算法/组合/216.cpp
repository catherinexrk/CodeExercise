#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;
//https://leetcode.cn/problems/combination-sum-iii/

class Solution {
public:
	vector<int> path;
	int sum = 0;
	vector<vector<int>> result;
	
	void backTracking(int n,int k,int startIndex){
		if(sum == n && path.size() == k){
			result.push_back(path);
			return;
		}
		if(sum > n) return;
		
		for(int i = startIndex;i <= 9 - (k - path.size()) + 1;i++){
			sum += i;
			path.push_back(i);
			
			backTracking(n,k,i + 1);
			path.pop_back();
			sum -= i;
		}
	}
	
	vector<vector<int>> combinationSum3(int k, int n) {
		backTracking(n,k,1);
		
		return result;
	}
};

class Solution2{
public:
	vector<int> path;
	vector<vector<int>> result;
	int sum = 0;
	
	void backTracking(int n,int k,int startIndex){
		if(sum == n && path.size() == k){
			result.push_back(path);
			return;
		}
		if(sum > n) return;//剪枝操作
		
		for(int i = startIndex;i <= 9 - ( k - path.size()) + 1;i++){
			sum += i;
			path.push_back(i);
			
			backTracking(n,k,i + 1);
			
			sum -= i;
			path.pop_back();
		}
	}
};
