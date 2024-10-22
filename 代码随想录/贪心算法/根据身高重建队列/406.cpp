#include <stdlib.h>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <list>

using namespace std;
//https://leetcode.cn/problems/queue-reconstruction-by-height/

class Solution {
public:
	
	
	//按照身高从大到小进行排列，如果身高相等，数量小的放前面
	static bool cmp(vector<int>& a,vector<int>& b){
		if(a[0] == b[0]) return a[1] < b[1];
		return a[0] > b[0];
	}
	
	vector<vector<int>> reconstructQueue1(vector<vector<int>>& people) {
		/**
		 * 身高从大到小排 身高相等的k小的站前面
		 * 局部最优：优先按照身高高的people按照k进行排序
		 * 全局最优：最后都做完插入操作，整个队列满足题目队列属性
		 */
		
		sort(people.begin(),people.end(),cmp);
		
		vector<vector<int>> que;
		for(int i = 0;i < people.size();i++){
			int postition = people[i][1];
			que.insert(que.begin() + postition,people[i]);
		}
		
		return que;
	}
	
	vector<vector<int>> reconstructQueue(vector<vector<int>>& people){
		sort(people.begin(),people.end(),cmp);
		
		list<vector<int>> que;
		
		for(int i = 0;i < people.size();i++){
			int postition = people[i][1];//插入到下标为position的位置
			auto it = que.begin();
			
			while(postition--){
				it++;
			}
			
			que.insert(it,people[i]);
		}
		
		return vector<vector<int>>(que.begin(),que.end());
	}
};
