#include <stdlib.h>
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;
//https://leetcode.cn/problems/path-sum/

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
	bool flag = false;
	void traversal(TreeNode * node,vector<int>& path,int target){
		path.push_back(node->val);
		//碰到叶子节点
		if(node->left == nullptr and node->right == nullptr){
			int sum = 0;
			for(auto temp : path){
				sum += temp;
			}
			if(sum == target) flag = true;
		}
		
		if(node->left){
			traversal(node->left,path,target);
			path.pop_back();//回溯
		}
		
		if(node->right){
			traversal(node->right,path,target);
			path.pop_back();
		}
	}
	
	bool hasPathSum(TreeNode* root, int targetSum) {
		if(root == nullptr) return false;
		vector<int> path;
		traversal(root,path,targetSum);
		return flag;
	}
};
