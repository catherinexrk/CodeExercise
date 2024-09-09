#include <stdlib.h>
#include <string.h>
#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;
//https://leetcode.cn/problems/minimum-window-substring/description/


/*
简单说下我的思路，我的想法是一个动态区间，在这个动态区间里面去找
如果说是t中的每一个字符都可以在s的某个动态区间中被找到，那么算是成功
同时更新记录一下此时的区间，接着动态区间接着划分，如果再次匹配成功
此时比较两个子区间序列的长度，取长度最小的，最终返回，如果最终没找到则返回""
*/

//第一次做想的我感觉是对的，但是肯定没过，因为没考虑全

//class Solution {
//public:
//	string minWindow(string s, string t) {
//		string result = "";//最终返回的字符串
//		//先是判断长度
//		if(t.size() > s.size())
//			return result;
//		int left = 0;//左边界
//		for(int right = 0;right < s.size();right++){//右边界，可以滑动
//			string subString = s.substr(left,right);
//			//先是判断长度,符合长度区间要求再进行后续操作
//			if(subString.size() >= t.size()){
//				//满足条件之后开始进行比较
//				for(char temp : t){
//					int flag = containsChar(subString,temp);//查询t中的字符书否正常存在于s的子序列中
//					if(flag == 0){
//						break;//不在区间，终止循环
//					}
//				}
//				result = result.size() < subString.size() ? subString : result;//选取最短的字符串，并且保留
//			}
//			left++;
//		}
//		
//		return result;
//	}
//	
//private:
//	bool containsChar(const string& s, char temp) {
//		// 使用 find 方法查找字符的位置
//		return s.find(temp) != string::npos;
//	}
//};

class Solution1 {
public:
	string minWindow(string s, string t) {
		int m = s.size();
		int n = t.size();
		
		//比较s和t的长度
		if (n > m) 
			return "";
		
		// 用于记录 t 中每个字母的出现次数
		unordered_map<char, int> cntT;
		for (char c : t) {
			cntT[c]++;
		}
		
		// 用于记录当前窗口中每个字母的出现次数
		unordered_map<char, int> cntS;
		
		int left = 0;//左边界，初始位置在字符串s的起始位置
		int ansLeft = -1, ansRight = m;//记录最小子串的左右端点
		int required = cntT.size(); // 需要满足的字符种类数量
		int formed = 0; // 当前窗口中满足t频率的字符种类数量
		
		for (int right = 0; right < m; ++right) {
			char c = s[right];
			cntS[c]++;
			
			// 如果当前字符是 t 中的字符，并且当前窗口中的数量满足了 t 的数量
			if (cntT.count(c) && cntS[c] == cntT[c]) {
				formed++;
			}
			
			// 当窗口中包含了所有 t 中的字符时，尝试收缩窗口
			while (left <= right && formed == required) {
				// 更新结果
				if (right - left < ansRight - ansLeft) {
					ansLeft = left;
					ansRight = right;
				}
				
				// 收缩窗口
				char left_char = s[left];
				cntS[left_char]--;
				if (cntT.count(left_char) && cntS[left_char] < cntT[left_char]) {
					formed--;
				}
				left++;
			}
		}
		
		// 如果没有找到符合要求的子串，返回空字符串
		if (ansLeft == -1) return "";
		
		return s.substr(ansLeft, ansRight - ansLeft + 1);
	}
};

class MySolution {
public:
	string minWindow(string s, string t) {
		if(s.size() < t.size())
			return "";
		
		unordered_map<char,int> cntT;//记录t中的每一个字符出现的次数
		unordered_map<char,int> cntS;//记录s中的
		for(char temp : t){
			cntT[temp]++;//哈希表中更新字符出现的次数
		}
		
		int required = t.size();//表示s中的子序列中满足与t进行匹配的数量
		int formed = 0;//表示s的子序列中满足条件的数量，要与required进行比较
		
		int ansLeft = -1,ansRight = s.size();//满足条件子序列的左右端
		
		int left = 0;//左边界
		
		//开始遍历
		for(int right = 0;right < s.size();right++){
			cntS[s[right]]++;//更新cntS
			//判断字符是否存在于s中，并且当前区间内其在s中出现的频率是否满足在t中的频率
			if (cntT.count(s[left]) && cntS[s[left]] == cntT[s[left]]){
				formed++;
			}
			
			//当前子序列中包含了所有t中出现的字符时formed == required，开始收缩窗口，去不断找到最短序列
			while(left <= right && formed == required){
				//更新找到最小覆盖子串的左右边界
				if(right - left + 1 < ansRight - ansLeft + 1){
					ansLeft = left;
					ansRight = right;
				}
				//收缩窗口
				cntS[s[left]]--;//左边界要右移一位，因此需要讲cntS中减去原先左边界上的数值出现的次数
				if (cntT.count(s[left]) && cntS[s[left]] < cntT[s[left]]){ //判断减少的左边界的数值是否存在于t中
					formed--;
				}
				left++;
			}
		}
		
		if(ansLeft == -1)
			return "";
		return s.substr(ansLeft,ansRight - ansLeft + 1);//返回满足条件的序列区间
	}
};

class Solution {
public:
	string minWindow(string s, string t) {
		int m = s.size();
		int n = t.size();
		
		// 如果 t 比 s 长，直接返回空字符串
		if (n > m) 
			return "";
		
		unordered_map<char, int> cntT; // 记录 t 中的每一个字符出现的次数
		for (char temp : t) {
			cntT[temp]++;
		}
		
		unordered_map<char, int> cntS; // 记录 s 当前窗口中字符的出现次数
		
		int required = cntT.size(); // 需要满足的字符种类数量
		int formed = 0; // 当前窗口中满足 t 中字符数量的种类数
		
		int ansLeft = -1, ansRight = m; // 记录最小覆盖子串的左右端点
		
		int left = 0; // 左边界
		
		// 开始遍历 s
		for (int right = 0; right < m; ++right) {
			char c = s[right];
			cntS[c]++;
			
			// 如果当前字符是 t 中的字符，并且当前窗口中的数量满足了 t 的数量
			if (cntT.count(c) && cntS[c] == cntT[c]) {
				formed++;
			}
			
			// 当窗口中包含了所有 t 中的字符时，尝试收缩窗口
			while (left <= right && formed == required) {
				// 更新结果
				if (right - left < ansRight - ansLeft) {
					ansLeft = left;
					ansRight = right;
				}
				
				// 收缩窗口
				char left_char = s[left];
				cntS[left_char]--;
				if (cntT.count(left_char) && cntS[left_char] < cntT[left_char]) {
					formed--;
				}
				left++;
			}
		}
		
		// 如果没有找到符合要求的子串，返回空字符串
		if (ansLeft == -1) return "";
		
		return s.substr(ansLeft, ansRight - ansLeft + 1);
	}
};

