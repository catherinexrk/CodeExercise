#include <string.h>
#include <iostream>
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;
//https://leetcode.cn/problems/reverse-string/

class Solution {
public:
	void reverseString(vector<char>& s) {
		for(int head = 0,tail = s.size() - 1;head <= tail;head++,tail--){
			char temp;
			temp = s[head];
			s[head] = s[tail];
			s[tail] = temp;
		}
	}
};
