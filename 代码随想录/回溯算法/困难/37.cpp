#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_set>
#include <map>

using namespace std;
//https://leetcode.cn/problems/sudoku-solver/

/**
 * 搜索单挑路径bool
 * 搜索整个路径void
 */

class Solution {
public:
	
	
	bool backTracking(vector<vector<char>>& board){
		for(int i = 0;i < board.size();i++){//遍历行
			for(int j = 0;j < board[0].size();j++){//遍历列
				if(board[i][j] != '.') continue;//当前位置已经有数字了
				for(char k = '1';k <= '9';k++){//判断当前位置放[1,9]中的数字合法性
					if(isValid(i,j,k,board)){//当前k合规
						board[i][j] = k;
						
						if((backTracking( board))) return true;//找到合适的一组数独即返回
						board[i][j] = '.';//回溯，撤销k
					}
				}
				return false;//9个数字都不行，说明这个数独不成立
			}
		}
		return true;//遍历完没有false，说明此时数独合法
	}
	
	bool isValid(int row,int col,char val,vector<vector<char>>& board){
		//判断行里是否重复
		for(int i = 0;i < 9;i++){
			if(board[row][i] == val)
				return false;
		}
		
		//判断列里是否重复
		for(int j = 0;j < 9;j++){
			if(board[j][col] == val)
				return false;
		}
		
		//判断3*3的小方格里面数字是否存在重复
		int startRow = (row / 3) * 3;
		int startCol = (col / 3) * 3;
		
		for(int i = startRow;i < startRow + 3;i++){
			for(int j = startCol;j < startCol + 3;j++){
				if(board[i][j] == val)
					return false;
			}
		}
		
		return true;
	}
	
	bool backTracking2(vector<vector<char>>& board){
		for(int i = 0;i < board.size();i++){
			for(int j = 0;j < board[0].size();j++){
				if(board[i][j] != '.') continue;//当前位置有数字存在
				for(char key = '0';key < '9';key++){
					if(isValid2(i,j,key,board)){
						
						board[i][j] = key;
						
						backTracking(board);
						
						board[i][j] = '.';
					}
				}
				return false;
			}
		}
		return false;
	}
	
	bool isValid2(int row,int col,char key,vector<vector<char>> &board){
		//检查当前行
		for(int i = 0;i < 9;i++){
			if(board[row][i] == key)
				return false;
		}
		
		//检查当前列
		for(int j = 0;j < 9;j++){
			if(board[j][col] == key)
				return false;
		}
		
		//检查3*3区域
		int startRow = (row / 3) * 3;
		int startCol = (col / 3) * 3;
		
		for(int i = 0;i < startRow + 3;i++){
			for(int j = 0;j < startCol + 3;j++){
				if(board[i][j] == key)
					return false;
			}
		}
		
		return true;
	}
	
	void solveSudoku(vector<vector<char>>& board) {
		backTracking(board);
	}
};
