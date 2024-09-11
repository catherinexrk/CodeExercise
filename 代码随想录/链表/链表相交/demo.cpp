#include <stdlib.h>
#include <iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* getIntersectionNode(ListNode* headA, ListNode* headB){
	//首先是判断头结点是否为空，如果为空则根本没机会相交
	if(headA == nullptr || headB == nullptr){
		return nullptr;
	}
	
	ListNode * pA = headA;
	ListNode * pB = headB;
	
	while(pA != pB){
		pA = (pA == nullptr) ? headB : pA->next;//进行判断，如果pA到了nullptr，则pA开始遍历headB
		pB = (pB == nullptr) ? headA : pB->next;
		
		
	}
	//此时
	return pA;
}
