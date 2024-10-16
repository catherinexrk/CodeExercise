#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;
//https://leetcode.cn/problems/combinations/

/**
 * 组合 切割 子集 排列 棋盘
 */

//void backTracking(参数){
//	if(终止条件){
//		存放结果;
//		return;
//	}
//	
//	for(选择：本层集合中的元素){
//		处理节点
//		backTracking(路径，选择列表);//递归
//		回溯，撤销处理结果
//	}
//}

/**
 * 递归函数参数、返回值
 * 确定终止条件
 * 单层递归逻辑
 */

class Solution {
public:
	
	vector<int> path;
	vector<vector<int>> result;
	void backTracking(int n,int k,int startIndex){
		//纵向遍历
		if(path.size() == k){
			result.push_back(path);
			return;
		}
		//横向遍历
		for(int i = startIndex;i <= n;i++){
			path.push_back(i);
			backTracking(n,k,i + 1);
			path.pop_back();
		}
		
	}
	
	vector<vector<int>> combine(int n, int k) {
		backTracking(n,k,1);
		return result;
	}
};

class Solution2{
public:
	vector<int> path;
	vector<vector<int>> result;
	void backTracking(int n,int k,int startIndex){
		if(path.size() == k){
			result.push_back(path);
			return;
		}
		
		for(int i = startIndex;i <= n - ( k - path.size()) + 1;i++){
			path.push_back(i);
			backTracking(n,k,i + 1);
			path.pop_back();
		}
	}
	
	vector<vector<int>> combine(int n, int k) {
		backTracking(n,k,1);
		return result;
	}
};
