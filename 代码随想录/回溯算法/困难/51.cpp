#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_set>
#include <map>

using namespace std;
//https://leetcode.cn/problems/reconstruct-itinerary/

class Solution {
public:
	vector<vector<string>> result;
	
	//n棋盘大小 row表示当前遍历到棋盘的第几层
	void backTracking(int n,int row,vector<string>& chessboard){
		if(row == n){
			result.push_back(chessboard);
			return;
		}
		
		/**
		 * 递归深度row控制棋盘的行
		 * for循环col控制棋盘的列
		 */
		
		for(int col = 0;col < n;col++){
			if(isValid(row,col,chessboard,n)){
				chessboard[row][col] = 'Q';//放置Q皇后
				backTracking(n,row + 1,chessboard);
				chessboard[row][col] = '.';//回溯，撤销皇后
			}
		}
	}
	
	bool isValid(int row,int col,vector<string> &chessborad,int n){
		//检查当前列上方所有行[0,row - 1]是否存在皇后
		for(int i = 0;i < row;i++){
			if(chessborad[i][col] == 'Q')
				return false;
		}
		
		//检查45° 左上到右下
		//i从当前行row - 1向上递减，j从当前列col - 1向左递减，检查左上到右下的对角线
		//保证保存的皇后的左上没有其余皇后
		for(int i = row - 1,j = col - 1;i >= 0 && j >= 0;i--,j--){
			if(chessborad[i][j] == 'Q')
				return false;
		}
		
		
		//检查145° 右上到左下
		//保证当前皇后的右上角没有其余皇后
		for(int i = row - 1,j = col + 1;i >=0 && j < n;i--,j++){
			if(chessborad[i][j] == 'Q')
				return false;
		}
		
		return true;
	}
	
	vector<vector<string>> solveNQueens(int n) {
		vector<string> chessboard(n,string(n,'.'));
		backTracking(n,0,chessboard);
		
		return result;
	}
};
