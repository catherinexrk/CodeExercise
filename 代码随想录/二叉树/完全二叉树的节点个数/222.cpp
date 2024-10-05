#include <stdlib.h>
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;
//https://leetcode.cn/problems/count-complete-tree-nodes/

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
	//bfs
	int countNodesBFS(TreeNode* root) {
		if(root == nullptr) return 0;
		queue<TreeNode*> que;
		que.push(root);
		int sum = 0;
		while(!que.empty()){
			int size  = que.size();
			for(int i = 0;i < size;i++){
				auto node = que.front();
				que.pop();
				sum++;
				if(node->left) que.push(node->left);
				if(node->right) que.push(node->right);
			}
		}
		return sum;
	}
	
	//dfs
	int countNodes(TreeNode* root){
		if(root == nullptr) return 0;
		int leftSum = countNodes(root->left);
		int rightSum = countNodes(root->right);
		int totalSum = (leftSum + rightSum) + 1;
		return totalSum;
	}
	/**
	 * 时间复杂度o(n)
	 * 空间复杂度 取决于递归时的深度，最坏情况是o(n) 最优情况是平衡二叉树o(logn)
	 */
};
