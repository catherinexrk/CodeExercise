#include <stdlib.h>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <list>

using namespace std;
//https://leetcode.cn/problems/minimum-number-of-arrows-to-burst-balloons/

/**
 * 首先是对气球进行排序，按照左边界的大小进行排序
  
  接着开始对气球进行遍历
  如果存在说当前气球的左边界<上一个气球的右边界，说明此时气球有重叠，此时count不变，但是要对当前气球的右边界进行修改，改成当前气球的右边界和上一个气球的右边界的最小值
  
  反之另一情况，两个气球没overlap，因此count++
 */
class Solution {
public:
	/**
	 * 局部最优：气球出现重叠，一起射，所用弓箭最小
	 * 全局最优：把所有气球射爆所用弓箭最小
	 */
	static bool cmp(const vector<int>&a,const vector<int>&b){
		return a[0] < b[0];//按照数组的左边界大小进行排序
	}
	
	int findMinArrowShots1(vector<vector<int>>& points) {
		if(points.size() == 0) 
			return 0;
		
		int count = 1;//表示射出的最小弓箭数量
		//对气球的左边界进行排序
		sort(points.begin(),points.end(),cmp);
		
		//开始进行边界比较
		for(int i = 1;i < points.size();i++){
			//当i的左边界大于i-1的右边界时，对count进行+1操作
			if(points[i][0] > points[i - 1][1]){
				count++;//表示要多射出一发弓箭
			} else{
				//气球有重叠，此时更新当前i气球的右边界 = i-1气球的左边界
				points[i][1] = min(points[i][1],points[i - 1][1]);
			}
		}
		
		return count++;
	}
	
	int findMinArrowShots(vector<vector<int>>& points){
		if(points.size() == 0)
			return 0;
		
		sort(points.begin(),points.end(),cmp);
		int result = 1;
		
		int lastEnd = points[0][1];
		
		for(int i = 1;i < points.size();i++){
			if(points[i][0] <= lastEnd){
				lastEnd = min(lastEnd,points[i][1]);
			} else{
				result++;
				lastEnd = points[i][1];
			}
		}
		
		return result;
	}
};
