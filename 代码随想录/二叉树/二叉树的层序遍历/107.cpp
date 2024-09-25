#include <stdlib.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
//https://leetcode.cn/problems/binary-tree-level-order-traversal-ii/

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
	vector<vector<int>> levelOrderBottom(TreeNode* root) {
		vector<vector<int>> result;
		queue<TreeNode *>que;
		if(root != nullptr) que.push(root);
		
		while(!que.empty()){
			vector<int> vec;
			int size = que.size();
			for(int i = 0;i < size;i++){
				TreeNode * node = que.front();
				que.pop();
				vec.push_back(node->val);
				if(node->left) que.push(node->left);
				if(node->right) que.push(node->right);
			}
			result.push_back(vec);
		}
		reverse(result.begin(),result.end());
		return result;
	}
};
