#include <stdlib.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <list>

using namespace std;
//https://kamacoder.com/problempage.php?pid=1170


vector<vector<int>> result;
vector<int> path;

void dfs(const vector<list<int>>& graph,int x,int n){
	if(x == n){
		result.push_back(path);
		return;
	}
	
	for(int i : graph[x] ){
		path.push_back(i);
		dfs(graph,i,n);
		path.pop_back();
	}
}


int main(){
	int n,m,s,t;
	cin>>n>>m;
	
	vector<list<int>> graph(n + 1);
	while(m--){
		cin>>s>>t;
		graph[s].push_back(t);
	}
	
	path.push_back(1);
	dfs(graph,1,n);
	
	if(result.size() == 0)
		return -1;
	for(auto temp : result){
		for(int i = 0;i < temp.size() - 1;i++){
			cout<<temp[i]<<" ";
		}
		cout<<temp[temp.size() - 1]<<endl;
	}
}
