#include <stdlib.h>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
//https://leetcode.cn/problems/lemonade-change/

class Solution {
public:
	bool lemonadeChange(vector<int>& bills) {
		//1.账单是5，直接收下
		//2.账单是10，消耗一个5，增加一个10
		//3.账单是20，优先消耗一个10一个一个5，如果不够，直接消耗3个5
		
		int five = 0,ten = 0,twenty = 0;
		for(int bill : bills){
			//情况1
			if(bill == 5) five++;
			
			//情况2
			if(bill == 10){
				if(five <= 0)
					return false;//无法找零
				ten++;
				five--;
			}
			
			//情况3
			if(bill == 20){
				//优先消耗10，然后再5
				if(five > 0 && ten > 0){
					five--;
					ten--;
					twenty++;
				} else if(five >= 3){
					five -= 3;
					twenty++;
				} else 
					return false;
			}
		}
		
		return true;
	}
};


class Solution2 {
public:
	bool lemonadeChange(vector<int>& bills) {
		int five = 0,ten = 0;
		for(int bill : bills){
			if(bill == 5)
				five++;
			if(bill == 10){
				if(five > 0){
					five--;
					ten++;
				} else{
					return false;
				}
			}
			
			if(bill == 20){
				if(ten > 0 && five > 0){
					ten--;
					five--;
				} else if(five >= 3){
					five -= 3;
				} else{
					return false;
				}
			}
		}
		
		return true;
	}
};
