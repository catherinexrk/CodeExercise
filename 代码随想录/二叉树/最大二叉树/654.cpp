#include <stdlib.h>
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;
//https://leetcode.cn/problems/maximum-binary-tree/

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
	TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
		//1.首先是获取当前的最大数
		TreeNode * root = new TreeNode(0);
		if(nums.size() == 1){
			root->val = nums[0];
			return root;
		} else if(nums.size() == 0) {
			return nullptr;
		}
		//获取当前数组最大值和对应的index
		int delimiterIndex = 0;
		for(int i = 0;i < nums.size();i++){
			if(nums[i] > nums[delimiterIndex]) delimiterIndex = i;
		}
		//此时获取到了最大值对应的角标
		root->val = nums[delimiterIndex];
		
		//2.根据最大数进行元素切割
		
		//左 [being,delimiteIndex)
		vector<int> leftMax(nums.begin(),nums.begin() + delimiterIndex);
		
		//右[delimiterIndex + 1,end)
		vector<int> rightMax(nums.begin() + delimiterIndex + 1,nums.end());
		
		//3.递归处理左右
		root->left = constructMaximumBinaryTree(leftMax);
		root->right = constructMaximumBinaryTree(rightMax);
		
		return root;
	}
};
