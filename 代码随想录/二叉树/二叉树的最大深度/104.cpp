#include <stdlib.h>
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;
//https://leetcode.cn/problems/maximum-depth-of-binary-tree/

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

//bfs层序遍历 
class Solution1 {
public:
	int maxDepth(TreeNode* root) {
		//bfs
		queue<TreeNode*> que;
		int depth = 0;
		if(root != nullptr) depth++;
		que.push(root);
		
		while(!que.empty()){
			int size = que.size();
			depth++;
			for(int i = 0;i < size;i++){
				TreeNode * node = que.front();
				que.pop();
				if(node->left) que.push(node->left);
				if(node->right) que.push(node->right);
			}
		}
		return depth;
	}
};

//dfs 深入图或树的分支，直到不能再深入再回溯
class Solution {
public:
	int maxDepth1(TreeNode* root) {
		if(root == nullptr) return 0;
		//后序遍历
		int leftHeight = maxDepth(root->left);
		int rightHeight = maxDepth(root->right);
		int depth = 1 + max(leftHeight,rightHeight);
		return depth;
	}
};
