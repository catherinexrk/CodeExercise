#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <map>

using namespace std;

/**
 * 回溯法解决一下类型问题：
 * 1.组合问题：n个数里面按一定规则找出k个数的集合
 * 2.切割问题：一个字符串按一定规则有几种切割方式
 * 3.子集问题：一个n个数的集合里面有多少种符合条件的子集
 * 4.排列问题：n个数按照一定规则全排列，有几种排列方式
 * 5.棋盘问题：数独、n皇后
 */

/**
 * 组合问题
 */
class Solution{
public:
	vector<vector<int>> result;
	vector<int> path;
	
	void backTracking(int n,int k,int startIndex){
		if(path.size() == k){
			result.push_back(path);
			return;
		}
		
		for(int i = startIndex;i <= n - path.size() + 1;i++){
			path.push_back(i);
			backTracking(n,k,i + 1);
			path.pop_back();
		}
	}
	
	vector<vector<int>> combine(int n, int k) {
		backTracking(n,k,1);
		return result;
	}
};

class Solution2 {
public:
	vector<vector<int>> result;
	vector<int> path;
	int sum = 0;
	
	void backTracking(int n,int k,int startIndex){
		if(sum > n) return;
		if(sum == n && path.size() == k){
			result.push_back(path);
			return;
		}
		
		for(int i = startIndex;i <= 9 - (k - path.size()) + 1 && sum + i <= n;i++){
			sum += i;
			path.push_back(i);
			backTracking(n,k,i + 1);
			sum -= i;
			path.pop_back();
		}
	}
	
	vector<vector<int>> combinationSum3(int k, int n) {
		backTracking(n,k,1);
		return result;
	}
};


class Solution3{
public:
	vector<string> character = {
		"",//0
		"",//1
		"abc",//2
		"def",//3
		"ghi",//4
		"jkl", // 5
		"mno", // 6
		"pqrs", // 7
		"tuv", // 8
		"wxyz", // 9
	};
	vector<string> result;
	string s;
	
	void backTracking(string digits,int startIndex){
		if(startIndex == digits.size()){
			result.push_back(s);
			return;
		}
		
		int index = digits[startIndex] - '0';
		string letters = character[index];
		
		for(int i = 0;i < letters.size();i++){
			s.push_back(letters[i]);
			backTracking(digits,startIndex + 1);
			s.pop_back();
		}
	}
	
	
	vector<string> letterCombinations(string digits) {
		if(digits.size() == 0)
			return result;
		backTracking(digits,0);
		return result;
	}
};

//class Solution4{
//public:
//	vector<string> character = {
//		"",//0
//		"",//1
//		"abc",//2
//		"def",//3
//		"ghi",//4
//		"jkl", // 5
//		"mno", // 6
//		"pqrs", // 7
//		"tuv", // 8
//		"wxyz", // 9
//	};
//	
//	vector<string> result;
//	string s;
//	
//	void backTracking(vector<string> digits,int index){
//		if(index == digits.size()){
//			result.push_back(s);
//			return;
//		}
//		
//		int cur = digits[index] - '0';
//		string letter = character[cur];
//		
//		for(int i = 0;i < letter.size();i++){
//			s.push_back(letter[i]);
//			backTracking(digits,index + 1);
//			s.pop_back();
//		}
//	}
//	
//	
//	vector<string> letterCombinations(string digits) {
//		if(digits.size() == 0)
//			return result;
//		backTracking(digits,0);
//		return result;
//	}
//};

class Solution4{
public:
	vector<vector<int>> result;
	vector<int> path;
	int sum = 0;
	
	void backTracking(vector<int>& candidates,int target,int startIndex){
		if(sum > target) return;
		if(sum == target){
			result.push_back(path);
			return;
		}
		
		for(int i = startIndex;i < candidates.size();i++){
			
			sum += candidates[i];
			path.push_back(candidates[i]);
			
			//candidate中的数字可以被重复选取
			backTracking(candidates,target,i);
			
			sum -= candidates[i];
			path.pop_back();
		}
		
	}
	
	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		backTracking(candidates,target,0);
		return result;
	}
};

