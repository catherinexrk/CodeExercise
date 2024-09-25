#include <stdlib.h>
#include <iostream>
#include <vector>
#include <stack>

using namespace std;
//https://leetcode.cn/problems/binary-tree-inorder-traversal/

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


/**
 * 中序遍历
 */
class Solution {
public:
	vector<int> result;
	stack<TreeNode*> st;
	
	vector<int> inorderTraversal(TreeNode* root) {
		TreeNode * cur = root;
		while(cur != nullptr || !st.empty()){
			if(cur != nullptr){
				st.push(cur);
				cur = cur->left;//沿着左边一直跑下去
			} else{
				cur = st.top();//此时左节点为空，进而中再到右
				st.pop();
				result.push_back(cur->val);
				cur = cur->right;//开始从右节点开始跑
			}
		}
		return result;
	}
};
