#include <stdlib.h>
#include <vector>
#include <iostream>

using namespace std;

//https://leetcode.cn/problems/spiral-matrix/description/

class Solution {
public:
	vector<int> spiralOrder(vector<vector<int>>& matrix) {
		int rows = matrix.size();   // 获取行数
		int cols = matrix[0].size(); // 获取列数
		
		// 确定好左右边界
		int l = 0, r = cols - 1, t = 0, b = rows - 1;
		vector<int> result(rows * cols); // 初始化结果数组
		int index = 0; // 结果数组的索引
		
		while (l <= r && t <= b) {
			// 从左到右
			for (int j = l; j <= r; ++j) {
				result[index++] = matrix[t][j];
			}
			t++; // 上边界更新
			
			// 从上到下
			for (int i = t; i <= b; ++i) {
				result[index++] = matrix[i][r];
			}
			r--; // 右边界更新
			
			// 从右到左 (检查是否还有有效的行)
			if (t <= b) {
				for (int j = r; j >= l; --j) {
					result[index++] = matrix[b][j];
				}
				b--; // 下边界更新
			}
			
			// 从下到上 (检查是否还有有效的列)
			if (l <= r) {
				for (int i = b; i >= t; --i) {
					result[index++] = matrix[i][l];
				}
				l++; // 左边界更新
			}
		}
		
		return result;
	}
};

//class Solution {
//public:
//	vector<int> spiralOrder(vector<vector<int>>& matrix) {
//		if (matrix.empty()) return {};
//		
//		int rows = matrix.size();      // 获取行数
//		int cols = matrix[0].size();   // 获取列数
//		
//		// 获取完行数之后开始常规操作
//		// 确定好左右边界
//		int l = 0, r = cols - 1, t = 0, b = rows - 1;
//		vector<int> result(rows * cols);
//		int index = 0;
//		
//		while (t <= b && l <= r) {
//			// 从左到右
//			for (int j = l; j <= r; ++j)
//				result[index++] = matrix[t][j];
//			t++;
//			
//			// 从上到下
//			for (int i = t; i <= b; ++i)
//				result[index++] = matrix[i][r];
//			r--;
//			
//			// 从右到左
//			if (t <= b) {
//				for (int j = r; j >= l; --j)
//					result[index++] = matrix[b][j];
//				b--;
//			}
//			
//			// 从下到上
//			if (l <= r) {
//				for (int i = b; i >= t; --i)
//					result[index++] = matrix[i][l];
//				l++;
//			}
//		}
//		
//		return result;
//	}
//};

