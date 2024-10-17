#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;
//https://leetcode.cn/problems/restore-ip-addresses/

class Solution {
public:
	vector<string> result;
	
	//判断[begin,end]这个区间的字符串是否合法
	bool isValidIpString(string s,int begin,int end){
		if(begin > end) return false;
		
		//判断字符是否合法
		//0开头的数组不合法
		if(s[begin] == '0' && begin != end){
			return false;
		}
		
		int num = 0;
		for(int i = begin;i <= end;i++){
			num = num * 10 + (s[i] - '0');
			//如果数字大于255，则不合法
			if(num > 255){
				return false;
			}
		}
		return true;
	}
	
	
	//startIndex搜索的起始位置 poitNum添加逗点的数量
	void backTracking(string s,int startIndex,int pointSum){
		if(pointSum == 3){
			if(isValidIpString(s,startIndex,s.size() - 1)){
				result.push_back(s);
			}
		}
		
		for(int i = startIndex;i < s.size();i++){
			if(isValidIpString(s,startIndex,i)){
				//判断[startIndex,i]这个区间的子串是否合法
				s.insert(s.begin() + i + 1,'.');//如果合法，则在当前的分隔符i的下一位插入逗点
				pointSum++;
				backTracking(s,i + 2,pointSum);
				pointSum--;
				s.erase(s.begin() + i + 1);//回溯删除逗点
			} else{
				break;//不合法，结束本层循环
			}
		}
	}
	
	vector<string> restoreIpAddresses(string s) {
		if(s.size() < 4 || s.size() > 12) return result;//剪枝
		backTracking(s,0,0);
		
		return result;
	}
};

class Solution2 {
public:
	vector<string> result;
	
	//比较字符串的[begin,end]是否合法
	bool isValid(string s,int begin,int end){
		if(begin > end) return false;
		//开头的字符不能为0
		if(s[begin] == '0') return false;
		
		int num = 0;
		for(int i = begin;i <= end;i++){
			//字符不为1-9的数字
			if(s[i] > '9' || s[i] < '0') return false;
			
			num = num * 10 + s[i] - '0';
			//如果num大于255，则字符串区间不合法
			if(num > 255) return false;
		}
	}
	
	bool isValid2(string s,int begin,int end){
		if(begin > end) return false;
		
		if(s[begin] == '0') return false;
		
		int num = 0;
		for(int i = begin;i <= end;i++){
			if(s[i] > '9' || s[i] < '0') return false;
			
			num = num * 10 + s[i] - '0';
			if(num > 255) return false;	
		}
		return true;
	}
	
	void backTracking(string s,int startIndex,int pointSum){
		if(pointSum == 3){
			if(isValid(s,startIndex,s.size() - 1)){
				result.push_back(s);
			}
		}
		
		for(int i = startIndex;i < s.size();i++){
			if(isValid(s,startIndex,i)){
				s.insert(s.begin() + i + 1,'.');
				pointSum++;
				backTracking(s,i + 2,pointSum);
				pointSum--;
				s.erase(s.begin() + i + 1);
			} else break;
		}
	}
	
	vector<string> restoreIpAddresses(string s) {
		if(s.size() < 4 || s.size() > 12) return result;
		backTracking(s,0,0);
		return result;
	}
};