class Solution5{
public:
	vector<vector<int>> result;
	vector<int> path;
	int sum = 0;
	
	void backTracking(vector<int>& candidates,int target,int startIndex,vector<bool>& used){
		if(sum > target) return;
		if(sum == target){
			result.push_back(path);
			return;
		}
		
		for(int i = startIndex;i < candidates.size();i++){
			
			if(i > startIndex && candidates[i] == candidates[i - 1] && used[i] == false)
				continue;
			
			sum += candidates[i];
			path.push_back(candidates[i]);
			used[i] = true;//表示当前树枝被使用
			
			//candidate中的数字可以被重复选取
			backTracking(candidates,target,i + 1,used);
			
			sum -= candidates[i];
			path.pop_back();
			used[i] = false;
		}
		
	}
	
	vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
		sort(candidates.begin(),candidates.end());
		vector<bool> used(candidates.size(),false);
		backTracking(candidates,target,0,used);
		return result;
	}
};

class Solution6{
public:
	vector<vector<int>> result;
	vector<int> path;
	
	void baclTracking(string s,int startIndex){
		
	}
	
	
	vector<vector<string>> partition(string s) {
		
	}
	
};

/**
 * 子集问题不同于切割问题和组合问题，子集问题是要遍历所有节点，而后两个则是遍历叶子节点
 */
class Solution7{
public:
	vector<vector<int>> result;
	vector<int> path;
	
	void backTracking(vector<int>& nums,int startIndex){
		result.push_back(path);//收集子集，每次都要收集，收集所有的节点
		if(startIndex >= nums.size()){
			return;
		}
		
		for(int i = startIndex;i < nums.size();i++){
			path.push_back(nums[i]);
			backTracking(nums,i + 1);
			path.pop_back();
		}
		
	}
	
	
	
	vector<vector<int>> subsets(vector<int>& nums) {
		backTracking(nums,0);
		return result;
	}
};

class Solution8{
public:
	
	vector<vector<int>> result;
	vector<int> path;
	
	void backTracking(vector<int>& nums,int startIndex){
		result.push_back(path);
		if(startIndex >= nums.size())
			return;
		
		for(int i = startIndex;i < nums.size();i++){
			if(i > startIndex && nums[i] == nums[i - 1])
				continue;
			
			path.push_back(nums[i]);
			
			backTracking(nums,i + 1);
			
			path.pop_back();
		}
	}
	
	
	vector<vector<int>> subsetsWithDup(vector<int>& nums) {
		sort(nums.begin(),nums.end());
		backTracking(nums,0);
		return result;
	}
};

class Solution9{
public:
	
	vector<vector<int>> result;
	vector<int> path;
	
	void backTracking(vector<int>& nums,int startIndex){
		if(path.size() >= 2) 
			result.push_back(path);
		
		if(startIndex >= nums.size())
			return;
		
		unordered_set<int> used;//使用set对本层元素进行去重
		for(int i = startIndex;i < nums.size();i++){
			if(i > startIndex && nums[i] == nums[i - 1])
				continue;
			
			if(used.find(nums[i]) != used.end())
				continue;
			
			if(!path.empty() && path.back() <= nums[i]){
				path.push_back(nums[i]);
				used.insert(nums[i]);
				
				backTracking(nums,i + 1);
				
				path.pop_back();
			}
		}
	}
	
	
	vector<vector<int>> findSubsequences(vector<int>& nums) {
		backTracking(nums,0);
		return result;
	}
};

class Solution10{
public:
	vector<vector<int>> result;
	vector<int> path;
	
	void backTracking(vector<int>& nums,vector<bool>& used){
		if(path.size() == nums.size()){
			result.push_back(path);
			return;
		}
		
		for(int i = 0;i < nums.size();i++){
			if(used[i] == true) continue;
			
			used[i] = true;
			path.push_back(nums[i]);
			backTracking(nums,used);
			path.pop_back();
			used[i] = false;
		}
	}
	
	
	vector<vector<int>> permute(vector<int>& nums) {
		vector<bool> used(nums.size(),false);
		backTracking(nums,used);
		return result;
	}
};

class Solution11 {
public:
	vector<vector<int>> result;
	vector<int> path;
	
