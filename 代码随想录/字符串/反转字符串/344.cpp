#include <string.h>
#include <iostream>
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <algorithm>

using namespace std;
//https://leetcode.cn/problems/reverse-string/

class Solution1 {
public:
	void reverseString(vector<char>& s) {
		reverse(s.begin(),s.end());
		for(auto damn : s){
			cout<<damn;
		}
	}
};

class Solution {
public:
//	void reverseString(vector<char>& s) {
//		for(int i = 0,j = s.size() - i - 1;i < s.size();i++,j--){
//			if(i != j){
//				char damn = s[i];
//				s[i] = s[j];
//				s[j] = damn;
//			} else{
//				break;
//			}
//		}		
//		for(auto damn : s){
//			cout<<damn;
//		}
//	}
	void reverseString(vector<char>& s){
		int left = 0;
		int right = s.size() - 1;
		while(left < right){
			char temp = s[left];
			s[left] = s[right];
			s[right] = temp;
			left++;
			right--;
		}
		for(char damn : s){
			cout<<damn;
		}
	}
};
