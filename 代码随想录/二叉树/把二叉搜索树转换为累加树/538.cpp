#include <stdlib.h>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
//https://leetcode.cn/problems/convert-bst-to-greater-tree/

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
	int pre = 0;
	void traversal(TreeNode * cur){
		if(cur == nullptr) return;
		
		traversal(cur->right);//右
		cur->val += pre;
		pre = cur->val;
		
		traversal(cur->left);//左
	}
	
	TreeNode* convertBST(TreeNode* root) {
		pre = 0;
		traversal(root);
		return root;
	}
};

class Solution2{
public:
	
	int pre = 0;
	void traversal(TreeNode * node){
		if(node == nullptr) return;
		
		traversal(node->right);
		node->val += pre;
		pre = node->val;
		
		traversal(node->left);
	}
	
	TreeNode* convertBST(TreeNode* root){
		traversal(root);
		return root;
	}
};
