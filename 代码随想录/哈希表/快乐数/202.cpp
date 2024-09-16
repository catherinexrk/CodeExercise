#include <stdlib.h>
#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;
//https://leetcode.cn/problems/happy-number

class Solution {
public:
	bool isHappy(int n) {
		//找到问题的关键，无限循环，是不是意味着只要出现了重复的sum
		//就可以断定不符合
		unordered_set<int> sumTotal;//存储每一次的sum
		
		//先是将n分解成若干个数字，然后再进行平方和，然后将平方和存储在sumTotal中
		long sum = 0;
		
		while(true){
			while(n != 0){
				int damn = n % 10;//获取个位
				sum += damn * damn;
				n /= 10;
			}
			if(sumTotal.find(sum) != sumTotal.end()){
				return false; //发现了循环，说明这辈子都不可能等于1
			} else{
				if(sum == 1){
					return true;
				}
				sumTotal.insert(sum);//保存每次的求和
			}
			n = sum;
			sum = 0;
		}
		return false;
		
		//时间复杂度
	}
};

