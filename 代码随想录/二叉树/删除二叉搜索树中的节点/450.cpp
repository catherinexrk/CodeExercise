#include <stdlib.h>
#include <iostream>
#include <string>

using namespace std;
//https://leetcode.cn/problems/delete-node-in-a-bst/

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
	TreeNode* deleteNode(TreeNode* root, int key) {
		//1.没找到删除的节点，遍历到空节点直接返回
		if(root == nullptr) return root;
		
		//找到了要删除的节点
		if(root->val == key){
		//2.左右孩子为空，直接删除节点，返回null为根节点
			if(root->left == nullptr && root->right == nullptr){
				delete root;
				return nullptr;
			}
		
		//3.删除节点的左孩子为空，右孩子不为空，删除节点，右孩子补位，返回右孩子
			if(root->left == nullptr && root->right != nullptr){
				TreeNode * tmp = root->right;
				delete root;
				return tmp;
			}
		
		//4.删除节点的右孩子为空，左孩子不为空，删除节点，左孩子补位，返回左孩子
			if(root->left != nullptr && root->right == nullptr){
				TreeNode * tmp = root->left;
				delete root;
				return tmp;
			}
			
		//5.左右孩子都不为空，将删除节点的左子树头节点放到删除节点的右子树的最左边节点的孩子上
		//返回删除节点右孩子为新的根节点
			if(root->left != nullptr && root->right != nullptr){
				TreeNode * rootLeft = root->left;//左子树头节点
				TreeNode * rootRight = root->right;
				while(rootRight->left != nullptr){
					rootRight = rootRight->left;
				}
				//此时rootRight为右子树的最左节点
				rootRight->left = rootLeft;root;
				TreeNode * tmp = root;
				root = root->right;
				delete tmp;
				return root;
			}
		}
		
		if(root->val > key) root->left = deleteNode(root->left,key);
		if(root->val < key) root->right = deleteNode(root->right,key);
		
		return root;
	}
};


class Solution2{
public:
	TreeNode* deleteNode(TreeNode* root, int key){
		if(root == nullptr) return root;
		if(root->val == key){
			if(root->right == nullptr){
				return root->left;
			}
			
			TreeNode * cur = root->right;
			while(cur->left){
				cur = cur->left;
			}
			swap(root->val,cur->val);
		}
		
		root->left = deleteNode(root->left,key);
		root->right = deleteNode(root->right,key);
		
		return root;
	}
};

