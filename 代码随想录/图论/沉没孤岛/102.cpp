#include <stdlib.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <queue>
#include <math.h>

using namespace std;
//https://kamacoder.com/problempage.php?pid=1174

class Solution{
public:
	int dir[4][2] = {-1,0,0,-1,1,0,0,1};
	
	//标记所有连通的陆地单元格，将其标记为2
	void dfs(vector<vector<int>>& grid,int x,int y){
		grid[x][y] = 2;
		for(int i = 0;i < 4;i++){
			int nextx = x + dir[i][0];
			int nexty = y + dir[i][1];
			
			//超过边界
			if(nextx < 0 ||nextx >= grid.size() || nexty < 0 || nexty >= grid[0].size())
				continue;
			
			//不符合条件，不继续遍历
			if(grid[nextx][nexty] == 0 || grid[nextx][nexty] == 2)
				continue;
			
			dfs(grid,nextx,nexty);
		}
	}
	
	void init(){
		int n,m;
		cin>>n>>m;
		vector<vector<int>> grid(n,vector<int>(m,0));
		
		for(int i = 0;i < n;i++){
			for(int j = 0;j < m;j++){
				cin>>grid[i][j];
			}
		}
		
		//步骤一：深搜或者广搜将地图周边的1全改成2 (unique mark)
		//从左侧边、和右侧边 向中间遍历
		for(int i = 0;i < n;i++){
			if(grid[i][0] == 1)
				dfs(grid,i,0);
			if(grid[i][m - 1] == 1)
				dfs(grid,i,m - 1);
		}

		//从上边、下边向中间遍历
		for(int i = 0;i < m;i++){
			if(grid[0][i] == 1)
				dfs(grid,0,i);
			if(grid[n - 1][i] == 1)
				dfs(grid,n - 1,i);
		}
		
		//步骤二：将水域中间的陆地改成水域0
		//步骤三：将之前标记的特殊标记2改成1 陆地
		for(int i = 0;i < n;i++){
			for(int j = 0;j < m;j++){
				if(grid[i][j] == 1)
					grid[i][j] = 0;
				if(grid[i][j] == 2)
					grid[i][j] == 1;
			}
		}
		
		for(int i = 0;i < n;i++){
			for(int j = 0;j < m;j++){
				cout<<grid[i][j] << " ";
			}
			
			cout<<endl;
		}
		
	}
};
