#include <stdlib.h>
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;
//https://leetcode.cn/problems/minimum-depth-of-binary-tree/

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
	
	//dfs
	int minDepth(TreeNode* root) {
		if(root == nullptr) return 0;
		int leftHeight = minDepth(root->left);
		int rightHeight = minDepth(root->right);
		int minDepth = min(leftHeight,rightHeight) + 1;
		return minDepth;
	}
};
