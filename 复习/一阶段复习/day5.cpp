#include <bits/stdc++.h>

using namespace std;

class Solution1{
public:
	void reverseString(vector<char>& s) {
		int head = 0,tail = s.size() - 1;
		while(head <= tail){
			char temp = s[head];
			s[head] = s[tail];
			s[tail] = temp;
			tail--;
			head++;
		}
	}
};

class Solution2 {
public:
	
	string reverseStr(string s, int k) {
		for(int i = 0;i < s.length();i += (2 * k)){
			if(i + k <= s.length()){
				reverse(s.begin() + i,s.begin() + i + k);
			} else{
				reverse(s.begin() + i,s.end());
			}
		}
	}
};
