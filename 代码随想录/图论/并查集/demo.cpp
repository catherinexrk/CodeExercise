#include <stdlib.h>
#include <vector>
#include <iostream>

using namespace std;

class Solution1{
public:
	vector<int> father;
	
//初始化并查集，默认指向自己
	void init(){
		for(int i = 0;i < father.size();i++){
			father[i] = i;
		}
	}
	
//并查集里寻根的过程
	int find(int u){
		if(u == father[u]){
			return u;//如果根是自己，直接返回
		} else {
			return find(father[u]);//如果根不是自己，则按照数组下标一层一层向下找
		}
	}
	
//寻根 压缩路径
	int find2(int u){
		if(u == father[u]) return u;
		else return father[u] = find(father[u]);
	}
	
//将v、u这条边加入并查集
	void join(int u,int v){
		u = find(u);//寻找u的根
		v = find(v);//寻找v的根
		if(u == v){ ////如果发现根相同，说明在一个集合中，不用两个节点相连直接返回
			return;
		}
		father[v] = u;
	}
	
//判断u和v是否找到同一个根
	bool isSame(int u,int v){
		u = find(u);
		v = find(v);
		return u == v;
	}
};

class Solution2{
public:
	int n = 1005;
	vector<int> father = vector<int>(n,0);
	
	//并查集初始化
	void init(){
		for(int i=0;i < n;i++){
			father[i] = i;
		}
	}
	 
	//并查集寻根 压缩路径
	int find(int u){ 
		if(u == father[u]) return u;
		else return father[u] = find(father[u]);
	}
	
	//判断u和v是否找到同一个根
	bool isSame(int u,int v){
		u = find(u);
		v = find(v);
		return u == v;
	}
	
	//将v->u这条边加入到并查集中
	void join(int u,int v){
		u = find(u);
		v = find(v);
		if(u == v) return;
		father[v] = u;
	}
};
