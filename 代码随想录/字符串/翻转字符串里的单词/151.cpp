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

class Solution{
public:
	string reverseWords(string s) {
		
	}
};
