#include <stdlib.h>
#include <vector>
#include <iostream>
#include <cstdint>
#include <unordered_map>
using namespace std;

//https://leetcode.cn/problems/fruit-into-baskets/description/

class Solution {
public:
	int totalFruit(vector<int>& fruits) {
		unordered_map<int,int> basket;//哈希表存储不同种类的水果其不同的数量，键值对方式存储
		int left,maxQuantity;//left为左边界，进行滑动；maxQuantity为当前手机到的水果的最大数量
		for(int right = 0;right < fruits.size();right++){
			//right为右边界，其进行滑动
			basket[fruits[right]]++;//如果当前basket中无当前水果，则初始化其数量为1
			
			while(basket.size() > 2){
				basket[fruits[left]]--;//水果种类大于2，去除左边界的水果
				if(basket[fruits[left]] == 0){
					//当前左边界水果数量为0，从哈希表中删除
					basket.erase(fruits[left]);
				}
				left++;//左边界向右挪动，进行滑动
			}
			
			maxQuantity = max(maxQuantity,right-left+1);//试试更新最大数量
		}
		return maxQuantity;
	}
};
