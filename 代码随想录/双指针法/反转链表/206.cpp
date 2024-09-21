#include <string.h>
#include <iostream>
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

//https://leetcode.cn/problems/reverse-linked-list/

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

struct ListNode{
	int val;
	ListNode * next;
	ListNode():val(0),next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
	ListNode* reverseList(ListNode* head) {
		//判断链表是否为空
		if(head == nullptr){
			return nullptr;
		}
		ListNode * cur = head;
		ListNode * pre = nullptr;
		ListNode * temp;//暂存结点
		while(cur != nullptr){
			temp = cur->next;
			cur->next = pre;
			pre = cur;
			cur = temp;
		}
		//结束的时候,此时cur为nullptr
		return pre;
	}
};
