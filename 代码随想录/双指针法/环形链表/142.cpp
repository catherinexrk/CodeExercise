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
		
		
	}
};
