#include <stdlib.h>
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;
//https://leetcode.cn/problems/invert-binary-tree/

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/**
 * 我的想法是，bfs，遍历的时候左右节点进行翻转
 */

class Solution {
public:
	TreeNode* invertTree1(TreeNode* root) {
		if(root == nullptr) return root;
		/**
		 * 前序遍历 中 左 右
		 */
		swap(root->left,root->right);//中
		invertTree(root->left);//左
		invertTree(root->right);//右
		
		
		/**
		 * 后序遍历 左 右 中
		 */
//		invertTree(root->left);//左
//		invertTree(root->right);//右
//		swap(root->left,root->right);//中
		
		/**
		 * 中序遍历  左 中 右
		 * 此时通过画图可以知道不可以按照这个顺序去遍历
		 * 左 中 左 顺序遍历
		 */
//		invertTree(root->left);
//		swap(root->left,root->right);
//		invertTree(root->left);
		return root;
 	}
	
	TreeNode* invertTree(TreeNode* root){
		queue<TreeNode  * >que;
		if(root == nullptr) return root;
		else que.push(root);
		while(!que.empty()){
			int size = que.size();
			for(int i = 0;i < size;i++){
				TreeNode * node = que.front();
				que.pop();
				/**
				 * 前序 中 左 右
				 */
				swap(node->left,node->right);
				if(node->left) que.push(node->left);
				if(node->right) que.push(node->right);
			}
		}
		return root;
	}
};
