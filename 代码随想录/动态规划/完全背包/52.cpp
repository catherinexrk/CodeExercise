#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
//https://kamacoder.com/problempage.php?pid=1052

int main(){
	int n,bagWeight;
	cin>>n>>bagWeight;
	vector<int> weight(n);
	vector<int> value(n);
	
	for(int i = 0;i < n;i++){
		cin>>weight[i];
		cin>>value[i];
	}
	
	//dp[j]表示背包容量为j的时候,dp[j]为当前背包所装得最大值
	vector<int> dp(bagWeight + 1,0);
	
	//遍历物品
	for(int i = 0;i < n;i++){
		//遍历背包
		for(int j = weight[i];j <= bagWeight;j++){
			dp[j] = max(dp[j],dp[j-weight[i]] + value[i]);
		}
	}
	
//	for(int i = 0;i < n;i++){
//		for(int j = bagWeight;j >= weight[i];j--){
//			dp[j] = max(dp[j],dp[j - weight[i]] + value[i]);
//		}
//	}
	
	cout<<dp[bagWeight]<<endl;
	
}