	void backTracking(vector<int>& nums,vector<bool> used){
		if(path.size() == nums.size()){
			result.push_back(path);
			return;
		}
		
		for(int i = 0;i < nums.size();i++){
			//used[i - 1] == true 说明同一数值nums[i - 1]使用过
			//used[i - 1] == false 说明同一树层nums[i - 1]使用过
			if(i > 0 && nums[i] == nums[i - 1] && used[i - 1] == false)
				continue;
			
			if(used[i] == false){
				used[i] = true;
				path.push_back(nums[i]);
				
				backTracking(nums,used);
				
				used[i] = false;
				path.pop_back();
			}
		}
	}
	
	vector<vector<int>> permuteUnique(vector<int>& nums) {
		sort(nums.begin(),nums.end());
		vector<bool> used(nums.size(),false);
		backTracking(nums,used);
		return result;
	}
};

class Solution12 {
public:
	vector<vector<string>> result;
	
	//n棋盘大小 row表示当前遍历到棋盘的第几层
	void backTracking(int n,int row,vector<string>& chessboard){
		if(row == n){
			result.push_back(chessboard);
			return;
		}
		
		for(int col = 0;col < n;col++){
			if(isValid(row,col,chessboard,n)){
				chessboard[row][col] = 'Q';//放置Q皇后
				backTracking(n,row + 1,chessboard);
				chessboard[row][col] = '.';//回溯，撤销皇后
			}
		}
	}
	
	bool isValid(int row,int col,vector<string> &chessborad,int n){
		//检查列
		for (int i = 0; i < row; i++) { 
			if (chessborad[i][col] == 'Q') {
				return false;
			}
		}
		
		//检查45°
		for(int i = row - 1,j = col - 1;i >= 0 && j >= 0;i--,j--){
			if(chessborad[i][j] == 'Q')
				return false;
		}
		
		//检查145°
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

class Solution13{
public:
	vector<vector<string>> result;
	
	//n表示棋盘的规格，row表示当前行数，chessborad表示当前棋盘的内容
	void backTracking(int n,int row,vector<string>& chessboard){
		if(row == n){
			result.push_back(chessboard);
			return;
		}
		
		for(int col = 0;col < n;col++){
			if(isValid(row,col,chessboard,n)){
				//放置皇后
				chessboard[row][col] = 'Q';
				//开启下一层的皇后放置
				backTracking(n,row + 1,chessboard);
				//皇后回溯
				chessboard[row][col] = '.';
			}
		}
	}
	
	bool isValid(int row,int col,vector<string>& chessboard,int n){
		//检查列
		for(int i = 0;i < row;i++){
			if(chessboard[i][col] == 'Q')
				return false;
		}
		
		//检查左上角
		for(int i = row - 1,j = col - 1;i >= 0 && j >=0;i--,j--){
			if(chessboard[i][j] == 'Q')
				return false;	
		}
		
		//检查右上角
		for(int i = row - 1,j = col + 1;i >= 0 && j < n;i--,j++){
			if(chessboard[i][j] == 'Q')
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

class Solution14{
public:
	bool backTracking(vector<vector<char>>& board){
		
		//遍历行
		for(int i = 0;i < board.size();i++){
			//遍历列
			for(int j = 0;j < board[0].size();j++){
				if(board[i][j] != '.')
					continue;
				
				for(char key = '1';key <= '9';key++){
					if(isValid(i,j,key,board)){
						board[i][j] = key;
						
						if(backTracking(board))
							return true;
						
						board[i][j] = '.';
					}
				}
				//一层1->9都不能匹配，则返回false
				return false;
			}
		}
		return true;
	}
	
	bool isValid(int row,int col,char key,vector<vector<char>>& board){
		//判断行是否重复
		for(int i = 0;i < 9;i++){
			if(board[row][i] == key)
				return false;
		}
		
		//检查列是否重复
		for(int j = 0;j < 9;j++){
			if(board[j][col] == key)
				return false;
		}
		
		int startRow = row / 3 * 3;
		int startCol = col / 3 * 3;
		
		for(int i = startRow;i < 3;i++){
			for(int j = startCol;j < 3;j++){
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
