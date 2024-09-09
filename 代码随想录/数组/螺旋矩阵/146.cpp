#include <stdlib.h>
#include <vector>
#include <iostream>

using namespace std;

//https://leetcode.cn/problems/shun-shi-zhen-da-yin-ju-zhen-lcof/description/

class Solution {
public:
	vector<int> spiralArray(vector<vector<int>>& array) {
		if (array.empty() || array[0].empty()) 
			return {};
		int rows = array.size();//行
		int cols = array[0].size();//列
		vector<int> result(rows * cols);
		
		int l = 0, r = cols - 1, t = 0, b = rows - 1;
		int index = 0;
		while(l <= r && t <= b){
			//从左到右
			for(int i = l;i <= r;i++)
				result[index++] = array[t][i];
			t++;
			//从上到下
			for(int j = t;j <= b;j++)
				result[index++] = array[j][r];
			r--;
			
			//判断从左到右是否需要继续执行
			if(l <= r){
				for(int i = r;i >= l;i--)
					result[index++] = array[b][i];
				b--;
			}
			
			//判断是否需要继续执行从下到上
			if(t <= b){
				for(int j = b;j >= t;j--)
					result[index++] = array[j][l];
				l++;
			}
		}
		return result;
	}
};

class GptSolution {
public:
	vector<int> spiralArray(vector<vector<int>>& array) {
		if (array.empty() || array[0].empty())
			return {};
		
		int rows = array.size();
		int cols = array[0].size();
		vector<int> result;
		
		int l = 0, r = cols - 1, t = 0, b = rows - 1;
		
		while (l <= r && t <= b) {
			// 从左到右
			for (int i = l; i <= r; ++i)
				result.push_back(array[t][i]);
			t++;
			
			// 从上到下
			for (int j = t; j <= b; ++j)
				result.push_back(array[j][r]);
			r--;
			
			if (t <= b) {
				// 从右到左
				for (int i = r; i >= l; --i)
					result.push_back(array[b][i]);
				b--;
			}
			
			if (l <= r) {
				// 从下到上
				for (int j = b; j >= t; --j)
					result.push_back(array[j][l]);
				l++;
			}
		}
		
		return result;
	}
};

