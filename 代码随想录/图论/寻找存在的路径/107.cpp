#include <stdlib.h>
#include <vector>
#include <iostream>

using namespace std;
//https://kamacoder.com/problempage.php?pid=1179

/**
 * 并查集可以解决什么：
 * 判断两个节点在不在一个集合，也可以将两个节点添加到一个集合中
 */

int n;//节点数量
vector<int> father = vector<int>(101,0);//按照节点大小定义数组大小

//并查集初始化
void init(){
	for(int i = 0;i <= n;i++) father[i] = i;
}

//并查集里寻根的过程
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

//将v->u加入并查集
void join(int u,int v){
	u = find(u);
	v = find(v);
	if(u == v) return;
	father[v] = u;
}

int main(){
	int m,s,t,source,destination;
	cin>>n>>m;
	init();
	while(m--){
		cin>>s>>t;
		join(s,t);
	}
	
	cin>>source>>destination;
	if(isSame(source,destination))
		cout<<1<<endl;
	else
		cout<<0<<endl;
}
