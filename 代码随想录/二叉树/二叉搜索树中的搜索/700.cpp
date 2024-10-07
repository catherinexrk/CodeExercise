#include <stdlib.h>
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;
//https://leetcode.cn/problems/search-in-a-binary-search-tree/

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
	TreeNode* searchBST(TreeNode* root, int val) {
		//确定终止条件
		if(root == nullptr || root->val == val) return root;
		
		TreeNode * node = nullptr;
		if(root->val > val) node = searchBST(root->left,val);
		if(root->val < val) node = searchBST(root->right,val);
		
		return node;
	}
};
