#include <string.h>
#include <iostream>
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <algorithm>

using namespace std;
//https://leetcode.cn/problems/reverse-string-ii/

class Solution {
public:
	string reverseStr(string s, int k) {
		int sLen = s.length();
		
		for(int i = 0;i < s.length();i += 2 * k){
			//从每一个i位置开始算起
			if(i + k <= sLen){
				reverse(s.begin() + i,s.begin() + i + k);
			} else{
				reverse(s.begin() + i,s.end());
			}
		}
		return s;
	}
};
