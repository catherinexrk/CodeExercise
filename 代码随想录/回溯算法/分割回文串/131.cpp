#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;
//https://leetcode.cn/problems/palindrome-partitioning/

class Solution {
public:
	vector<vector<string>> result;
	vector<string> path;
	string s;
	
	bool judgePalindrome(string s,int begin,int end){
		for(;begin < end;begin++,end--){
			if(s[begin] != s[end]) return false;
		}		
		return true;
	}
	
	void backTracking(string s,int startIndex){
		if(startIndex >= s.size()){
			result.push_back(path);
			return;
		}
		
		
		for(int i = startIndex;i < s.size();i++){
			if(judgePalindrome(s,startIndex,i)){ //起始位置starytIndex，终止位置i
				string str = s.substr(startIndex, i - startIndex + 1);
				path.push_back(str);
			}else{
				continue;
			}
			
			backTracking(s,i + 1);
			path.pop_back();
		}
	}
	
	vector<vector<string>> partition(string s) {
		backTracking(s,0);
		return result;
	}
};

class Solution2 {
public:
	vector<vector<string>> result;
	vector<string> path;
	
	bool isPalindrome(string s,int begin,int end){
		while(begin <= end){
			if(s[begin] != s[end]) return false;
			begin++;
			end--;
		}
		return true;
	}
	
	void backTracking(string s,int startIndex){
		//startIndex即为切割线，表示字符串切割的位置
		if(startIndex >= s.size()){
			result.push_back(path);
			return;
		}
		
		for(int i = startIndex;i < s.size();i++){
			if(isPalindrome(s,startIndex,i)){
				string str = s.substr(startIndex,i -startIndex + 1);
				path.push_back(str);
			}else{
				continue;//说明此时不是回文字符
			}
			
			backTracking(s,i + 1);
			path.pop_back();
			
		}
	}
	
	vector<vector<string>> partition(string s) {
		backTracking(s,0);
		return result;
	}
};
