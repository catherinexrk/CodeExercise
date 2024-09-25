#include <stdlib.h>
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;
//https://leetcode.cn/problems/binary-tree-postorder-traversal/

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/**
 * 采用后序遍历
 */
class Solution {
public:
	vector<int> result;
	stack<TreeNode* > st;
	
	vector<int> postorderTraversal(TreeNode* root) {
		if(root == nullptr)
			return result;
		st.push(root);
		while(!st.empty()){
			TreeNode * node = st.top();
			st.pop();
			result.push_back(node->val);
			if(node->left) st.push(node->left);
			if(node->right) st.push(node->right);
		}
		reverse(result.begin(),result.end());
		return result;
	}
};
