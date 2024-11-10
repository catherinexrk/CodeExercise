#include <stdlib.h>
#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
#include <vector>

using namespace std;
//https://leetcode.cn/problems/largest-rectangle-in-histogram/

class Solution {
public:
	int largestRectangleArea(vector<int>& heights) {
		int result = 0;
		stack<int> st;
		// 将数组头部加入 0
		heights.insert(heights.begin(), 0);
		// 尾部加入 0
		heights.push_back(0);
		
		st.push(0);
		
		// st 递减排序
		// 寻找左右均小于当前柱子的左右下标
		for (int i = 1; i < heights.size(); i++) {
			if (heights[i] > heights[st.top()]) {
				st.push(i);
			} else if (heights[i] == heights[st.top()]) {
				st.pop();
				st.push(i);
			} else {
				while (!st.empty() && heights[i] < heights[st.top()]) {
					int mid = st.top();
					st.pop();
					if (!st.empty()) {
						// 计算左边界，确保左边界是严格小于当前弹出柱子高度的第一个柱子的下标加一
						int left = st.top() + 1;
						int right = i - 1;
						int w = right - left + 1;
						int h = heights[mid];
						result = max(result, h * w);
					}
				}
				st.push(i);
			}
		}
		
		return result;
	}
	
	int damn(vector<int> & height){
		stack<int> st;
		height.push_back(0);
		height.insert(height.begin(),0);
		st.push(0);
		
		int result = 0;
		
		for(int i = 1;i < height.size();i++){
			if(height[i] > height[st.top()]){
				st.push(i);
			} else if(height[i] == height[st.top()]){
				st.pop();
				st.push(i);
			} else {
				while(!st.empty() && height[i] < height[st.top()]){
					int mid = st.top;
					st.pop();
					if(!st.empty()){
						int left = st.top();
						int right = i;
						int w = right - left + 1;
						int h = height[mid];
						result = max(result,h * w);
					}
				}
				st.push(i);
			}
		}
		
		return result;
	}
	
	int bf(vector<int>& heights) {
		int sum = 0;
		for (int i = 0; i < heights.size(); i++) {
			int left = i;
			int right = i;
			for (; left >= 0; left--) {
				if (left == 0 || heights[left - 1] < heights[i])
					break;
			}
			for (; right < heights.size(); right++) {
				if (right == heights.size() - 1 || heights[right + 1] < heights[i])
					break;
			}
			int w = right - left + 1;
			int h = heights[i];
			sum = max(sum, w * h);
		}
		return sum;
	}
	
};
