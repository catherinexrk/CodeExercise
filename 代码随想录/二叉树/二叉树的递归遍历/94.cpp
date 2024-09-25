#include <stdlib.h>
#include <iostream>
#include <vector>

using namespace std;
//https://leetcode.cn/problems/binary-tree-inorder-traversal/

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
	vector<int> result;
	
	vector<int> inorderTraversal(TreeNode* root) {
		if(root != nullptr){
			inorderTraversal(root->left);
			result.push_back(root->val);
			inorderTraversal(root->right);
		}
		return result;
	}
};
