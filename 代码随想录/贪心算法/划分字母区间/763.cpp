#include <stdlib.h>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <list>

using namespace std;
//https://leetcode.cn/problems/partition-labels/

class Solution {
public:
	vector<int> partitionLabels1(string s) {
		int hash[27] = {0};//统计每一个字母最后出现的位置
		for(int i = 0;i < s.size();i++){
			hash[s[i] - 'a'] = i;
		}
		
		vector<int> result;
		int left = 0,right = 0;
		
		//从头开始遍历字符，并更新字符的最远出现下标，如果找到了字符最远出现下标和当前下标相等，则找到了分割点
		for(int i = 0;i < s.size();i++){
			right = max(right,hash[s[i] - 'a']);//找到字符出现的最远边界
			if(i == right){
				result.push_back(right - left + 1);
				left = i + 1;
			}
		}
		
		return result;
	}
	
	vector<int> partitionLabels(string s){
		int hash[27] = {0};//记录每一个字符出现在字符串中的最后的位置
		for(int i = 0;i < s.size();i++){
			hash[s[i] - 'a'] = i;
		}
		
		vector<int> result;
		int left = 0,right = 0;
		
		for(int i = 0;i < s.size();i++){
			right = max(right,hash[s[i] - 'a']); //确保这个字符串中包含的所有字母的最后一次出现位置，避免字母又出现在了别的字符串中
			if(i == right){
				result.push_back(right - left + 1);
				left = i + 1;//新的左边界
			}
		}
		
		return result;
	}
};
