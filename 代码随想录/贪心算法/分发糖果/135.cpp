#include <stdlib.h>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
//https://leetcode.cn/problems/candy/

class Solution {
public:
	int candy(vector<int>& ratings) {
		vector<int> candyVec(ratings.size(),1);//初始化
		
		//从前向后 比较右孩子大于左孩子评分的情况
		for(int i = 1;i < ratings.size();i++){
			if(ratings[i] > ratings[i - 1])
				candyVec[i] = candyVec[i - 1] + 1;
		}
		
		//从后向前
		for(int i = ratings.size() - 2;i >= 0;i--){
			if(ratings[i] > ratings[i + 1]){
				candyVec[i] = max(candyVec[i],candyVec[i + 1] + 1);
			}
		}
	
		
		int result = 0;
		for(int temp : candyVec)
			result += temp;
		
		return result;
	}
};

class Solution2{
public:
	int candy(vector<int>& ratings){
		vector<int> candyVec(ratings.size(),1);
		
		//从左到右
		for(int i = 1;i < ratings.size();i++){
			if(ratings[i] > ratings[i - 1])
				candyVec[i] = candyVec[i - 1] + 1;
		}
		
		//从右到左
		for(int i = ratings.size() - 2;i >= 0;i--){
			if(ratings[i] > ratings[i + 1]){
				candyVec[i] = max(candyVec[i + 1] + 1,candyVec[i]);
			}
		}
		
		int result = 0;
		for(int temp : candyVec)
			result += temp;
		
		return result;
	}
};
