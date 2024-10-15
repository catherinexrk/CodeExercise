#include <stdlib.h>
#include <iostream>
#include <string>

using namespace std;
//https://leetcode.cn/problems/trim-a-binary-search-tree/

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
	TreeNode* trimBST(TreeNode* root, int low, int high) {
		if(root == nullptr) return nullptr;
		if(root->val >= low && root->val <= high){
			return root;
		} else{
			//删除当前root
			if(root->left == nullptr && root->right == nullptr){
				delete root;
				return nullptr;
			} else if(root->left == nullptr){
				TreeNode * tmp = root->right;
				delete root;
				return tmp;
			} else if(root->right == nullptr){
				TreeNode * tmp = root->left;
				delete root;
				return tmp;
			} else{
				TreeNode * left = root->left;
				TreeNode * right = root->right;
				while(right->left){
					right = right->left;
				}
				right->left = left;
				TreeNode * tmp = root;
				root = root->right;
				delete tmp;
				return root;
			}
		}
		
		root->left = trimBST(root->left,low,high);
		root->right = trimBST(root->right,low,high);
		
		return root;
		
	}
};

class Solution2{
public:
	TreeNode* trimBST(TreeNode* root, int low, int high){
		if(root == nullptr) return nullptr;
		if(root->val < low){
			TreeNode * right = trimBST(root->right,low,high);
			return right;
		} 
		if(root->val > high){
			TreeNode * left = trimBST(root->left,low,high);
			return left;
		}
		root->left = trimBST(root->left,low,high);
		root->right = trimBST(root->right,low,high);
		return root;
	}
};
