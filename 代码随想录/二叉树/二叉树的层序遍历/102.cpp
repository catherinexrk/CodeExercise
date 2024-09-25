#include <stdlib.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
//https://leetcode.cn/problems/binary-tree-level-order-traversal/

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
	vector<vector<int>> levelOrder(TreeNode* root) {
		queue <TreeNode*> que;
		if(root != nullptr) que.push(root);
		vector<vector<int>> result;
		while(!que.empty()){
			int size = que.size();
			vector<int> vec;//保存每层的数据
			for(int i = 0;i < size;i++){
				TreeNode * node = que.front();
				que.pop();
				vec.push_back(node->val);
				if(node->left) que.push(node->left);//当前层遍历完，塞入下层结点
				if(node->right) que.push(node->right);
			}
			result.push_back(vec);
		}
		return result;
 	}
};

class Solution1{
public:
	vector<vector<int>> levelOrder(TreeNode* root){
		queue<TreeNode*> que;//保存每层结点
		vector<vector<int>> result;//保存每层结果
		if(root != nullptr) que.push(root);
		
		while(!que.empty()){
			int size = que.size();
			vector<int> vec;//保存每层结点对应的数值
			for(int i = 0;i < size;i++){
				//遍历同一层的每一个结点
				TreeNode * node = que.front();
				que.pop();
				vec.push_back(node->val);
				if(node->left) que.push(node->left);
				if(node->right) que.push(node->right);
				
			}
			result.push_back(vec);
		}
		return result;
	}
};
/**
 * 时间复杂度
 * 空间复杂度
 */
