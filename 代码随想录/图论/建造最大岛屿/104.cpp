#include <stdlib.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <queue>
#include <math.h>
#include <unordered_map>
#include <unordered_set>

using namespace std;

//https://kamacoder.com/problempage.php?pid=1176

/**
 * 1.一次遍历地图，得出各个岛屿的面积，并做编号记录，使用map记录，key为岛屿编号，value为岛屿面积
 * 2.再遍历地图，遍历0的方格，并统计将该0变成1之后其周边岛屿的面积，将其相邻面积相加在一起，遍历所有0之后，
 * 	 便可以得出选一个从0变成1之后的最大面积
 */
class Solution{
public:
	int count;
	int n,m;
	
	int dir[4][2] = {0,1,1,0,-1,0,0,-1};//四个方向
	
	void dfs(vector<vector<int>>& grid,vector<vector<bool>>& visited,int x,int y,int mark){
		//终止条件：访问过的节点  ||  遇到海水grid == 0
		if(visited[x][y] || grid[x][y] == 0)
			return;
		
		visited[x][y] = true;
		grid[x][y] = mark;
		count++;
		
		for(int i=0;i < 4;i++){
			int nextx = x + dir[i][0];
			int nexty = y + dir[i][1];
			
			if(nextx < 0 || nextx >= grid.size() || nexty < 0 || nexty >= grid[0].size())
				continue;
			
			dfs(grid,visited,nextx,nexty,mark);
		}
	}
		
	int main(){
		cin>>n>>m;
		
		vector<vector<int>> grid(n,vector<int>(m,0));
		
		for(int i = 0;i < n;i++){
			for(int j = 0;j < m;j++){
				cin>>grid[i][j];
			}
		}
		
		//标记访问过的点
		vector<vector<bool>> visited(n,vector<bool>(m,false));
		
		unordered_map<int,int> gridNum;
		
		//记录每一个岛屿的编号
		int mark = 2;
		
		//标记书否整个地图都是陆地
		bool isAllGrid = true;
		
		for(int i = 0;i < n;i++){
			for(int j = 0;j < m;j++){
				if(grid[i][j] == 0)
					isAllGrid = false;
				
				if(!visited[i][j] && grid[i][j] == 1){
					count = 0;
					
					//将与其链接的陆地都标记上true
					dfs(grid,visited,i,j,mark);
					
					//记录每一个岛屿的面积
					gridNum[mark] = count;
					
					//记录下一个岛屿编号
					mark++;
				}
			}
		}
		
		if(isAllGrid){
			//如果都是陆地，返回全面积
			cout<<n * m<<endl;
			
			//结束程序
			return 0;
		}
		
		// 以下逻辑是根据添加陆地的位置，计算周边岛屿面积之和
		int result = 0; // 记录最后结果
		unordered_set<int> visitedGrid; // 标记访问过的岛屿
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				count = 1; // 记录连接之后的岛屿数量
				visitedGrid.clear(); // 每次使用时，清空
				if (grid[i][j] == 0) {
					for (int k = 0; k < 4; k++) {
						int neari = i + dir[k][1]; // 计算相邻坐标
						int nearj = j + dir[k][0];
						if (neari < 0 || neari >= n || nearj < 0 || nearj >= m) continue;
						if (visitedGrid.count(grid[neari][nearj])) continue; // 添加过的岛屿不要重复添加
						// 把相邻四面的岛屿数量加起来
						count += gridNum[grid[neari][nearj]];
						visitedGrid.insert(grid[neari][nearj]); // 标记该岛屿已经添加过
					}
				}
				result = max(result, count);
			}
		}
		cout << result << endl;
		
	}
};
