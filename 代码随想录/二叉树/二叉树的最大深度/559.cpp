#include <stdlib.h>
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;
//https://leetcode.cn/problems/maximum-depth-of-n-ary-tree/

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
	//bfs层序遍历
	int maxDepth1(Node* root) {
		int depth = 0;
		queue<Node*> que;
		if(root != nullptr){
			que.push(root);
		}
		
		while(!que.empty()){
			int size = que.size();
			for(int i = 0;i < size;i++){
				Node * node = que.front();
				que.pop();
				for(auto temp : node->children){
					que.push(temp);
				}
			}
			depth++;
		}
		return depth;
	}
	
	
	//dfs
	int maxDepth(Node * root){
		if(root == nullptr) return 0;
		int depth = 0;
		for(auto temp : root->children){
			depth = max(depth,maxDepth(temp));
		}
		return depth + 1;
	}
	
};
