#include <stdlib.h>
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;
//https://leetcode.cn/problems/same-tree/

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
	bool compareNode(TreeNode * left,TreeNode * right){
		if(left == nullptr && right == nullptr) return true;
		else if(left == nullptr && right != nullptr) return false;
		else if(left != nullptr && right == nullptr) return false;
		else if(left->val != right->val) return false;
		else{
			bool leftCompare = compareNode(left->left,right->left);
			bool rightCompare = compareNode(left->right,right->right);
			bool result = (leftCompare && rightCompare);
			return result;
		}
	}
	
	bool isSameTree(TreeNode* p, TreeNode* q) {
		return compareNode(p,q);
	}
};

