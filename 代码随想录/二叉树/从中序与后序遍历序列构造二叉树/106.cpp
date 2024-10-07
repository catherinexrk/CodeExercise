#include <stdlib.h>
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;
//https://leetcode.cn/problems/construct-binary-tree-from-inorder-and-postorder-traversal/

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
	TreeNode * traversal(vector<int>inorder,vector<int>& postorder){
		//1.如果数组大小为0，为空节点
		if(postorder.size() == 0) return nullptr;
		
		//2.如果非空，取后序数组最后一个元素作为节点元素
		int rootValue = postorder[postorder.size() - 1];
		TreeNode * root = new TreeNode(rootValue);
		
		//后序数组只有一个，此时则为一个根节点
		if(postorder.size() == 1) return root;
		
		//3.找到后序数组最后一个元素所在中序数组的位置，作为切割点
		int index;
		for(int i = 0;i < inorder.size();i++){
			if(inorder[i] == rootValue){
				index = i;
				break;
			}
		}
		
		//4.切割中序数组，切成中序左数组和中序右数组
		//找到中序遍历的切割点
		int delimiterIndex;
		for(delimiterIndex = 0;delimiterIndex < inorder.size();delimiterIndex++){
			if(inorder[delimiterIndex] == rootValue)
				break;
		}
		
		//[0,delimiterIndex)
		vector<int> leftInorder(inorder.begin(),inorder.begin() + delimiterIndex );
		//[delimiterIndex + 1,end)
		vector<int> rightInorder(inorder.begin() + delimiterIndex + 1,inorder.end());
		
		//5.切割后序数组，切成后序左数组和后序右数组
		
		//postOrder舍弃末尾元素 因为这个元素是中间节点 已经用过了
		postorder.resize(postorder.size() - 1);
		
		//左闭右开 [0,leftInorder.s.size)
		vector<int> leftPoster(postorder.begin(),postorder.begin() + leftInorder.size());
		//[leftInorder.size + 1,end)
		vector<int> rightPoster(postorder.begin() + leftInorder.size(),postorder.end());
		
		//6.递归处理左区间和右区间
		root->left = traversal(leftInorder,leftPoster);
		root->right = traversal(rightInorder,rightPoster);
		return root;
	}
	
	TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
		if(inorder.size() == 0 || postorder.size() == 0) return nullptr;
		return traversal(inorder,postorder);
	}
};

