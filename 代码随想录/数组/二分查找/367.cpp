#include <stdlib.h>
#include <iostream>

using namespace std;

//https://leetcode.cn/problems/valid-perfect-square/description/

bool isPerfectSquare1(int num) {
	//暴力解题
	long long temp;
	for(temp = 1;;temp++){
		if(temp * temp == num){
			return true;
		} 
		if(temp * temp > num){
			return false;
		}
	}
	return false;
}

bool isPerfectSquare(int num){
	int left = 0;
	int right = num;
	long mid;
	while(left <= right){
		mid = left + (right - left)/2;
		if(mid * mid == num){
			return true;
		} else if(mid * mid < num){
			left = mid + 1; 
		} else{
			right = mid - 1;
		}
	}
	return false;
}
