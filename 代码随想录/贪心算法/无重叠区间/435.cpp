#include <stdlib.h>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <list>

using namespace std;
//https://leetcode.cn/problems/non-overlapping-intervals/

class Solution {
public:
	static bool cmp(const vector<int>&a,const vector<int>&b){
		return a[0] < b[0];
	}
	
	int eraseOverlapIntervals1(vector<vector<int>>& intervals) {
		if(intervals.size() <= 1) 
			return 0;
		
		int result = 0;
		
		sort(intervals.begin(),intervals.end(),cmp);
		int lastEnd = intervals[0][1];//最近的一次右边界
		
		for(int i = 1;i < intervals.size();i++){
			if(intervals[i][0] < lastEnd ){
				result++;
				//此时更新边界信息
				lastEnd = min(lastEnd,intervals[i][1]);
			} else{
				lastEnd = intervals[i][1];
			}
		}
		
		return result;
	}
	
	int eraseOverlapIntervals(vector<vector<int>>& intervals){
		if(intervals.size() <= 1)
			return 0;
		
		int result = 0;
		sort(intervals.begin(),intervals.end(),cmp);
		
		int lastEnd = intervals[0][1];
		
		for(int i = 1;i < intervals.size();i++){
			if(intervals[i][0] < lastEnd){
				result ++;
				lastEnd = min(lastEnd,intervals[i][1]);
			} else{
				lastEnd = intervals[i][1];
			}
		}
		
		return result;
	}
};
