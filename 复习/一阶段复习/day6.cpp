#include <bits/stdc++.h>

using namespace std;

class Solution{
public:
	string reverseStr1(string s, int k) {
		for(int i = 0;i < s.length();i += 2 * k){
			if(i + 2 * k < s.length()){
				reverse(s.begin() + i,s.begin() + i + k);//此时说明从i开始2k的长度都可以进行翻转
			} else if(i + k < s.length()){
				reverse(s.begin() + i,s.end());
			}else if(i + 2 * k > s.length() && i + k < s.length()){
				reverse(s.begin() + i,s.begin() + i + k);
			}
		}
		return s;
	}
	
	string reverseStr(string s, int k){
		for(int i = 0;i < s.length();i += 2 * k){
			if(i + k < s.length()){
				reverse(s.begin() + i,s.begin() + i + k);
			} else{
				reverse(s.begin() + i,s.end());
			}
		}
		return s;
	}
};

class Solution2{
public:
	string replaceString(string s){
		int countNum = 0;//记录数字次数
		for(char temp : s){
			if(temp >= '0' && temp <= '9') countNum++;
		}
		int oldSize = s.length() - 1;
		s.resize(s.length() + countNum * 5);
		int newSize = s.length() - 1;
		while(oldSize >= 0){
			if(s[oldSize] >= '0' && s[oldSize] <= '9'){
				s[newSize--] = 'r';
				s[newSize--] = 'e';
				s[newSize--] = 'b';
				s[newSize--] = 'm';
				s[newSize--] = 'u';
				s[newSize--] = 'n'; 
				oldSize--;
			} else{
				s[newSize--] = s[oldSize--];
			}
		}
		return s;
	}
};

class Solution3{
public:
	string reverseWords1(string s) {
		reverse(s.begin(),s.end());
		vector<string> result;//存储第一次反转的字符
		vector<char> charArray;
		for(char temp : s){
			if(temp == ' '){
				string str(charArray.begin(),charArray.end());
				result.push_back(str);
				charArray.clear();
			}
			charArray.push_back(temp);	
		}
		
		for(string temp : result){
			reverse(temp.begin(),temp.end());
		}
		
		string resultString;
		for(int i = 0;i < result.size();i++){
			if(i == result.size() - 1){
				resultString += result[i];
			}
			resultString += result[i];
			resultString += ' ';
		}
		return resultString;
		
	}
	
	string reverseWords(string s){
		vector<string> wordArray;
		string word;
		reverse(s.begin(),s.end());
		for(char ch : s){
			if(ch != ' '){
				word.push_back(ch);
			} else{
				if(!word.empty()){
					wordArray.push_back(word);
					word.clear();
				}
			}
		}
		
		if(!word.empty()){
			wordArray.push_back(word);
		}
		
		string result;
		for(int i = 0;i < wordArray.size();i++){
			reverse(wordArray[i].begin(),wordArray[i].end());
			result += wordArray[i];
			if(i < wordArray.size() - 1){
				result += ' ';
			}
		}
		return result;
	}
};

class Solution4{
public:
	 string rotateString(int len, string& s){
		//合理的区间
		 len = len % s.length();
		 string tail(s.begin() + len,s.end());
		 string head(s.begin(),s.begin() + len);
		 s.clear();
		 s.append(tail);
		 s.append(head);
		 
		 
		 return s;
	 }
};




class Solution5{
public:
	
};


class Solution6{
public:
	bool isValid(string s) {
		stack<char> st;
		for(char temp : s){
			if(temp == '(' || temp == '{' || temp == '['){
				st.push(temp);
			}else if(temp == ')' || temp == ']' || temp == '}'){
				if(!st.empty()) return false;//stack为空
				char ch = st.top();
				st.pop();
				if((temp == ')' && ch == '(') ||
					(temp == ']' && ch == '[') ||
					(temp == '}' && ch == '{')) continue;
				else{
					return false;
				}
			}
		}
		return st.empty();
	}
};

class Solution7{
public:
	string removeDuplicates(string s) {
		
	}
};
