#include <stdlib.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
//https://leetcode.cn/problems/populating-next-right-pointers-in-each-node/

class Node {
public:
	int val;
	Node* left;
	Node* right;
	Node* next;
	
	Node() : val(0), left(NULL), right(NULL), next(NULL) {}
	
	Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}
	
	Node(int _val, Node* _left, Node* _right, Node* _next)
	: val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
	Node* connect(Node* root) {
		queue<Node*> que;
		if(root != nullptr){
			que.push(root);
		}
		while(!que.empty()){
			int size = que.size();
			for(int i = 0;i < size;i++){
				Node* node = que.front();
				que.pop();
				//保证node的next指向同层的右边，并且当前的node不是同层的最后一个节点
				if(que.front() != nullptr && i != size - 1){
					node->next = que.front();
				}
				//当前node是同层最后一个节点
				if(i == size - 1){
					node->next = nullptr;
				}
				if(node->left) que.push(node->left);
				if(node->right) que.push(node->right);
			}
		}
		
		return root;
	}
};
