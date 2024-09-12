#include <stdlib.h>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;
//https://leetcode.cn/problems/valid-anagram/description/

class Solution {
public:
	bool isAnagram(string s, string t) {
		//s t 仅包含小写字母
		if(s.length() != t.length()){
			return false;//长度不符合直接pass
		}
		
		vector<int> count(26,0);//记录字符串中的所有字符出现的次数
		for(int i = 0;i < s.length();i++){
			count[s[i] - 'a']++;//统计每一个s中的字符中的出场次数
			//对t开始计数
			count[t[i] - 'a']--;
		}
		for(int i = 0;i < 26;i++){
			if(count[i] != 0){ 
				//按道理来说count数组每一个位置都应该为0，否则不符合题目要求
				return false;
			}
		}
		return true;
	}
};

//时间复杂度O(n)
