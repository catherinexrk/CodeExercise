#include <stdlib.h>
#include <iostream>
#include <vector>

using namespace std;
//https://leetcode.cn/problems/binary-tree-preorder-traversal/


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
	
	vector<int> preorderTraversal(TreeNode* root) {
		if(root != nullptr) {
			result.push_back(root->val);
			preorderTraversal(root->left);//
			preorderTraversal(root->right);
		}
		return result;
	}
};

/**
 * 时间复杂度o(n)
 */

