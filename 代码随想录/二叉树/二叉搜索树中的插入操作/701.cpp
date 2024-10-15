#include <stdlib.h>
#include <iostream>
#include <string>

using namespace std;
//https://leetcode.cn/problems/insert-into-a-binary-search-tree/

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
	TreeNode* insertIntoBST(TreeNode* root, int val) {
		//终止代码
		if(root == nullptr){
			TreeNode * node = new TreeNode(val);
			return node;
		}
		if(root->val > val){
			root->left = insertIntoBST(root->left,val);
		}
		
		if(root->val < val){
			root->right = insertIntoBST(root->right,val);
		}
		
		return root;
	}
};

class Solution2{
public:
	TreeNode * parent;
	void traversal(TreeNode * cur,int val){
		if(cur == nullptr){
			TreeNode * node = new TreeNode(val);
			if(val > parent->val) parent->right = node;
			if(val < parent->val) parent->left = node;
			return;
		}
		
		parent = cur;
		if(cur->val > val) traversal(cur->left,val);
		if(cur->val < val) traversal(cur->right,val);
		return;
	}
	
	TreeNode* insertIntoBST(TreeNode* root, int val){
		parent = new TreeNode(0);
		if(root == nullptr){
			root = new TreeNode(val);
		}
		traversal(root,val);
		return root;
	}
};

