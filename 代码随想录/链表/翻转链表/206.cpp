#include <stdlib.h>
#include <iostream>

using namespace std;
//https://leetcode.cn/problems/reverse-linked-list/


struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution1 {
public:
	ListNode* reverseList(ListNode* head) {
		//先是判断是否为空
		if(head == nullptr){
			return head;
		}
		//我的思想是，我创建一个新的链表头结点，这样每次我遍历的时候我头1插法插入到新链表中
		ListNode * newHead = nullptr;
		ListNode * temp = head;
		while(temp != nullptr){
			newHead = addAtHead(newHead,temp->val);
			temp = temp->next;
		}
		return newHead;
		
	}
	
	ListNode * addAtHead(ListNode * head,int val){
//		ListNode * newHead = new ListNode(val);
//		if(head == nullptr){
//			head = newHead;
//		} else{
//			newHead->next = head;
//			head = newHead;
//		}
//		return head;
		ListNode * newNode = new ListNode(val);
		newNode->next = head;
		head = newNode;
		return head;
	}
	
};

class Solution {
public:
	ListNode* swapPairs(ListNode* head) {
		//使用前后指针
		ListNode * pre = nullptr;//pre表示反转后的最后一个结点所指向
		ListNode * cur = head;//cur进行遍历原先链表，在此基础上进行链表的反转
		ListNode * temp = nullptr;
		while(cur){
			temp = cur->next;
			cur->next = pre;
			pre = cur;
			cur = temp;
		}
		return pre;
	}
};
