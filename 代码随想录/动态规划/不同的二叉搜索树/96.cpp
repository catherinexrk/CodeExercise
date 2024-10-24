#include <stdlib.h>
#include <iostream>
#include <vector>
#include <string>

using namespace std;
//https://leetcode.cn/problems/unique-binary-search-trees/

class Solution {
public:
	int numTrees(int n) {
		//dp[i]表示1到i节点组成的二叉搜索树的个数为dp[i]
//		dp[3] = dp[2]*dp[0] + dp[1]dp[1] + dp[0]*dp[2];
		//dp[3]为dp[0] dp[1] dp[2]的累加之和
		vector<int> dp(n + 1);
		dp[0] = 1;//空树也是二叉树
		
		for(int i = 1;i <= n;i++){
			//j表示从1开始遍历累加
			for(int j = 1;j <= i;j++){
				//以j为根节点，左子树是1到j-1的数值节点构成左子树
				//j+1 到i 构成了右子树 i - (j + 1) + 1有i - j个节点
				dp[i] += dp[j - 1] * dp[i - j];
			}
		}
		
		return dp[n];
	}
};
