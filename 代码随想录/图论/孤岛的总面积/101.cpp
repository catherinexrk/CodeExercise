#include <stdlib.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <queue>
#include <math.h>

using namespace std;
//https://kamacoder.com/problempage.php?pid=1173

/**
 * 找的是不靠边的陆地面积，则从周边找到陆地之后，通过dfs或者bfs将周边靠陆地并且相邻的陆地变成海洋
 * 然后再去重新遍历地图，统计此时还剩下的陆地即可
 */

class Solution{
public:
	int dir[4][2] = {-1,0,0,-1,1,0,0,1};
	int count;//统计符合题目要求的陆地空格数量
	
	void dfs(vector<vector<int>>& grid,int x,int y){
		grid[x][y] = 0;//将访问过的单元格标记为已访问过
		count++;
		
		for(int i = 0;i < 4;i++){
			int nextx = x + dir[i][0];
			int nexty = y + dir[i][1];
			
			//超过边界
			if(nextx < 0 || nextx >= grid.size() || nexty < 0 || nexty >= grid[0].size())
				continue;
			
			//不符合条件，继续遍历
			if(grid[nextx][nexty] == 0)
				continue;
			//如果相邻单元格是陆地1，则递归调用dfs函数，如果是水0，则跳过单元格
			dfs(grid,nextx,nexty);
		}
		
		return;
	}
	
	int func1(){
		int n, m;
		cin >> n >> m;
		vector<vector<int>> grid(n, vector<int>(m, 0));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> grid[i][j];
			}
		}
		
		//从左侧边，和右侧边，向中间遍历
		for(int i = 0;i < n;i++){
			if(grid[i][0] == 1)
				dfs(grid,i,0);
			if(grid[i][m - 1] == 1)
				dfs(grid,i,m - 1);
		}
		
		//从上边、下边，向中间遍历
		for(int j = 0;j < m;j++){
			if(grid[0][j] == 1)
				dfs(grid,0,j);
			if(grid[n - 1][j] == 1)
				dfs(grid,n - 1,j);
		}
		
		count = 0;
		
		for(int i = 0;i < n;i++){
			for(int j = 0;j < m;j++){
				if(grid[i][j] == 1)
					dfs(grid,i,j);
			}
		}
		
		return count;
	}
	
	void bfs(vector<vector<int>>& grid,int x,int y){
		queue<pair<int,int>> que;
		que.push({x,y});
		
		grid[x][y] = 0;//只要加入队列，就立刻标记为海洋0
		count++;
		
		while(!que.empty()){
			pair<int,int> cur = que.front();
			que.pop();
			
			int curx = cur.first;
			int cury = cur.second;
			
			for(int i = 0;i < 4;i++){
				int nextx = curx + dir[i][0];
				int nexty = cury + dir[i][1];
				
				if(nextx < 0 || nextx >= grid.size() || nexty < 0 || nexty >= grid[0].size())
					continue;//越界了直接跳过
				
				if(grid[nextx][nexty] == 1){
					que.push({nextx,nexty});
					count++;
					grid[nextx][nexty] = 0;//只要加入队列立刻标记
				}
			}
		}
	}
};
