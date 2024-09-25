#include <stdlib.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

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
	int minDepth(TreeNode* root) {
		queue<TreeNode *> que;
		int min_depth = 0;
		if(root != nullptr) {
			que.push(root);
			min_depth = 1;
		}
		
		
		while(!que.empty()){
			int size = que.size();
			for(int i = 0;i < size;i++){
				TreeNode * node = que.front();
				que.pop();
				if(node->right == nullptr && node->left == nullptr){
					return min_depth;
				}
				if(node->left) que.push(node->left);
				if(node->right) que.push(node->right);
			}
			min_depth++;
		}
		return min_depth;
	}
};
