#include <iostream>
#include <vector>
#include <algorithm> // 引入算法库，因为使用了max函数

using namespace std;
//https://kamacoder.com/problempage.php?pid=1046

int main() {
	int n, bagWeight; // n为物品的数量，bagWeight为背包存放的最大重量
	cin >> n >> bagWeight;
	
	vector<int> weight(n, 0); // 存储每个物品所占空间
	vector<int> value(n, 0); // 存储每个物品价值
	
	for (int i = 0; i < n; i++) {
		cin >> weight[i]; // 正确的索引是i
	}
	
	for (int j = 0; j < n; j++) {
		cin >> value[j]; // 正确的索引是j
	}
	
	// dp数组，dp[i][j]表示背包容量为j情况下，从下标[0,i]的物品中任意取，能达到的最大价值
	vector<vector<int>> dp(n, vector<int>(bagWeight + 1, 0));
	
	// 初始化
	for (int j = weight[0]; j <= bagWeight; j++) {
		dp[0][j] = value[0];
	}
	
	// 遍历物品
	for (int i = 1; i < n; i++) {
		// 遍历背包容量
		for (int j = 0; j <= bagWeight; j++) {
			if (j < weight[i]) {
				//如果当前的物品的容量大于背包的上限
				dp[i][j] = dp[i - 1][j]; // 如果装不下这个物品，那么就继承dp[i - 1][j]
			} else {
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight[i]] + value[i]);
			}
		}
	}
	
	//遍历物品
	for(int i = 1;i < n;i++){
		//遍历背包
		for(int j = 0;j <= bagWeight;j++){
			if(j < weight[i])
				dp[i][j] = dp[i - 1][j];
			else
				dp[i][j] = max(dp[i-1][j - weight[i]] + value[i],dp[i-1][j]);
		}
	}
	
	cout << dp[n - 1][bagWeight] << endl;
	return 0;
}
