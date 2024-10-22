#include <stdlib.h>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
//https://leetcode.cn/problems/gas-station/

class Solution {
public:
	//已经超时
	int canCompleteCircuitBF(vector<int>& gas, vector<int>& cost) {
		//bf
		for(int i = 0;i <cost.size();i++){
			int rest = gas[i] - cost[i];//油箱剩余数量
			int index = (i + 1) % cost.size();//表示汽车下一站的加油站序号
			
			//模拟以i为起点行驶一圈，如果rest==0，此时答案不唯一
			while(rest > 0 && index != i){ 
				rest += gas[index] - cost[index];
				index = (index + 1) % cost.size();
			}
			
			//此时以i为起点跑一圈，剩余油量>=0，返回该起始位置
			if(rest >= 0 && index == i)
				return i;
		}
		
		return -1;
	}
	
	int canCompleteCircuit1(vector<int>& gas, vector<int>& cost) {
		/**
		 * 1.如果gas总和小于cost总和，说明无论怎么走都不行
		 * 2.rest[i] = gas[i] - cost[i]，如果i从0开始累加到最后一站，如果累加没有出现负数，
		 * 	则说明从0开始，油就没断过，可以一直跑，因此0是起点
		 * 3.如果累加值和是负数，则汽车从非0开始出发，从后向前看，如果哪个节点可以把这个负数填平
		 * 	能把这个负数填平的节点就是出发节点
		 */
		
		int curSum = 0;
		int min = INT_MAX;//从起点出发，油箱里的最小值
		for(int i = 0;i < gas.size();i++){
			int rest = gas[i] - cost[i];
			curSum += rest;
			
			if(curSum < min){
				min = curSum;
			}
		}
		
		if(curSum < 0) return -1;//情况1
		if(min >= 0) return 0;//情况2
		//情况3
		if(min < 0){
			for(int i = gas.size() - 1;i >= 0;i--){
				int rest = gas[i] - cost[i];
				min += rest;
				if(min >= 0){
					return i;
				}
			}
			
			return -1;
		}
	}
	
	int canCompleteCircuit2(vector<int>& gas, vector<int>& cost) {
		int curSum = 0;
		int min = INT_MAX;
		
		for(int i = 0;i < gas.size();i++){
			curSum += gas[i] - cost[i];
			
			//找到当前油量的最小值
			if(min > curSum){
				min = curSum;
			}
		}
		
		if(curSum < 0) return -1;
		if(min >= 0) return 0;
		else{
			for(int i = gas.size() - 1;i >= 0;i--){
				int rest = gas[i] - cost[i];
				min += rest;
				
				if(min >= 0){
					return i;
				}
			}
			return -1;
		}
		
		return -1;
	}
	
	int canCompleteCircuit(vector<int>& gas, vector<int>& cost){
		
	}
};

class Solution2 {
public:
	//已经超时
	int canCompleteCircuitBF(vector<int>& gas, vector<int>& cost) {
		for(int i = 0;i < cost.size();i++){
			int rest = gas[i] - cost[i];
			int index = (i + 1) % cost.size();
			
			while(rest >= 0 && index != i){
				rest = gas[index] - cost[index];
				index = (index + 1) % cost.size();
			}
			
			if(rest >= 0 && index == i)
				return i;
		}
		
		//不能返回起点
		return -1;
	}
};
