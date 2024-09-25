#include <stdlib.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
//https://leetcode.cn/problems/binary-tree-right-side-view/

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
	vector<int> rightSideView(TreeNode* root) {
		vector<int> result;
		queue<TreeNode*> que;
		if(root != nullptr) que.push(root);
		
		while(!que.empty()){
			int size = que.size();
			for(int i = 0;i < size;i++){
				TreeNode * node = que.front();
				que.pop();
				
				//只有当i为size - 1的时候，说明此时的node为最右边的
				if(i == size - 1){
					result.push_back(node->val);
				}
				if(node->left) que.push(node->left);
				if(node->right) que.push(node->right);
			}
		}
		return result;
	}
};
/**
 * 时间复杂度
 * 空间复杂度
 */

