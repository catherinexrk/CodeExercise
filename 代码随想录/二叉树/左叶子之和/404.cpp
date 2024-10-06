#include <stdlib.h>
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;
//https://leetcode.cn/problems/sum-of-left-leaves/

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
//	int traversal(TreeNode* node){
//		int result;
//		if(node->left != nullptr and node->left->left == nullptr and node->left->right == nullptr){
//			result = node->left->val;
//		}
//		tra
//	}
	
	int sumOfLeftLeaves(TreeNode* root) {
		//左 右 中 后序遍历
		if(root == nullptr) return 0;
		
		int leftValue = sumOfLeftLeaves(root->left);
		if(root->left != nullptr and root->left->left == nullptr and root->left->right == nullptr){
			leftValue = root->left->val;
		}
		
		int rightValue = sumOfLeftLeaves(root->right);
		
		int sum = leftValue + rightValue;
		return sum;
	}
	
	int func(TreeNode * root){
		if(root == nullptr) return 0;
		int left = func(root->left);
		if(root->left != nullptr and root->left->left == nullptr and root->left->right == nullptr){
			left = root->left->val;
		}
		int right = func(root->right);
		int sum = left + right;
		return sum;
	}
	
	//bfs
	int sumOfLeftLeaves2(TreeNode* root){
		queue<TreeNode*> que;
		if(root == nullptr) return 0;
		que.push(root);
		vector<TreeNode*> vec;//存储左叶子节点
		while(!que.empty()){
			int size = que.size();
			for(int i = 0;i < size;i++){
				TreeNode * temp = que.front();
				que.pop();
				if(temp->left != nullptr && temp->left->left == nullptr && temp->left->right == nullptr){
					vec.push_back(temp->left);
				}
				
				if(temp->left) que.push(temp->left);
				if(temp->right) que.push(temp->right);
			}
		}
		int sum = 0;
		for(auto damn : vec){
			sum += damn->val;
		}
		return sum;
	}
};
