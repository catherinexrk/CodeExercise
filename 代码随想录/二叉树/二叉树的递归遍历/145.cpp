#include <stdlib.h>
#include <iostream>
#include <vector>

using namespace std;
//https://leetcode.cn/problems/binary-tree-postorder-traversal/

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
	
	vector<int> postorderTraversal(TreeNode* root) {
		if(root != nullptr){
			postorderTraversal(root->left);
			postorderTraversal(root->right);
			result.push_back(root->val);			
		}
		return result;
	}
};
