#include <stdlib.h>
#include <iostream>

using namespace std;

//https://leetcode.cn/problems/sqrtx/

int mySqrt(int x) {
	int left = 0;
	int right = x;
	long mid;
	while (left <= right) {
		mid = left + (right - left) / 2;
		if(mid * mid == x){
			return mid;//精准匹配
		} else if(mid * mid > x){
			right = mid -1;
		} else { // mid * mid < x
			left = mid + 1;
		}
	}
	return right;
}

int main(){
	
	return 0;
}
