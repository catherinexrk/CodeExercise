#include <stdlib.h>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <list>

using namespace std;
//https://leetcode.cn/problems/merge-intervals/

class Solution {
public:
	static bool cmp(const vector<int>& a,const vector<int>& b){
		return a[0] < b[0];
	}
	
	vector<vector<int>> merge(vector<vector<int>>& intervals) {
		if(intervals.size() <= 1)
			return intervals;
		
		vector<vector<int>> result;
		
		sort(intervals.begin(),intervals.end(),cmp);
		int leftEnd = intervals[0][0];//左边界
		int rightEnd = intervals[0][1];//右边界
		
		for(int i = 1;i < intervals.size();i++){
			if(intervals[i][0] <= rightEnd){
//				rightEnd = max(rightEnd,intervals[i][1]);
//				leftEnd = min(leftEnd,intervals[i][0]);
//				result.push_back({leftEnd,rightEnd});
				rightEnd = max(rightEnd,intervals[i][1]);//更新右边界，但是不插入，避免重复
			} else{
				//不重叠的情况下，将前一个合并的区间加入结果
				result.push_back({leftEnd,rightEnd});
				
				leftEnd = intervals[i][0];
				rightEnd = intervals[i][1];
			}
		}
		//调用到最后一个区间的时候，没有其余区间和这个相重叠匹配
		result.push_back({leftEnd,rightEnd});
		
		return result;
	}
};
