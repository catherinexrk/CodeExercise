#include <stdlib.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <queue>
#include <math.h>

using namespace std;
//https://kamacoder.com/problempage.php?pid=1172

class Solution{
public:
	int dir[4][2] = {1,0,0,1,-1,0,0,-1};
	int count;
	void dfs(const vector<vector<int>>& grid,vector<vector<bool>> visited,int x,int y){
		//处理当前的岛屿节点，遇到海水就结束
		if(grid[x][y] == 0)
			return;
		
		visited[x][y] = true;
		count++;
		
		for(int i = 0;i < 4;i++){
			int nextx = x + dir[i][0];
			int nexty = y + dir[i][1];
			
			if(nextx < 0 || nextx >= grid.size() || nexty < 0 || nexty >= grid[0].size())
				continue;
			dfs(grid,visited,nextx,nexty);
		}
	}
	
	int init(){
		int n,m;
		cin>>n>>m;
		vector<vector<int>> grid(n,vector<int>(m,0));
		for(int i = 0;i < n;i++){
			for(int j = 0;j < m;j++){
				cin>>grid[i][j];
			}
		}
		
		vector<vector<bool>> visited = vector<vector<bool>>(n,vector<bool>(m,false));
		
		int result = 0;
		
		for(int i = 0;i < n;i++){
			for(int j = 0;j < m;j++){
				if(!visited[i][j] && grid[i][j] == 1){
					count++;//因为dfs处理当前节点，所以遇到陆地计数为0，进dfs之后从1开始计数
					dfs(grid,visited,i,j);
					result = max(result,count);
				}
			}
		}
		
		return result;
	}
};

class Solution2{
public:
	int count;
	int dir[4][2] = {0,1,1,0,-1,0,0,-1};
	void dfs(const vector<vector<int>>& grid,vector<vector<bool>> visited,int x,int y){
		//dfs处理下一个节点，即在主函数遇到岛屿就计数为1，dfs处理接下来的相邻陆地
		for(int i = 0;i < 4;i++){
			int nextx = x + dir[i][0];
			int nexty = y + dir[i][1];
			
			if(nextx < 0 || nextx >= grid.size() || nexty < 0 || nexty >= grid[0].size())
				continue;
			
			if(!visited[nextx][nexty] && grid[nextx][nexty] == 1){ // 没有访问过的&&是陆地
				visited[nextx][nexty] = true;
				count++;
				dfs(grid,visited,nextx,nexty);
			}
		}
	}
	
	int init(){
		int n,m;
		cin>>n>>m;
		vector<vector<int>> grid(n,vector<int>(m,0));
		
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> grid[i][j];
			}
		}
		
		vector<vector<bool>> visited(n, vector<bool>(m, false));
		
		int result = 0;
		for(int i = 0;i < n;i++){
			for(int j = 0;j < m;j++){
				if(!visited[i][j] && grid[i][j] == 1){
					count = 1;
					visited[i][j] = true;
					dfs(grid,visited,i,j);
					result = max(result,count);
				}
			}
		}
		
		return result;
	}
};


int main(){
	Solution s;
	cout<<s.init()<<endl;
	return 0;
}

