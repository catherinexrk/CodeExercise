#include <stdlib.h>
#include <iostream>

using namespace std;
//https://leetcode.cn/problems/swap-nodes-in-pairs/
struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution1 {
public:
	ListNode* swapPairs(ListNode* head) {
		if(head == nullptr || head->next == nullptr){
			return head;
		}
		ListNode * before = head;
		ListNode * after = head->next;
		while(before != nullptr and after != nullptr){
			int damn;
			damn = before->val;
			before->val = after->val;
			after->val = damn;
			
			before = after->next;
			if(before != nullptr){
				after = before->next;
			} else{
				after = nullptr;
			}
		}
		
		return head;
	}
};

class Solution2 {
public:
	ListNode* swapPairs(ListNode* head) {
		//先判断链表满不满足两位起步的容量
		if(head == nullptr || head->next == nullptr){
			return head;
		}
		//使用虚拟头指针
		ListNode * virNode = new ListNode(0);
		virNode->next = head;//virNode是虚拟指针
		ListNode * before = head;
		ListNode * after = before->next;
		
		ListNode * temp = virNode;
		//此时形成了virNode->before->after
		
		while(before != nullptr and after != nullptr){
			//开始交换结点
			before->next = after->next;
			after->next = before;
			temp->next = after;
			
			//交换完毕
			//开始下一轮赋值变换
			before = before->next;
			if(before != nullptr){
				after = before->next;
			} else{
				after = nullptr;
			}
			temp = temp->next->next;
		}
		head = virNode->next;
		delete virNode;
		return head;
		
	}
};

class Solution {
public:
	ListNode* swapPairs(ListNode* head) {
		//先判断链表满不满足两位起步的容量
		if(head == nullptr || head->next == nullptr){
			return head;
		}
		ListNode * virNode = new ListNode(0);
		virNode->next = head;//virNode是虚拟指针
		
		ListNode * prev = virNode;
		while(prev->next != nullptr and prev->next->next != nullptr){
			ListNode *first = prev->next;  // 要交换的第一个节点
			ListNode *second = first->next;  // 要交换的第二个节点
			
			// 进行节点交换
			first->next = second->next;
			second->next = first;
			prev->next = second;
			
			prev = first;//prev直接跳两格
		}
		
		head = virNode->next;
		delete virNode;
		return head;
	}
};
