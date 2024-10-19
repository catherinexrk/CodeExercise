#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_set>
#include <map>

using namespace std;
//https://leetcode.cn/problems/reconstruct-itinerary/

class Solution {
public:
	//unordered_map<出发机场,map<到达机场,航班次数>> targets
	//unordermap存储从某个机场出发的目的地机场及对应航班的次数
	//map:内层的mao按字典序存储到达目的地机场，并记录从出发机场到达目的地的航班次数
	unordered_map<string,map<string,int>> targets;
	
	bool backTracking(int ticketNum,vector<string>& result){		
		//回溯过程中，遇到的机场个数，如果达到了（航班数量 + 1）,便找到了一个行程，将所有的航班串起来了
		if(result.size() == ticketNum + 1){
			return true;
		}
		
		for(auto& target : targets[result[result.size() - 1]]){
			if(target.second > 0){ //记录飞机是否飞过了
				result.push_back(target.first);
				target.second--;
				if(backTracking(ticketNum,result)) 
					return true;
				result.pop_back();
				target.second++;
			}
		}
		return false;
	}
	
	
	vector<string> findItinerary(vector<vector<string>>& tickets) {
		vector<string> result;	
		for(const vector<string>& vec : tickets){
			targets[vec[0]][vec[1]]++;//记录映射关系
		}
		result.push_back("JFK");
		
		backTracking(tickets.size(),result);
		return result;
	}
};
