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
//https://kamacoder.com/problempage.php?pid=1177

//key当前得到的key
//visited记录所有访问过的房间

//这个dfs是处理访问的节点
void dfs(const vector<list<int>>& graph,int key,vector<bool>& visited){
	//如果当前访问到的节点是true，说明这个节点之前已经访问过了，则终止访问
	if(visited[key] == true){
		return;
	}
	
	visited[key] = true;
	list<int> keys = graph[key];
	
	for(int key : keys){
		//dfs
		dfs(graph,key,visited);
	}
}

//void func(const vector<list<int>>& graph,int key,vector<bool>& visited){
//	if(visited[key] == true)
//		return;
//	
//	visited[key] = true;
//	list<int> keys = graph[key];
//	
//	for(int key : keys){
//		dfs(graph,key,visited);
//	}
//}

//处理下一个要访问的节点
void dfs2(const vector<list<int>>& graph,int key,vector<bool>& visited){
	list<int> keys = graph[key];
	
	for(int key : keys){
		//判断下一个要处理的节点是否为未被访问到
		if(visited[key] == false){
			visited[key] = true;
			dfs(graph,key,visited);
		}
	}
}

int main(){
	int n,m,s,t;
	cin>>n>>m;
	
	//节点编号从1到n，所以申请n+1这么大的数组
	
	vector<list<int>> graph(n + 1);//邻接表
	while(m--){
		cin>>s>>t;
		//使用邻接表
		graph[s].push_back(t);
	}
	
	vector<bool> visited(n + 1,false);
	
	dfs(graph,1,visited);
	
	//检查是否都访问到了
	for(int i = 1;i <= n;i++){
		if(visited[i] == false){
			cout<<-1<<endl;
			return 0;
		}
	}
	
	cout<<1<<endl;
}
