#include <stdlib.h>
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;
//https://leetcode.cn/problems/balanced-binary-tree/

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
	int getHeight(TreeNode * node){
		//比较左右子树的高度差
		if(node == nullptr) return 0;
		int left = getHeight(node->left);
		if(left == -1) return -1;
		int right = getHeight(node->right);
		if(right == -1) return -1;
		
		int result;
		if(abs(left - right) > 1) result = -1;
		else result = max(left,right) + 1;
		return result;
	}
	
	bool isBalanced(TreeNode* root) {
		return getHeight(root) == -1 ? false : true;
	}
};

