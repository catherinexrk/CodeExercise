#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
//https://kamacoder.com/problempage.php?pid=1067

int main(){
	//n为需要多少阶楼梯、m为每次至多爬n阶
	int n,m;
	cin>>n>>m;
	
	vector<int> dp(n + 1,0);
	
	dp[0] = 1;
	
	for(int j = 1;j <= n;j++){
		for(int i = 1;i <= m;i++){
			if(j >= i){
				dp[j] += dp[j - i];
			}
		}
	}
	
	cout<<dp[n];
	return 0;
}
