#include <iostream>
#include <stdlib.h>

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

struct ListNode{
	int val;
	ListNode * next;
	ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
	ListNode *detectCycle(ListNode *head) {
		//fast slow   fast速度是slow的两倍
		ListNode * fast = head;
		ListNode * slow = head;
		//fast比slow快两倍
		while (fast != nullptr and fast->next != nullptr and slow != nullptr){
			fast = fast->next->next;
			slow = slow->next;
			if(fast == slow){
				ListNode * index1 = fast;
				ListNode * index2 = head;
				while(index1 != index2){
					index1 = index1->next;
					index2 = index2->next;
				}
				return index2;
			}
		}
		return nullptr;
	}
};
