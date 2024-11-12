#include <stdlib.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <queue>
#include <math.h>

using namespace std;
//https://kamacoder.com/problempage.php?pid=1172

int dir[4][2] = {1,0,0,1,-1,0,0,-1};
int sum;
void bfs(const vector<vector<int>>& grid,vector<vector<bool>> visited,int x,int y){
	queue<pair<int,int>> que;
	que.push({x,y});
	visited[x][y] = true;//加入visited代表该节点是陆地可以到达的点
	
	while(!que.empty()){
		pair<int,int> cur = que.front();
		que.pop();
		
		int curx = cur.first;
		int cury = cur.second;
		
		for(int i = 0;i < 4;i++){
			int nextx = curx + dir[i][0];
			int nexty = cury + dir[i][1];
			
			if(nextx < 0 || nextx >= grid.size() || nexty < 0 || nexty >= grid[0].size())
				continue;	
			
			if(!visited[nextx][nexty] && grid[nextx][nexty]){
				que.push({nextx,nexty});
				visited[nextx][nexty] = true;
				sum++;
			}
		}
	}
}

int main(){
	int n,m,s,t;
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
			if(!visited[i][j] && grid[i][j]){
				sum = 0;
				bfs(grid,visited,i,j);
				result = max(result,sum);
			}	
		}
	}
	
	return result;
}

