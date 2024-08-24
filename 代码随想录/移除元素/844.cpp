#include <stdlib.h>
#include <iostream>
#include <vector>
#include <stack>

using namespace std;
//https://leetcode.cn/problems/backspace-string-compare/description/

class SolutionStack{
public:
	bool backspaceCompare(string s, string t) {
		s = disposeString(s);
		t = disposeString(t);
		if(s == t){
			return true;
		}
		return false;
	}
	
private:
	string disposeString(string s){
		//栈操作
		stack<int> stk;
		for(char temp : s){
			if(temp == '#'){
				if(!stk.empty()){
					stk.pop();//检测到'#' 弹出前一个元素
				}
			} else{
				stk.push(temp);
			}
		}
		string result;
		while(!stk.empty()){ //将栈中的元素遍历弹出
			result += stk.top(); //result接收来自stk栈顶元素，并且本身相加
			stk.pop();//stk不断弹出元素
		}
		return result;
	}
};

class Solution {
public:
	bool backspaceCompare(string s, string t) {
		
	}
};

int main(){
//	string s = "hello world ";
//	string s1 = "hello world  ";
//	cout<<s.compare(s1);
}
