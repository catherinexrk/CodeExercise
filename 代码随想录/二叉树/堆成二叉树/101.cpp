#include <stdlib.h>
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;
//https://leetcode.cn/problems/symmetric-tree/

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution1 {
public:
	bool compareNode(TreeNode* left,TreeNode* right){
		//讨论左右的全部情况，包括左右节点的存在性、存储数值的一致性
		if(left == nullptr && right != nullptr) return false;
		else if(left != nullptr && right == nullptr) return false;
		else if(left == nullptr && right == nullptr) return true;
		//排除所有空节点情况
		//排除了所有空节点的情况，再排除数值相等的情况
		else if(left->val != right->val) return false;
		else{
			bool leftCompare = compareNode(left->left,right->right);//最左侧和最右侧
			bool rightCompare = compareNode(left->right,right->left);//
			bool result = (leftCompare && rightCompare);
			return result;
		}
	}
	
	bool isSymmetric(TreeNode* root) {
		if(root == nullptr) return true;
		return compareNode(root->left,root->right);
	}
};
/**
 * 时间复杂度o(n) 每个节点都会被访问到
 * 空间复杂度o() 
 */

class Solution {
public:
	//迭代法
	bool isSymmetric(TreeNode* root) {
		queue<TreeNode*> que;
		if(root == nullptr) return true;
		que.push(root->left);
		que.push(root->right);
		
		while(!que.empty()){
			auto ledtNode = que.front();
			que.pop();
			auto rightNode = que.front();
			que.pop();
			
			//此时判断条件
			//1.左右节点均为空，满足对称条件
			if(ledtNode == nullptr && rightNode == nullptr) continue;
		
			//2.讨论不符合的条件
			/**
			 * 1.null  full
			 * 2.full null
			 * 3.val != val
			 */
			if((ledtNode == nullptr && rightNode != nullptr) ||
				(ledtNode != nullptr && rightNode == nullptr) ||
				(ledtNode->val != rightNode->val)) return false;
			
			//剩下的便是满足条件，接着对其下面的节点进行检查
			que.push(ledtNode->left);
			que.push(rightNode->right);
			que.push(ledtNode->right);
			que.push(rightNode->left);
		}
		return true;
	}
};
