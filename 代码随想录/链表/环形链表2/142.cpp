#include <stdlib.h>
#include <iostream>

using namespace std;
//https://leetcode.cn/problems/linked-list-cycle-ii/description/

struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
	ListNode *detectCycle(ListNode *head) {
		//使用快慢指针
		ListNode * fast = head;
		ListNode * slow = head;
		while(fast != nullptr and fast->next != nullptr ){
			slow = slow->next;
			fast = fast->next->next;
			
			if(fast == slow){
				//说明有环
				ListNode * entry = head;
				while(entry != slow){
					entry = entry->next;
					slow = slow->next;
				}
				return entry;
			}
		}
		return nullptr;
	}
};
