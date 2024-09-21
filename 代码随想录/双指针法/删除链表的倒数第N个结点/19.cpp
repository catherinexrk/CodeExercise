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
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		if(head == nullptr){
			return nullptr;
		}
	
		ListNode * virHead;
		virHead->next = head;
		ListNode * slow = virHead;
		ListNode * fast = virHead;
		
		//fast移动n+1步数
		for(int i = 0;i <= n;i++){
			fast = fast->next;
		}
		while(fast != nullptr){
			slow = slow->next;
			fast = fast->next;
		}
		//此时fast已经到了链表末尾，并且此时的slow下一位便是要删除的结点
		ListNode * temp = slow->next;
		slow->next = temp->next;
		delete temp;
		
		ListNode * newHead = virHead->next;
		delete	virHead;
		return newHead;
		
	}
};
