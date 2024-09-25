#include <stdlib.h>
#include <iostream>
#include <vector>
#include <stack>

using namespace std;
//https://leetcode.cn/problems/binary-tree-preorder-traversal/


struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/**
 * 使用栈替代递归操作
 */
class Solution {
public:
	vector<int> result;
	stack<TreeNode* > st;
	
	vector<int> preorderTraversal(TreeNode* root) {
		if(root == nullptr)
			return result;
		st.push(root);
		
		while(!st.empty()){
			TreeNode* node = st.top();
			result.push_back(node->val);//存入根节点
			st.pop();
			
			if(node->right)
				st.push(node->right);//右结点先进栈
			if(node->left)
				st.push(node->left);//左结点入栈
		}
		
		return result;
	}
};

/**
 * 时间复杂度o(n)
 * 空间复杂度o(n)
 */

