#include <string.h>
#include <iostream>
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;
//https://leetcode.cn/problems/reverse-words-in-a-string/

class Solution1 {
public:
	string reverseWords(string s) {
		vector<string> result;
		stringstream temp(s);
		string word;
		while(temp >> word){
			result.push_back(word);
		}
		
		reverse(result.begin(),result.end());
		string result1;
		for(int i = 0;i < result.size();i++){
			result1 += result[i];
			if(i != result.size() - 1){
				result1 += ' ';
			}
		}
		return result1;
	}
};

class Solution2{
public:
	string reverseWords(string s) {
		vector<string> result;
		stringstream temp(s);//根据空格进行分割字符
		string word;//接收temp中的分割
		for(temp >> word){
			result.push_back(word);
		}
		
		reverse(result.begin(),result.end());//反转数组
		string return1;
		for(int i = 0;i < result.size();i++){
			return1 += result[i];
			if(i != result.size() - 1){
				return1 += ' ';
			}
		}
		return return1;
		
	}
};

class Solution {
public:
	string reverseWords(string s) {
		
	}
};
