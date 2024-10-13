#include <stdlib.h>
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;
//https://leetcode.cn/problems/merge-two-binary-trees/

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
	TreeNode* mergeTrees1(TreeNode* root1, TreeNode* root2) {
		//特殊情况
		if(root1 == nullptr) return root2;
		if(root2 == nullptr) return root1;
		
		//中左右
		root1->val += root2->val;
		
		//左
		root1->left = mergeTrees1(root1->left,root2->left);
		
		//右
		root1->right = mergeTrees1(root1->right,root2->right);
		
		return root1;
	}
	
	TreeNode* func(TreeNode * root1,TreeNode* root2){
		if(root1 == nullptr ) return root2;
		if(root2 == nullptr) return root1;
		
		root1->val += root2->val;
		root1->left = func(root1->left,root2->left);
		root1->right = func(root1->right,root2->right);
		
		return root1;
	}
	
	TreeNode* mergeTreesBFS(TreeNode* root1, TreeNode* root2){
		queue<TreeNode*> que;
		if(root1 == nullptr) return root2;
		if(root2 == nullptr) return root1;
		que.push(root1);
		que.push(root2);
		while(!que.empty()){
			TreeNode * node1 = que.front();que.pop();
			TreeNode * node2 = que.front();que.pop();
			node1->val += node2->val;
			
			//两棵树的左节点不为空
			if(node1->left != nullptr and node2->left != nullptr){
				que.push(node1->left);
				que.push(node2->left);
			}
			
			//右节点不为空
			if(node1->right != nullptr and node2->right != nullptr){
				que.push(node1->right);
				que.push(node2->right);
			}
			
			//node1左节点为空，t2不为空
			if(node1->left == nullptr and node2->left != nullptr){
				node1->left = node2->left;
			}
			
			//node1右节点为空，t2不为空
			if(node1->right == nullptr and node2->right != nullptr){
				node1->right = node2->right;
			}
			
		}
		return root1;
	}
	
	TreeNode * mergeTrees(TreeNode* root1,TreeNode* root2){
		queue<TreeNode*> que;
		if(root1 == nullptr) return root2;
		if(root2 == nullptr) return root1;
		que.push(root1);
		que.push(root2);
		while(!que.empty()){
			TreeNode* node1 = que.front();
			que.pop();
			TreeNode* node2 = que.front();
			que.pop();
			
			node1->val += node2->val;
		
			if(node1->left != nullptr and node2->left != nullptr){
				que.push(node1->left);
				que.push(node2->left);
			}
			
			if(node1->right != nullptr and node2->right != nullptr){
				que.push(node1->right);
				que.push(node2->right);
			}
			
			if(node1->left == nullptr and node2->left){
				node1->left = node2->left;
			}
			
			if(node1->right == nullptr and node2->right != nullptr){
				node1->right = node2->right;
			}
		}
		
		return root1;
	}
};
