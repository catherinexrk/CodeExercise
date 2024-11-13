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
//https://kamacoder.com/problempage.php?pid=1178

int main(){
	int n,m,s,t;
	cin>>n>>m;
	
	vector<vector<int>> grid(n,vector<int>(m,0));
	
	for(int i = 0;i < n;i++){
		for(int j = 0;j < m;j++){
			cin>>grid[i][j];
		}
	}
	
	int dir[4][2] = {0,1,1,0,-1,0,0,-1};
	int result = 0;
	
	for(int i = 0;i < n;i++){
		for(int j = 0;j < m;j++){
			if(grid[i][j] == 1){
				//上下左右四个方面
				for(int k = 0;k < 4;k++){
					int x = i + dir[k][0];
					int y = j + dir[k][1]; //计算周边坐标x、y
					
					if(x < 0 //x在边界上
						   || x >= grid.size() //x在边界上
						   || y < 0 // x在边界上 //y在边界上
						   || y >= grid[0].size() //y在边界上
						   || grid[x][y] == 0 //x、y位置是水域
						){
						result++;
					}
				}
				
			}
		}
	}
	
	cout<<result<<endl;
	
}
