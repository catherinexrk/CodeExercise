#include <stdlib.h>
#include <vector>
#include <iostream>

using namespace std;
//https://kamacoder.com/problempage.php?pid=1181

int n;
vector<int> father(1001,0);

void init(){
	for(int i = 0;i <=n;i++){
		father[i] = i;
	}
}

int find(int u){
	return u == father[u] ? u : father[u] = find(father[u]);
}

bool isSame(int u,int v){
	u = find(u);
	v = find(v);
	return u == v;
}

void join(int u,int v){
	u = find(u);
	v = find(v);
	if(u == v) return;
	
	father[v] = u;
}

int main(){
	int s,t;
	cin>>n;
	init();
	for(int i = 0;i < n;i++){
		cin>>s>>t;
		if(isSame(s,t)){
			cout<<s<<" "<<t<<endl;
			return 0;
		} else {
			join(s,t);
		}
	}
}
