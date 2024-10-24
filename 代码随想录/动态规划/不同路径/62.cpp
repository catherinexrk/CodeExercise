#include <stdlib.h>
#include <iostream>
#include <vector>
#include <string>

using namespace std;
//https://leetcode.cn/problems/unique-paths/

class Solution {
public:
	//图论的dfs深度搜索
	int dfs(int i,int j,int m,int n){
		if(i > m || j > n) 
			return 0;//越界
		if(i == m && j == n)
			return 1;//找到了一种方法到达重点
		return dfs(i + 1,j,m,n) + dfs(i,j + 1,m,n);
	}
	
	int uniquePaths(int m, int n) {
		return dfs(1,1,m,n);
	}
	
	
	//i行 j列 m总长 n总高
	int dfs1(int i,int j,int m,int n){
		if(i > m || j > n)
			return 0;//越界
		if(i == m && j == n)
			return 1;//找到了一种方法
		return dfs1(i + 1,j,m,n) + dfs1(i,j + 1,m,n);
	}
	
	int func(int m,int n){
		return dfs1(1,1,m,n);
	}
};

class Solution1 {
public:
	int uniquePaths(int m, int n) {
		vector<vector<int>> dp(m,vector<int>(n,0));
		//dp[i][j]表示到达i行j列有多少种方法
		
		//找到递推公式
//		int i,j;
//		dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
		
		//初始化
		for(int i = 0;i < m;i++) dp[i][0] = 1;
		for(int j = 0;j < n;j++) dp[0][j] = 1;
		
		for(int i = 1;i < m;i++){
			for(int j = 1;j < n;j++){
					dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
			}
		}
		
		return dp[m - 1][n - 1];
	}
};
