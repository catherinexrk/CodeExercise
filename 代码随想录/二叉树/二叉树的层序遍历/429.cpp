#include <stdlib.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
//https://leetcode.cn/problems/n-ary-tree-level-order-traversal/

class Node {
public:
	int val;
	vector<Node*> children;
	
	Node() {}
	
	Node(int _val) {
		val = _val;
	}
	
	Node(int _val, vector<Node*> _children) {
		val = _val;
		children = _children;
	}
};

class Solution {
public:
	vector<vector<int>> levelOrder(Node* root) {
		//null来分隔
		vector<vector<int>> result;
		queue<Node*> que;
		if(root != nullptr){
			que.push(root);
		}
		while(!que.empty()){
			int size = que.size();
			vector<int> cal;
			for(int i = 0;i < size;i++){
				Node* node = que.front();
				que.pop();
				cal.push_back(node->val);
				//直接遍历子节点
				for(auto temp : node->children){
					que.push(temp);
				}
			}
			result.push_back(cal);
		}
		return result;
	}
};
/**
 * 时间复杂度o(n) 每一个节点都会被遍历，n为树的节点树 
 * 空间复杂度o(n) 最坏情况下，队列que中保存一整层的节点
 */
