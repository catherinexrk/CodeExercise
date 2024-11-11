#include <stdlib.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <queue>

using namespace std;

int dir[4][2] = {0, 1, 1, 0, -1, 0, 0, -1}; // 表示四个方向
// grid 是地图，也就是一个二维数组
// visited标记访问过的节点，不要重复访问
// x,y 表示开始搜索节点的下标
void bfs(vector<vector<char>>& grid, vector<vector<bool>>& visited, int x, int y) {
	queue<pair<int, int>> que; // 定义队列
	que.push({x, y}); // 起始节点加入队列
	visited[x][y] = true; // 只要加入队列，立刻标记为访问过的节点
	while(!que.empty()) { // 开始遍历队列里的元素
		pair<int ,int> cur = que.front(); // 从队列取元素
		que.pop(); 
		int curx = cur.first;
		int cury = cur.second; // 当前节点坐标
		for (int i = 0; i < 4; i++) { // 开始想当前节点的四个方向左右上下去遍历
			int nextx = curx + dir[i][0];
			int nexty = cury + dir[i][1]; // 获取周边四个方向的坐标
			if (nextx < 0 || nextx >= grid.size() || nexty < 0 || nexty >= grid[0].size()) continue;  // 坐标越界了，直接跳过
			if (!visited[nextx][nexty]) { // 如果节点没被访问过
				que.push({nextx, nexty});  // 队列添加该节点为下一轮要遍历的节点
				visited[nextx][nexty] = true; // 只要加入队列立刻标记，避免重复访问
			}
		}
	}
	
}


//grid为地图,也就是一个二维数组
//visited存储访问过的节点,不要重复访问
//x y表示开始搜索节点的下标
void bfs2(vector<vector<char>>& grid,vector<vector<bool>>& visited,int x,int y){
	queue<pair<int,int>> que;//队列存储坐标信息
	que.push({x,y});
	
	visited[x][y] = true;//只要加入队列,便立刻标记为访问过的节点
	while(!que.empty()){
		pair<int,int> cur = que.front();
		que.pop();
		int curx = cur.first;
		int cury = cur.second;
		
		//开始朝者当前节点的四个方向上下去遍历
		for(int i = 0;i < 4;i++){
			int nextx = curx + dir[i][0];
			int nexty = cury + dir[i][1];//获取周边四个方向的坐标
			
			//坐标越界,直接跳过
			if(nextx < 0 || nextx >= grid.size() || nexty < 0 || nexty >= grid[0].size())
				continue;
			
			//如果节点没被访问到
			if(!visited[nextx][nexty]){
				//队列添加该节点为下一轮要遍历的节点
				que.push({nextx,nexty});
				
				visited[nextx][nexty] = true;//只要加入队列,便进行标记,避免重复访问
			}
		}
	}
}
