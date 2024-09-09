#include <stdlib.h>
#include <iostream>
#include <malloc.h>

using namespace std;
//https://leetcode.cn/problems/design-linked-list/

class MyLinkedList {
public:
	//定义单链表结构
	struct ListNode{
		int val;
		ListNode * next;
		ListNode(int val):val(val),next(NULL){};
	};
	
	//链表的头结点
	ListNode * head;
	int length;//链表的长度
	
	MyLinkedList() {
		//初始化MyLinkedList对象
		head = NULL;//初始化头结点为空
		length = 0;//链表首长为0
	}
	
	int get(int index) {
		//先是判断index的合法性
		if(index < 0 || index >= length){
			return -1;
		}
		//从头开始遍历
		ListNode * temp = head;
		int cur = 0;
		while(temp != NULL){
			if(cur == index){
				return temp->val;
			}
			temp = temp->next;
			cur++;
		}
		return -1;
	}
	
	void addAtHead(int val) {
		ListNode * newNode = new ListNode(val);
		//判断头结点是否为空
		if(head == nullptr){
			head = newNode;
		} else{
			newNode->next = head;
			head = newNode;
		}
		length++;
	}
	
	void addAtTail(int val) {
//		//尾插法，将一个数值直接插入到表尾
//		//遍历链表，直到->next == nullptr
//		ListNode * before = head;
//		while(before->next != nullptr){
//			before = before->next;
//		}
//		//此时before就是队尾元素了
//		ListNode * damn = before->next;
//		damn->next = nullptr;
//		damn->val = val;
		//创建一个新结点
		ListNode * newNode = new ListNode(val);//构造函数
		if(head == nullptr){
			head = newNode;
		} else{
			ListNode * temp = head;
			while(temp->next != nullptr){
				temp = temp->next;
			}
			temp->next = newNode;
		}
		length++;
	}
	
	void addAtIndex(int index, int val) {
		//首先是判断index合法
		//index的合法区间是[0,length]可以超过length范围
		if(index < 0 || index > length){
			return;
		}
		
		if(head == nullptr || index == 0){
			addAtHead(val);
			return;
		}else{
			int flag = 0;
			ListNode * before = head;
			while(flag < index - 1 && before != nullptr){
				flag++;
				before = before->next;
			}
			//此时before已经是index前一位
			ListNode * damn = new ListNode(val);
			damn->next = before->next;
			before->next = damn;
		}
		length++;
	}
	
	void deleteAtIndex(int index) {
		//此时的区间范围是[0,length)
		if(index < 0 || index >= length){
			return;
		}
		if(index == 0){ 
			//要删除的是头结点
			ListNode * newNode = head;
			head = head->next;
			delete newNode;
			
		} else{
			int flag = 0;
			ListNode * before = head;
			while(flag < index - 1 && before != nullptr){
				flag++;
				before = before->next;
			}
			ListNode * damn = before->next;
			before->next = damn->next;
			delete damn;
		}
		
		length--;
	}

};
