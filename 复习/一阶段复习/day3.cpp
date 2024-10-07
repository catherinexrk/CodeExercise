#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <vector>
#include <limits.h>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;

struct ListNode{
	int val;
	ListNode * next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution1{
	//203
public:
	ListNode* removeElements(ListNode* head, int val) {
		//空节点
		if(head == nullptr) return nullptr;
		
		ListNode * virNode = new ListNode(0);
		virNode->next = head;
		
		ListNode * cur = virNode;
		while(cur!=nullptr and cur->next != nullptr){
			if(cur->next->val == val){
				ListNode * temp = cur->next;
				cur->next = temp->next;
				delete temp;
			} else{
				cur = cur->next;//指向下一个新的节点
			}
			
		}
		ListNode * newHead = virNode->next;
		delete virNode;
		return newHead;
	}
	
	
	ListNode * remove(ListNode * head,int val){
		if(head == nullptr) return nullptr;
		ListNode * virNode = new ListNode(0);
		virNode->next = head;
		
		ListNode * cur = virNode->next;
		while(cur != nullptr and cur->next != nullptr){
			if(cur->val == val){
				ListNode * temp = cur->next;
				cur->next = temp->next;
				delete temp;
			} else{
				cur = cur->next;
			}
		}
		
		ListNode * newHead = virNode->next;
		delete virNode;
		return newHead;
	}
};

class MyLinkedList {
public:
	
	struct myLink{
		int val;
		myLink * next;
		myLink(int x):val(x),next(nullptr){}
	};
	
	myLink * head;
	int length;
	
	//初始化链表
	MyLinkedList() {
		head = nullptr;
		length = 0;
	}
	
	int get(int index) {
		//index 无效
		if(index >= length || index < 0){
			return -1;
		}

		myLink * node = head;
		for(int i = 0;i < index;i++){
			node = node->next;
		}
		//此时node是目标前一位
		return node->val;
	}
	
	void addAtHead(int val) {
		myLink * virHead = new myLink(0);
		myLink * node = new myLink(val);
		virHead->next = node;
		node->next = head;
		head = node;
		delete virHead;
		length++;
	}
	
	void addAtTail(int val) {
		myLink * node = new myLink(val);
		if(head == nullptr){
			head = node;
		}else{
			myLink * temp = head;
			while(temp->next != nullptr){
				temp = temp->next;
			}
			temp->next = node;
		}
		while(node->next != nullptr){
			node = node->next;
		}
		length++;
	}
	
	void addAtIndex(int index, int val) {
		if(index < 0){
			return;
		}
		int flag = 0;
		myLink * node = head;
		while(flag < index and node != nullptr and node->next != nullptr){
			node = node->next;
			flag++;
		}
		//此时node是index前一个
		myLink * damn = node->next;
		myLink * temp = new myLink(val);
		temp->next = damn;
		node->next = temp;
		length++;
		
	}
	
	void deleteAtIndex(int index) {
		if(index >= length || index < 0){
			return;
		}
		int flag = 0;
		myLink * node = head;
		while(flag < index and node != nullptr and node->next != nullptr){
			node = node->next;
			flag++;
		}
		myLink * damn = node->next->next;
		myLink * temp = node->next;
		node->next = damn;
		delete temp;
		length--;
	}
};

class Solution2{
public:
	ListNode* reverseList(ListNode* head) {
		if(head == nullptr) return nullptr;
		ListNode * cur = head;
		ListNode * pre = nullptr;
		while(cur != nullptr){
			ListNode * temp = new ListNode(0);
			temp = cur->next;
			cur->next = pre;
			pre = cur;
			cur = temp;
		}
		return pre;
	}
};

class Solution3{
public:
	ListNode* swapPairs(ListNode* head) {
		if(head == nullptr || head->next == nullptr){
			return head;
		}
		ListNode * virNode = new ListNode(0);
		virNode->next = head;
		
		ListNode * prev = virNode;
		while(prev->next != nullptr and prev->next->next != nullptr){
			ListNode * first = prev->next;
			ListNode * second = first->next;
			
			//进行节点交换
			first->next = second->next;
			second->next = first;
			prev->next = second;
			
			prev = first;
		}
		
		head = virNode->next;
		delete virNode;
		return head;
	}
};

class Solution4{
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		ListNode * virNode = new ListNode(0);
		virNode->next = head;
		
		ListNode * fast = virNode->next;
		for(int i = 0;i < n;i++){
			fast = fast->next;
		}
		
		ListNode * slow = virNode->next;
		ListNode * pre = virNode;
		while(fast != nullptr){
			fast = fast->next;
			slow = slow->next;
			pre = pre->next;
		}
		pre->next = slow->next;
		delete slow;
		head = virNode->next;
		delete virNode;
		return head;
	}
};

class Solution5{
public:
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		ListNode * a = headA;
		ListNode * b = headB;
		while(a != b){
			a = (a == nullptr) ? headB : a->next;
			b = (b == nullptr) ? headA : b->next;
		}
		if(a == nullptr) return nullptr;
		else return a;
	}
};

class Solution6{
public:
	ListNode *detectCycle(ListNode *head) {
		if(head == nullptr) return nullptr;
		ListNode * fast = head;
		ListNode * slow = head;
		while(fast != nullptr and fast->next != nullptr and slow != nullptr){
			fast = fast->next->next;
			slow = slow->next;
			if(fast == slow){
				ListNode * cur = head;
				while(cur != fast){
					fast = fast->next;
					cur = cur->next;
				}
				return cur;
			}
		}
		return nullptr;
	}
};
