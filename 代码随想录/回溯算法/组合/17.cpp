#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;
//https://leetcode.cn/problems/letter-combinations-of-a-phone-number/

class Solution {
public:
	vector<string> character = {
		"",//0
		"",//1
		"abc",//2
		"def",//3
		"ghi",//4
		"jkl", // 5
		"mno", // 6
		"pqrs", // 7
		"tuv", // 8
		"wxyz", // 9
	};
	
	vector<string> result;//保存所有的字符串
	string s;
	
	//index记录遍历了第几个数字
	void backTracking(string digits,int index){
		if(index == digits.size()){
			result.push_back(s);
			return;
		}
		
		int digit = digits[index] - '0';//将index指向的数字转化成为int
		string letters = character[digit];
		
		for(int i = 0;i < letters.size();i++){
			s.push_back(letters[i]);
			backTracking(digits,index + 1);
			s.pop_back();
		}
	}
	
	void back(string digits,int index){
		if(index == digits.size()){
			//此时遍历到头了
			result.push_back(s);
			return;
		}
		
		int digit = digits[index] - '0';
		string letters = character[digit];
		
		for(int i = 0;i < letters.size();i++){
			s.push_back(letters[i]);
			back(digits,index + 1);
			s.pop_back();
		}
	}
	
	vector<string> letterCombinations(string digits) {
		if(digits.size() == 0){
			return result;
		}
		
		backTracking(digits,0);
		return result;
	}
};

class Solution2{
	vector<string> character = {
		"",//0
		"",//1
		"abc",//2
		"def",//3
		"ghi",//4
		"jkl", // 5
		"mno", // 6
		"pqrs", // 7
		"tuv", // 8
		"wxyz", // 9
	};
	
	
	vector<string> result;
	string s;
	
	void back(string digits,int index){
		if(index == digits.size()){
			result.push_back(s);
			return;
		}
		
		int digit = digits[index] - '0';
		string letter = character[digit];
		
		for(int i = 0;i < letter.size();i++){
			s.push_back(letter[i]);
			back(digits,index + 1);
			s.pop_back();
		}
	}
	
	vector<string> letterCombinations(string digits) {
		if(digits.size() == 0){
			return {};
		}
		back(digits,0);
		return result;
	}
};
