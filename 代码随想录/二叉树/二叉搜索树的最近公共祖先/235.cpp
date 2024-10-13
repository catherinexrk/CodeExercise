#include <stdlib.h>
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;
//https://leetcode.cn/problems/lowest-common-ancestor-of-a-binary-search-tree/

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
		//终止条件
		if(root == nullptr) return root;
		
		//左
		if(root->val > p->val && root->val > q->val){
			TreeNode* left = lowestCommonAncestor(root->left,p,q);
			if(left != nullptr){
				return left;
			}
		}
		
		//右
		if(root->val < p->val && root->val < q->val){
			TreeNode * right = lowestCommonAncestor(root->right,p,q);
			if(right != nullptr) {
				return right;
			}
		}
		
		return root;
		
	}
};
