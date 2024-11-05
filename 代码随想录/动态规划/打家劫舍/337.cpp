#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
//https://leetcode.cn/problems/house-robber-iii/

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
	int rob(TreeNode* root) {
		vector<int> result = robTree(root);
		return max(result[0],result[1]);
	}
	
	vector<int> robTree(TreeNode * cur){
		//dp数组是一个存储两个元素的数组，其中dp[0]表示不偷当前节点所得到的最大金钱
		//dp[1]表示记录偷当前节点的情况下所得到的最大金钱
		
		if(cur == nullptr)
			return vector<int>{0,0};
		
		//0不偷当前节点  1偷当前节点
		vector<int> left = robTree(cur->left);//左
		vector<int> right = robTree(cur->right);//右
		
		//偷cur，那么就不能偷左右节点
		int val1 = cur->val + left[0] + right[0];
		
		//不偷cur，那么可以偷也可以不偷左右节点，去取较大情况
		int val2 = max(left[0], left[1]) + max(right[0], right[1]);
		
		return {val2,val2};
		
	}
	
	vector<int> func(TreeNode * root){
		if(root == nullptr)
			return {0,0};
		
		vector<int> left = func(root->left);
		vector<int> right = func(root->right);
		
		//偷当前节点
		int val1 = root->val + left[0] + right[0];
		
		//不偷当前节点
		int val2 = max(left[0],left[1]) + max(right[0],right[1]);
		
		return {val2,val1};
	}
};
