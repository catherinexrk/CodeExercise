#include <stdlib.h>
#include <vector>
#include <iostream>

using namespace std;

//https://leetcode.cn/problems/spiral-matrix-ii/description/

class Solution1 {
public:
	vector<vector<int>> generateMatrix(int n) {
		vector<vector<int>> result(n,vector<int>(n));
		int left = 0,right = n - 1,top = 0,bottom = n - 1;//表示正方形的四个边界点的位置
		for(int i = 1;i <= n * n;){
			//l-r 从左到右
			for(int j = left;j <= right;j++) 
				result[top][j] = i++;
			top++;//第一行完成 此时起始点在第二行
			//t-b
			for(int j = top;j <= bottom;j++)
				result[j][right] = i++;
			right--;//右边界左移动
			//r-l
			for(int j = right;j >= left;j--)
				result[bottom][j] = i++;
			bottom--;//下边界向上移动
			//b-t
			for(int j = bottom;j >= top;j--)
				result[j][left] = i++;
			left++;//上边界向下移动一层
		}
		return result;
	}
};

class Solution {
public:
	vector<int> spiralOrder(vector<vector<int>>& matrix) {
		int n = matrix.size();
//		vector<vector<int>> result(n,vector<int>(n));
		vector<int> result(n * n);
		int left = 0,right = n - 1,top = 0,bottom = n - 1;//表示正方形的四个边界点的位置
		int index = 0;
		for(int i = 1;i <= n * n;){
			//l-r 从左到右
			for(int j = left;j <= right;j++) 
//				result[top][j] = i++;
			result[index++] = i++;
			top++;//第一行完成 此时起始点在第二行
			//t-b
			for(int j = top;j <= bottom;j++)
//				result[right][j] = i++;
				result[index++] = i++;
			right--;//右边界左移动
			//r-l
			for(int j = right;j >= left;j--)
//				result[bottom][j] = i++;
				result[index++] = i++;
			bottom--;//下边界向上移动
			//b-t
			for(int j = bottom;j >= top;j--)
//				result[left][j] = i++;
				result[index++] = i++;
			left++;//上边界向下移动一层
		}
		return result;
	}
};
