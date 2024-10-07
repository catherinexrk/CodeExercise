#include <stdlib.h>
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;
//https://leetcode.cn/problems/construct-binary-tree-from-preorder-and-inorder-traversal/

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
	TreeNode * traversal(vector<int>& preorder, vector<int>& inorder){
		//1.如果为空，返回null
		if(preorder.size() == 0) return nullptr;
		
		//2.不为空，读取数值，为根节点
		int rootValue = preorder.front();
		TreeNode * root = new TreeNode(rootValue);
		//如果中序数组长度为1，直接返回root
		if(inorder.size() == 1) return root;
		
		//3.找到中序的分割点
		int delimiter;
		for(delimiter = 0;delimiter < inorder.size();delimiter++){
			if(inorder[delimiter] == rootValue) break;
		}
		
		//4.切割中序 
		//中左[begin.delimiter)
		vector<int> leftInorder(inorder.begin(),inorder.begin() + delimiter);
		
		//中右[begin + delimiter + 1,end)
		vector<int> rightInorder(inorder.begin() + delimiter + 1,inorder.end());
		
		//5.切割前序
		//首先得知道第一个位置肯定是根节点，得去除
		//[begin + 1,leftInorder.size + begin + 1)
		vector<int> leftPreorder(preorder.begin() + 1,preorder.begin() + 1 + leftInorder.size());
		
		//[leftInorder + being + 1,end)
		vector<int> rightPreorder(preorder.begin() + 1 + leftInorder.size() + 1,preorder.end());
		
		//6.递归操作
		root->left = traversal(leftPreorder,leftInorder);
		root->right = traversal(rightPreorder,rightInorder);
		return root;
	}
	
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		if(preorder.size() == 0 || inorder.size() == 0) return nullptr;
		return traversal(preorder,inorder);
	}
};
