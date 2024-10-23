#include <stdlib.h>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <list>

using namespace std;
//https://leetcode.cn/problems/monotone-increasing-digits/

class Solution {
public:
	int monotoneIncreasingDigits(int n) {
		//将数字转化为字符串
		string s = to_string(n);
		//flag用来标记赋值9从哪里开始
		//初始化为s.size，避免后序在flag没有被赋值的情况下接着执行
		int flag = s.size();
		
		for(int i = s.size() - 1;i > 0;i--){
			//前一位大于后一位
			if(s[i - 1] > s[i]){
				s[i - 1]--;
				flag = i;//flag记录应当变成9的开始位置
			}
		}
		
		for(int i = flag;i < s.size();i++){
			s[i] = '9';
		}
		
		return stoi(s);
	}
};
class Solution2 {
public:
	int monotoneIncreasingDigits(int n) {
		string s = to_string(n);
		
		int flag = s.size();
		
		for(int i = s.size() - 1;i > 0;i--){
			if(s[i - 1] > s[i]){
				flag = i;
				s[i - 1]--;
			}
		}
		
		for(int i = flag;i < s.size();i++){
			s[i] = '9';
		}
		
		return stoi(s);
	}
};
