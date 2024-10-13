#include <stdlib.h>
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;
//https://leetcode.cn/problems/validate-binary-search-tree/

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
	long long maxValue = LONG_LONG_MIN;
	bool isValidBST(TreeNode* root) {
		if(root == nullptr) return true;
		
		//左
		bool left = isValidBST(root->left);
		//中
		if(root->val > maxValue){
			maxValue = root->val; 
		} else return false;	
		//右
		bool right = isValidBST(root->right);
		
		return left and right;
	}
	
	
	
};

class Solution1{
public:
	//中序遍历得到升序数组
	void Inorder(TreeNode * root,vector<int>& result){
		
		if(root != nullptr){
			Inorder(root->left,result);
			result.push_back(root->val);
			Inorder(root->right,result);
		}
	}
	bool isValidBST(TreeNode* root){
		vector<int> result;
		Inorder(root,result);
		for(int i = 1;i < result.size();i++){
			if(result[i - 1] >= result[i]) return false;
		}
		return true;
	}
};

class Solution3{
	TreeNode * pre = nullptr;//记录前一个节点
	bool isValidBST(TreeNode* root) {
		if(root == nullptr) return true;
		bool left = isValidBST(root->left);
		if(pre != nullptr && pre->val >= root->val) return false;
		
		pre = root;//前一个节点
		bool right = isValidBST(root->right);
		return left && right;
	}
};
