#include <stdlib.h>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
//https://leetcode.cn/problems/convert-sorted-array-to-binary-search-tree/

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
	TreeNode* sortedArrayToBST(vector<int>& nums){
		TreeNode * root = traversal(nums,0,nums.size() - 1);
		return root;
	}
	
	//[left,right]
	TreeNode * traversal(vector<int> &nums,int left,int right){
		if(left > right) return nullptr;
		
		int mid = left + (right - left) / 2;
		TreeNode * root = new TreeNode(nums[mid]);
		
		root->left = traversal(nums,left,mid);
		root->right = traversal(nums,mid + 1,right);
		
		return root;
	}
};

class Solution2{
public:
	TreeNode* sortedArrayToBST(vector<int>& nums){
		return traversal(nums,0,nums.size() - 1);
	}

	TreeNode * traversal(vector<int> &nums,int left,int right){
		if(left > right) return nullptr;
		int mid = left + (right - left) / 2;
		
		TreeNode * root = new TreeNode(nums[mid]);
		
		root->left = traversal(nums,left,mid);
		root->right = traversal(nums,mid + 1,right);
		
		return root;
	}
};

class Solution3{
	TreeNode* sortedArrayToBST(vector<int>& nums) {
		return traversal(nums, 0, nums.size() - 1);
	}
	
	TreeNode* traversal(vector<int>& nums, int left, int right) {
		if (left > right) return nullptr;
		
		int mid = left + (right - left) / 2;
		TreeNode* root = new TreeNode(nums[mid]);
		
		root->left = traversal(nums, left, mid - 1);
		root->right = traversal(nums, mid + 1, right);
		
		return root;
	}
};
