#include <stdlib.h>
#include <iostream>

using namespace std;
//https://leetcode.cn/problems/remove-nth-node-from-end-of-list/
struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		ListNode * virNode = new ListNode(0);
		virNode->next = head;
		
		//将slow和fast指向head前一个虚拟结点，因为slow最终只想要删除的前一个，当考虑到
		//要删除的结点是头结点时，便不合理
		ListNode * fast = virNode;
		ListNode * slow = virNode;
		
		for(int i = 0;i < n;i++){
			fast = fast->next;
		}
		
		while(fast != nullptr){
			fast = fast->next;
			slow = slow->next;
		}
		
		//结束的时候slow下一个便是要删除的
		ListNode * temp = slow->next;
		slow->next = temp->next;
		delete temp;
		head = virNode->next;
		delete virNode;
		return head;
	}
	
	/*
		//双指针法，一个fast 一个slow
	ListNode * fast = head;//快指针
	ListNode * slow = head;//慢指针
	int index = 0;
	while(index < n and fast != nullptr){
	fast = fast->next;
	index++;
	}
	//此时开始同时移动fast和slow
	while(fast->next != nullptr){
	fast = fast->next;
	slow = slow->next;
	}
	//此时slow下一个就是要删除的
	ListNode * temp = slow->next;
	slow->next = temp->next;
	
	//删除temp
	delete temp;
	return head;
	*/
};
