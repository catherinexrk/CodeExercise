#include <stdlib.h>
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;
//https://leetcode.cn/problems/lowest-common-ancestor-of-a-binary-tree/

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
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		if(root == q || root == p || root == nullptr) return root;
		TreeNode * left = lowestCommonAncestor(root->left,p,q);
		TreeNode * right = lowestCommonAncestor(root->right,p,q);
		if(left != nullptr && right != nullptr) return root;
		
		if(left == nullptr && right != nullptr) return right;
		else if(left != nullptr && right == nullptr) return left;
		else nullptr; 
	}
};
