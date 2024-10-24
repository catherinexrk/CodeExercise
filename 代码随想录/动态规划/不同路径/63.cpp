#include <stdlib.h>
#include <iostream>
#include <vector>
#include <string>

using namespace std;
//https://leetcode.cn/problems/unique-paths-ii/

class Solution {
public:
	int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
		int m = obstacleGrid.size();//行
		int n = obstacleGrid[0].size();//列
		
		//开头就被堵住了
		if(obstacleGrid[0][0] == 1 || obstacleGrid[m-1][n-1] == 1)
			return 0;
		
		vector<vector<int>> dp(m,vector<int>(n,0));
		
//		int i,j;
//		dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
		//更新行
		for(int i = 0;i < n;i++){
			if(obstacleGrid[0][i] == 1){
				break;
			}
			dp[0][i] = 1;
		}
		
		//更新列
		for(int j = 0;j < m;j++){
			if(obstacleGrid[j][0] == 1)
				break;
			dp[j][0] = 1;
		}
		
		for(int i = 1;i < m;i++){
			for(int j = 1;j < n;j++){
				if(obstacleGrid[i][j] == 1){
					continue;
				}
				dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
			}
		}
		
		return dp[m - 1][n - 1];
	}
};
