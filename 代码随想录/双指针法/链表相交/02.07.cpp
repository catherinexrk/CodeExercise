#include <string.h>
#include <iostream>
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;
//https://leetcode.cn/problems/remove-nth-node-from-end-of-list/

struct ListNode{
	int val;
	ListNode * next;
	ListNode():val(0),next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		ListNode * a = headA;
		ListNode * b = headB;
		while(a != b){
			a = (a == nullptr)? headB:a->next;
			b =(b==nullptr)? headA:b->next;
		}
		if(a == nullptr and b ==nullptr){
			return nullptr;
		} else {
			return a;
		}
	}
};

