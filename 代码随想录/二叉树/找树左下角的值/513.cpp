#include <stdlib.h>
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;
//https://leetcode.cn/problems/find-bottom-left-tree-value/

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
	int findBottomLeftValueBFS(TreeNode* root) {
		//bfs
		//bfs从右往左遍历
		queue<TreeNode*> que;
		que.push(root);
		while(!que.empty()){
			int size = que.size();
			TreeNode * node;
			for(int i = 0;i < size;i++){
				node = que.front();
				que.pop();
				if(node->right) que.push(node->right);
				if(node->left) que.push(node->left);
			}
			if(que.empty()){
				return node->val;
			}
		}
		return 0;
	}
	
	/**
	 * 最底层最左边的，及是深度最大的节点且左边的节点
	 */
	int maxDepth = INT_MIN;//全局变量 记录最大深度
	int result;//全局变量  最大深度最左节点的数值
	
	void traversal(TreeNode *root,int depth){
		//中
		if(root->left == nullptr and root->right == nullptr){
			if(depth > maxDepth){
				result = root->val;
				maxDepth = depth;
			}
		}
		
		//左
		if(root->left){
			depth++;
			traversal(root->left,depth);
			depth--;//回溯
		}
		
		//右
		if(root->right){
			depth++;
			traversal(root->right,depth);
			depth--;
		}
	}
	
	int findBottomLeftValue(TreeNode* root) {
		//dfs
		traversal(root,0);
		return result;
	}
};
