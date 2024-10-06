#include <stdlib.h>
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;
//https://leetcode.cn/problems/binary-tree-paths/

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
	void traversal(TreeNode* cur,vector<int>& path,vector<string>& result){
		path.push_back(cur->val);//种
		//遇到叶子节点
		if(cur->left == nullptr and cur->right == nullptr){
			string sPath;
			for(int i = 0;i < path.size() - 1;i++){
				sPath += to_string(path[i]);
				sPath += "->";
			}
			//处理最后一个叶子节点的数值
			sPath += to_string(path[path.size() - 1]);
			result.push_back(sPath);//存放一个路径
			return;
		}
		if(cur->left){
			traversal(cur->left,path,result);
			path.pop_back();//返回上一级
		}
		
		if(cur->right){
			traversal(cur->right,path,result);
			path.pop_back();
		}
		
	}
	
	vector<string> binaryTreePaths(TreeNode* root) {
		
		vector<string> result;//路径集合
		vector<int> path;
		if(root == nullptr) return result;
		
		traversal(root,path,result);
		
		return result;
	}
};
