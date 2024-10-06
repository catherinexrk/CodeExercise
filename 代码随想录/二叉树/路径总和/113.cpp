#include <stdlib.h>
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;
//https://leetcode.cn/problems/path-sum-ii/

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
	
	void traversal(TreeNode * node,vector<int>& path,vector<vector<int>>& result,int target){
s		path.push_back(node->val);
		if(node->left == nullptr and node->right == nullptr){
			int sum = 0;
			for(auto temp : path){
				sum += temp;
			}
			if(sum == target) result.push_back(path);
		}
		
		if(node->left){
			traversal(node->left,path,result,target);
			path.pop_back();//回溯到当前
		}
		
		if(node->right){
			traversal(node->right,path,result,target);
			path.pop_back();
		}
		
	}
	
	vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
		if(root == nullptr) return vector<vector<int>>();
		vector<vector<int>> result;
		vector<int> path;
		traversal(root,path,result,targetSum);
		return result;
		
	}
};
