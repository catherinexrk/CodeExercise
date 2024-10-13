#include <stdlib.h>
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;
//https://leetcode.cn/problems/minimum-absolute-difference-in-bst/

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
	int getMinimumDifference(TreeNode* root) {
		vector<int> result;
		inorder(root,result);
		int min = INT_MAX;
		if(result.size() == 1) return INT_MAX;
		for(int i = 1;i < result.size();i++){
			int temp = abs(result[i] - result[i - 1]);
			min = (min > temp) ? temp : min;
		}
		return min;
	}
	
	void inorder(TreeNode * root,vector<int> & result){
		if(root != nullptr){
			inorder(root->left,result);
			result.push_back(root->val);
			inorder(root->right,result);
		}
	}
};

class Solution2{
public:
	int getMinimumDifference(TreeNode * root){
		vector<int> result;
		inorder(root,result);
		if(result.size() == 1) return INT_MAX;
		int min = INT_MAX;
		for(int i = 0;i < result.size();i++){
			int temp = abs(result[i] - result[i - 1]);
			min = min(min,temp);
		}
		return min;
	}
	
	void inorder(TreeNode * root,vector<int> &result){
		if(root != nullptr){
			inorder(root->left,result);
			result.push_back(root->val);
			inorder(root->right,result);
		}
	}
};

class Solution1{
public:
	int result = INT_MAX;
	TreeNode * pre = nullptr; //保存上一个节点
	void traversal(TreeNode * cur){
		if(cur == nullptr) return;
		traversal(cur->left);//左
		if(pre != nullptr){
			result = min(result,cur->val - pre->val);
		}
		pre = cur;
		traversal(cur->right);//右
	}
	
	int getMinimumDifference(TreeNode* root){
		traversal(root);
		return result;
	}
};
