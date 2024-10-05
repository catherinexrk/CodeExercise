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
		
		if(root->left == nullptr and root->right != nullptr){
			return 1 + rightHeight;
		}
		
		if(root->left != nullptr and root->right == nullptr){
			return 1 + leftHeight;
		}
		
		int minDepth = min(leftHeight,rightHeight) + 1;
		return minDepth;
	}
	
	int demo(TreeNode* root){
		if(root == nullptr) return 0;
		int leftHeight = minDepth(root->left);
		int rightHeight = minDepth(root->right);
		int height = min(leftHeight,rightHeight) + 1;
		return height;
	}
	
	
	//bfs
	int minDepth1(TreeNode* root){
		if(root == nullptr) return 0;
		queue<TreeNode*> que;
		que.push(root);
		int depth = 1;
		while(!que.empty()){
			int size = que.size();
			for(int i = 0;i < size;i++){
				TreeNode * node = que.front();
				que.pop();
				if(node->left == nullptr and node->right == nullptr) return depth;
				if(node->left) que.push(node->left);
				if(node->right) que.push(node->right);
			}
			depth++;
		}
		return depth;
	}
};
