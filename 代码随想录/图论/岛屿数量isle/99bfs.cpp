#include <stdlib.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <queue>

using namespace std;
//https://kamacoder.com/problempage.php?pid=1171

int dir[4][2] = {0,1,1,0,-1,0,0,-1};//表示四个方向

void bfs(const vector<vector<int>>& grid,vector<vector<bool>> visited,int x,int y){
	queue<pair<int,int>> que;//队列
	que.push({x,y});
	visited[x][y] = true;//当前节点已经被访问
	
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
			
			if(!visited[nextx][nexty] && grid[nextx][nexty] == 1){
				que.push({nextx,nexty});
				visited[nextx][nexty] = 1;//加入队列就立刻进行标记
			}
			
		}
	}
}

int main(){
	int n,m;
	cin>>n>>m;
	vector<vector<int>> grid(n,vector<int>(m,0));
	
	for(int i = 0;i < n;i++){
		for(int j = 0;j < m;j++){
			cin>>grid[i][j];
		}
	}

	vector<vector<bool>> visited(n, vector<bool>(m, false));
	
	int result = 0;
	for(int i = 0;i < n;i++){
		for(int j = 0;j < m;j++){
			if(!visited[i][j] && grid[i][j] == 1){
				result++;//遇到没访问的陆地+1
				bfs(grid,visited,i,j);
			}
		}
	}
	
	cout<<result<<endl;
}
