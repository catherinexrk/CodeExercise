#include <stdlib.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <queue>

using namespace std;
//https://kamacoder.com/problempage.php?pid=1171

int dir[4][2] = {0,1,1,0,-1,0,0,-1};//四个方向

void dfs(const vector<vector<int>>& grid,vector<vector<bool>>& visited,int x,int y){
	//终止条件:访问过的节点或者遇到海水
	if(visited[x][y] || grid[x][y] == 0)
		return;
	
	for(int i = 0;i < 4;i++){
		int nextX = x + dir[i][0];
		int nextY = y + dir[i][1];
		
		if(nextX < 0 || nextX >= grid.size() || nextY < 0 || nextY >= grid[0].size())
			continue;//越界
		
		//{nextX,nextY}没有访问,并且同时也是陆地
		if(!visited[nextX][nextY] && grid[nextX][nextY] == true){
			visited[nextX][nextY] = true;
			
			dfs(grid,visited,nextX,nextY);
		}
	}
}

void dfs2(const vector<vector<int>>& grid,vector<vector<bool>>& visited,int x,int y){
	for(int i = 0;i < 4;i++){
		int nextx = x + dir[i][0];
		int nexty = y + dir[i][1];
		
		if(nextx < 0 || nextx >= grid.size() || nexty < 0 || nexty >= grid[0].size())
			continue;
		
		if(!visited[nextx][nexty] && grid[nextx][nexty] == true){
			visited[nextx][nexty] = true;
			
			dfs2(grid,visited,nextx,nexty);
		}
	}
}

void damn(){
	int n,m;
	cin>>n>>m;
	
	vector<vector<int>> grid(n,vector<int>(m,0));
	
	for(int i = 0;i < n;i++){
		for(int j = 0;j < m;j++){
			cin>>grid[i][j];
		}
	}
	
	vector<vector<bool>> visited(n,vector<bool>(m,false));
	
	int result = 0;
	for(int i = 0;i < n;i++){
		for(int j = 0;j < m;j++){
			if(!visited[i][j] && grid[i][j] == 1){
				visited[i][j] = true;
				result++;
				dfs2(grid,visited,i,j);
			}
		}
	}
	
	cout<<result<<endl;
}

int main(){
	int n,m;//行 列
	cin>>n>>m;
	
	vector<vector<int>> grid(n,vector<int>(m,0));
	
	for(int i = 0;i < n;i++){
		for(int j = 0;j < m;j++){
			cin>>grid[i][j];
		}
	}
	
	vector<vector<bool>> visited(n,vector<bool>(m,false));
	
	int result = 0;
	for(int i = 0;i < n;i++){
		for(int j = 0;j < m;j++){
			if(!visited[i][j] && grid[i][j] == 1){
				visited[i][j] = true;
				result++;//遇到没有访问到的陆地
				dfs(grid,visited,i,j);
			}
		}
	}
	
	cout<<result<<endl;
}
