#include <stdlib.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
//https://leetcode.cn/problems/populating-next-right-pointers-in-each-node-ii/

struct Node {
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
		if(root != nullptr) que.push(root);
		
		while(!que.empty()){
			
			int size = que.size();
			
			for(int i = 0;i < size;i++){
				Node * temp = que.front();
				que.pop();
				if(i == size - 1){
					temp->next = nullptr;
				} else if(i != size - 1 && que.front() != nullptr){
					temp->next = que.front();
				}
				
				if(temp->left) que.push(temp->left);
				if(temp->right) que.push(temp->right);
			}
		}
		
		return root;
	}
};
