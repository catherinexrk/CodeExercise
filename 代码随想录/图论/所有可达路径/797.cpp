#include <stdlib.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <list>

using namespace std;
//https://leetcode.cn/problems/all-paths-from-source-to-target/

class Solution {
public:
	
	vector<vector<int>> result;
	vector<int> path;
	void dfs(const vector<vector<int>>& graph,int x,int n){
		if(x == n - 1){
			result.push_back(path);
			return;
		}
		
		for(int i : graph[x]){
			path.push_back(i);
			dfs(graph,i,n);
			path.pop_back();
		}
	}
	
	vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
		int size = graph.size();
		path.push_back(0);
		dfs(graph,0,size);
		return result;
	}
};
