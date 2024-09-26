#include <stdlib.h>
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;
//https://leetcode.cn/problems/subtree-of-another-tree/

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
	bool compareNode(TreeNode * root,TreeNode * root2){
		if(root == nullptr and root2 == nullptr) return true;
		else if(root != nullptr and root2 == nullptr) return false;
		else if(root == nullptr and root2 != nullptr) return false;
		else if(root->val != root2->val) return false;
		
		bool leftCompare = compareNode(root->left,root2->left);
		bool rightCompare = compareNode(root->right,root2->right);
		bool result = (leftCompare && rightCompare);
		return result;
	}
	
	bool isSubtree(TreeNode* root, TreeNode* subRoot) {
		if(root == nullptr) return false;
		
		if(compareNode(root,subRoot)) return true;
		else return isSubtree(root->left,subRoot) ||isSubtree(root->right,subRoot);
	}
};
