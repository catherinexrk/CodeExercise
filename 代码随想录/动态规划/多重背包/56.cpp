#include <iostream>
#include <vector>
#include <algorithm>
//#include <unordered_set>

using namespace std;
//https://kamacoder.com/problempage.php?pid=1066

/**
 * 如何解答多重背包
 * 将多重背包全部展开得到01背包
 */
int main(){
	int bagWeight,n;
	cin >> bagWeight >> n;
	vector<int> weight(n, 0); //重量
	vector<int> value(n, 0); //价值
	vector<int> nums(n, 0); //数量
	for (int i = 0; i < n; i++) cin >> weight[i];
	for (int i = 0; i < n; i++) cin >> value[i];
	for (int i = 0; i < n; i++) cin >> nums[i];   
	
	for(int i = 0;i < n;i++){
		while(nums[i] > 1){ //物品数量不是1的，都展开
			weight.push_back(weight[i]);
			value.push_back(value[i]);
			nums[i]--;
		}
	}

	vector<int> dp(bagWeight + 1,0);
	//遍历物品，此时物品的数量不是n，应当为weight的总数
	for(int i = 0;i < weight.size();i++){
		//遍历背包容量
		for(int j = bagWeight;i >= weight[i];j--){
			dp[j] = max(dp[j],dp[j - weight[i]] + value[i]);
		}
	}
	
	cout<<dp[bagWeight]<<endl;
}

void damn(){
	int bagWeight,n;
	cin >> bagWeight >> n;
	vector<int> weight(n, 0); //重量
	vector<int> value(n, 0); //价值
	vector<int> nums(n, 0); //数量
	for (int i = 0; i < n; i++) cin >> weight[i];
	for (int i = 0; i < n; i++) cin >> value[i];
	for (int i = 0; i < n; i++) cin >> nums[i];   
	
	for(int i = 0;i < n;i++){
		while(nums[i] > 1){
			weight.push_back(weight[i]);
			value.push_back(value[i]);
			nums[i]--;
		}
	}
	
	vector<int> dp(bagWeight + 1,0);
	
	for(int i = 0;i < weight.size();i++){
		for(int j = bagWeight;j >= weight[i];j--){
			dp[j] = max(dp[j],dp[j - weight[i]] + value[i]);
		}
	}
	
	cout<<dp[bagWeight]<<endl;
}


void damn2() {
	int bagWeight, n;
	cin >> bagWeight >> n;
	vector<int> weight(n), value(n), nums(n);
	for (int i = 0; i < n; i++) cin >> weight[i];
	for (int i = 0; i < n; i++) cin >> value[i];
	for (int i = 0; i < n; i++) cin >> nums[i];
	
	vector<int> dp(bagWeight + 1, 0);
	
	//遍历所有类型的石头
	for (int i = 0; i < n; i++) {
		//考虑同一个种类中的石头，从头到尾进行遍历 from stem to stren
		for (int k = 1; k <= nums[i]; k++) {
			// 从后向前更新dp数组，避免重复使用同一块石头
			for (int j = bagWeight; j >= weight[i]; j--) {
				dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
			}
		}
	}
	
//	for(int i = 0;i < n;i++){
//		for(int j = 1;j <= nums[i];j++){
//			for(int k = bagWeight;j > weight[i];k--){
//				dp[k] = max(dp[k],dp[k - weight[i]] + value[i]);
//			}
//		}
//	}
	
	cout << dp[bagWeight] << endl;
}
