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

class Solution3 {
public:
    string reverseWords(string s) {
		vector<string> arr;
		stringstream result(s);//分解原先字符串
		string word;
		while(result >> word){
			arr.push_back(word);
		}

		reverse(arr.begin(),arr.end());
		string finalResult;
		for(int i = 0;i < arr.size();i++){
			finalResult.append(arr[i]);
			if(i != arr.size() - 1){
				finalResult += ' ';
			}
		}
		return finalResult;
    }
};

class Solution {
public:
	void reverse(string& s,int start,int end){
		for(int i = start,j = end;i < j;i++,j--){
			swap(s[i],s[j]);
		}
	}

	//去除所有空格，并且在相邻单词之间田间空格，使用快慢指针
	void removeExtraSpaces(string& s){
		int slow = 0;
		for(int i = 0;i < s.size();i++){
			//遇到非空格就进行处理，删除所有空格
			if(s[i] != ' '){
				if(slow != 0){
					s[slow++] = ' ';//slow!=0 说明不是第一个单词，需要在单词前面添加空格
				}
				while(i < s.size() and s[i] != ' '){
					s[slow++] = s[i++];
				}
			}
		}
		s.resize(slow);
	}

	string reverseWords(string s) {
		removeExtraSpaces(s);//去除多余空格 并且保证单词之间只有一个空格，且字符串首尾都没有空格

		reverse(s,0,s.size() - 1);

		int start = 0;//
		for(int i = 0;i <= s.size();i++){
			//到达空格或者串尾，说明一个单词进行结束，进行单词的翻转
			if(i == s.size() or s[i] == ' '){
				reverse(s,start,i - 1);//翻转当前的单词
				start = i + 1;//更新下一个单词的开始下标
			}
		}
		return s;
	}
};
