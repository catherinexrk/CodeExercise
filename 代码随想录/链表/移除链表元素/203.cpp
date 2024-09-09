#include <stdlib.h>
#include <iostream>
#include <malloc.h>

using namespace std;

//https://leetcode.cn/problems/remove-linked-list-elements/description/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

//Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:
//	ListNode* removeElements(ListNode* head, int val) {
//		ListNode * before = head->next;
//		while(before->next != NULL){
//			ListNode * temp = before->next;
//			if(temp->val == val){
//				ListNode * after =(ListNode *)malloc(sizeof(ListNode));
//				after->val = temp->val;
//				after->next = temp->next;
//			}
//			before = temp->next;
//			free(temp);
//		}
//		return head;
//	}
	//头结点
	ListNode* removeElements1(ListNode* head, int val){
		//首先判断头结点的数值是否为val并且头结点不为null
		while(head != NULL && head->val == val){
			ListNode * temp = head;
			head = temp->next;
			delete temp;
		}
		//此时的头结点不为null并且其val != val
		ListNode * cur = head;
		while(cur != NULL && cur->next !=NULL){
			//此时的head还是cur
			//判断cur->next即可
			if(cur->next->val == val){
				ListNode * temp = cur->next;
				cur->next = cur->next->next;
				delete temp;
			} else{
				cur = cur->next;
			}
		}
		return head;
	}
	//虚拟头指针
	ListNode* removeElements(ListNode* head, int val){
		ListNode * virHead = new ListNode();
		virHead->next = head;
		ListNode * cur = virHead;
		while(cur->next != nullptr){
			if(cur->next->val == val){
				ListNode * temp = cur->next->next;
				cur->next = temp->next;
				delete temp;
			} else{
				cur = cur->next;
			}
		}
		
		return head;
	}
		
};
