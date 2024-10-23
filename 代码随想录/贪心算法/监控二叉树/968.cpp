#include <stdlib.h>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <list>

using namespace std;
//https://leetcode.cn/problems/binary-tree-cameras/

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
	int traversal(TreeNode * cur){
		//终止条件
		if(cur == nullptr) 
			return 0;
		
		int left = traversal(cur->left);
		int right = traversal(cur->right);
		
		
		
	}
	
	int minCameraCover(TreeNode* root) {
		/**
		 * 将摄像头放在子节点上，不可以放在叶子节点上
		 */
	}
};
