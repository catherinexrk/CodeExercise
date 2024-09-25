#include <stdlib.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
//https://leetcode.cn/problems/find-largest-value-in-each-tree-row/

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
	int findMax(vector<int> vec){
		int max;
		if(vec.size() != 0){
			max = vec[0];
			for(auto temp:vec){
				max = (max > temp) ? max : temp;
			}
		}
		return max;
	}
	
	vector<int> largestValues(TreeNode* root) {
		vector<int> result;
		queue<TreeNode* > que;
		if(root != nullptr) que.push(root);
		
		while(!que.empty()){
			int size = que.size();
			vector<int> arr;
			for(int i = 0;i < size;i++){
				TreeNode * node = que.front();
				que.pop();
				arr.push_back(node->val);
				if(node->left) que.push(node->left);
				if(node->right) que.push(node->right);
			}
			int max = findMax(arr);
			result.push_back(max);
		}
		return result;
	}
};

/**
 * 时间复杂度 o(n)
 * 空间复杂度 o(n)
 */
