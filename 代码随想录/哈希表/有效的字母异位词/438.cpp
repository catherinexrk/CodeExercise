#include <stdlib.h>
#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

//https://leetcode.cn/problems/find-all-anagrams-in-a-string/

/*
我的第一时间的想法，滑动窗口加哈希表存储，定义一个滑动窗口，长度跟p相同长度，每次移动一个位置
如果相等则记录一下位置，其中判断是否相等也简单，sort一下就行了
*/
class Solution1 {
public:
	vector<int> findAnagrams1(string s, string p) {
		//考虑特殊情况
		if(s.length() < p.length()){
			return {};
		}
		
		sort(p.begin(),p.end());//对p进行排序
		string key = p;
		string window(p.length(),'0');
		
		vector<int> result;
		
//		删除首元素：使用pop_front方法（C++20引入），或者通过下标和erase方法。
//		删除尾元素：使用pop_back方法。
		window = s.substr(0,3);//从0位置开始，截取三个元素
		for(int i = 0;i < s.length();i++){
			string damn = window;
			sort(damn.begin(),damn.end());
			if(damn == key){
				result.push_back(i);//存储当前位置
			}
			//判断结束，此时滑动窗口右移一位
			window.erase(0,0);
			window.push_back()
		}
	}
	
	vector<int> findAnagrams(string s, string p){
		if(s.length() < p.length()){
			return {};
		}
		
		sort(p.begin(),p.end());
		string key = p;//存储应该保存的key
		vector<int> result;//存储满足要求的序列下号
		
		//先进行滑动，再进行比较
		string window = s.substr(0,key.length());
		string damn = window;
		sort(damn.begin(),damn.end());
		if(damn == key){
			result.push_back(0);
		}
		
		for(int i = 1;i < s.length() - key.length() + 1;i++){
			window.erase(0,1);//删除首元素
			window += s[i + p.length() - 1];//尾加一个元素
			
			string damn = window;
			sort(damn.begin(),damn.end());
			if(damn == key){
				result.push_back(i);
			}
		}
		
		return result;
	}
};

class Solution{
public:
	vector<int> findAnagrams(string s, string p){
		if(s.length() < p.length()){
			return {};
		}
		
		sort(p.begin(),p.end());
		string key = p;//存储应该保存的key
		vector<int> result;//存储满足要求的序列下号
		
		//先进行滑动，再进行比较
		string window = s.substr(0,key.length());
		string damn = window;
		sort(damn.begin(),damn.end());
		if(damn == key){
			result.push_back(0);
		}
		
		for(int i = 1;i < s.length() - key.length() + 1;i++){
			window.erase(0,1);//删除首元素
			window += s[i + p.length() - 1];//尾加一个元素
			
			string damn = window;
			sort(damn.begin(),damn.end());
			if(damn == key){
				result.push_back(i);
			}
		}
		
		return result;
	}
};

class Solution2{
public:
	vector<int> findAnagrams(string s, string p) {
		vector<int> result;
		int sLen = s.length(), pLen = p.length();
		
		if (sLen < pLen) return result;  // 如果 s 的长度小于 p，直接返回空数组
		
		vector<int> pCount(26, 0), sCount(26, 0);  // 用于记录字符频率
		
		// 先统计 p 中每个字符的频率
		for (int i = 0; i < pLen; i++) {
			pCount[p[i] - 'a']++;
			sCount[s[i] - 'a']++;
		}
		
		// 检查初始窗口是否是异位词
		if (pCount == sCount) {
			result.push_back(0);
		}
		
		// 开始滑动窗口
		for (int i = pLen; i < sLen; i++) {
			sCount[s[i] - 'a']++;  // 新加入的字符
			sCount[s[i - pLen] - 'a']--;  // 移除的字符
			
			// 检查当前窗口是否是异位词
			if (pCount == sCount) {
				result.push_back(i - pLen + 1);
			}
		}
		
		return result;
	}
};

class Solution {
public:
	vector<int> findAnagrams(string s, string p) {
		int sLen = s.length();
		int pLen = p.length();
		if(sLen < pLen){
			return {};
		}
		
		vector<int> result;//保存返回的序列号
		
		//创建两个count数组保存字母出现的频率
		vector<int> sCount(26,0);
		vector<int> pCount(26,0);
		
		for(int i = 0;i < pLen;i++){
			sCount[s[i] - 'a']++;
			pCount[p[i] - 'a']++;
		}
		
		//先塞入pLen个元素从头开始比较
		if(sCount == pCount){
			result.push_back(0);
		}
		
		for(int i = pLen;i < sLen;i++){
			sCount[s[i] - 'a']++;//吸收新元素
			sCount[s[i - pLen] - 'a']--;//取出队头元素
			
			if(sCount == pCount){
				result.push_back(i - pLen + 1);
			}
		}
		//时间复杂度O(n)
		return result;
	}
};
