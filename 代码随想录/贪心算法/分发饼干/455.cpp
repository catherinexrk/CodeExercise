#include <stdlib.h>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
//https://leetcode.cn/problems/assign-cookies/

class Solution {
public:
	int findContentChildren(vector<int>& g, vector<int>& s) {
		//g是孩子的胃口值
		//s是每块饼干的尺寸
		
		
		//此题保证了最大的饼干一定要喂给胃口大的吃
		sort(g.begin(),g.end());
		sort(s.begin(),s.end());
		
		
		//开始从s的最大开始依次递减
		int count = 0;//表示多少个孩子符合吃
		int index = s.size() - 1;
		for(int i = g.size() - 1;i >= 0;i--){
			if(index >=0 && s[index] >= g[i]){
				index--;
				count++;
			}
		}
		
		return count;
	}
};
