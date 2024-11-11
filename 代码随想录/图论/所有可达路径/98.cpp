#include <stdlib.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <list>

using namespace std;
//https://kamacoder.com/problempage.php?pid=1170

/**
 * dfs函数首先要存一个图，用来遍历，需要存一个目前我们遍历的节点，定义为X0
 * 还需要存一个n，表示重点，遍历的时候，用来判断当x == n时，标明找到了终点
 */
vector<vector<int>> result;//收集符合条件的路径
vector<int> path;//存储节点到终点的路径
//x：目前遍历的节点
//graph：存当前的图
//n：终点
void dfs(const vector<vector<int>>& graph,int x,int n){
	//当前遍历的节点x到达节点n 
	//终止条件
	if(x == n){  //此时找到了一条符合条件的路径
		result.push_back(path);
		return;
	}
	
	//此时x并没有到达终点
	//遍历节点x链接的所有节点
	for(int i = 1;i <= n;i++){
		if(graph[x][i] == 1){ //找到x指向的节点，就是节点i
			path.push_back(i);//遍历得到的节点加入到路径中来
			dfs(graph,i,n);
			path.pop_back();
		}
	}
}

//x是当前的节点
//n是终点节点
void dfs2(const vector<vector<int>>& graph,int x,int n){
	if(x == n){
		//此时当前节点到达了终点
		result.push_back(path);
		return;
	}
	
	for(int i = 1;i <= n;i++){
		if(graph[x][i] == 1){
			path.push_back(i);
			dfs(graph,i,n);
			path.pop_back();
		}
	}
}

int init(){
	int N,M;
	cin>>N>>M;
	
	vector<vector<int>> graph(N+1,vector<int>(N+1,0));
	int s,t;
	while(M--){
		cin>>s>>t;
		graph[s][t] = 1;
	}
	
	path.push_back(1);
	dfs(graph,1,N);
	
	if(result.size() == 0)
		return -1;
	for(auto temp : result){
		for(int i = 1;i < temp.size() - 1;i++){
			cout<<temp[i]<<" ";
		}
		cout<<temp[temp.size() - 1]<<endl;
	}
	
}

int main(){
	int N,M;
	cin>>N>>M;
	//初始化图的邻接矩阵
	vector<vector<int>> graph(N + 1,vector<int>(N + 1,0));
	int s,t;//s指向t
	while(M--){
		cin>>s>>t;
		graph[s][t] = 1;
	}
	
	//0节点出发
	path.push_back(1);
	dfs(graph,1,N);
	
	if(result.size() == 0)
		cout<<-1<<endl;
	
	for(auto temp : result){
		for(int i = 0;i < temp.size() - 1;i++){
			cout<<temp[i]<<" ";
		}
		cout<<temp[temp.size() - 1]<<endl;
	}
	return 0;
	
//	//邻接表
//	vector<list<int>> graphList(N + 1);
//	for(M--){
//		cin>>s>>t;
//		graphList[s].push_back(t);
//	}
}

