#include <stdlib.h>
#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
#include <vector>

using namespace std;
//https://leetcode.cn/problems/trapping-rain-water/

class Solution {
public:
	int trapBF(vector<int>& height) {
		//暴力求解，纵向求值
		int sum = 0;
		for(int i = 0;i < height.size();i++){
			//第一根柱子和最后一根柱子不接雨水
			if(i == 0 || i == height.size() - 1)
				continue;
			
			int rHeight = height[i];//记录右柱子的最高高度
			int lHeight = height[i];//记录左柱子的最高高度
			
			for(int r = i + 1;r < height.size();r++){
				rHeight = max(height[r],rHeight);
			}
			
			for(int l = i - 1;l >= 0;l--){
				lHeight = max(height[l],lHeight);
			}
			
			int h = min(lHeight,rHeight) - height[i];
			if(h > 0)
				sum += h;
		}
		
		return sum;
	}
	
	int trapBF2(vector<int>& height){
		int sum = 0;
		for(int i = 0;i < height.size();i++){
			if(i == 0 || i == height.size() - 1)
				continue;
			
			int lHeight = height[i];
			int rHeight = height[i];
			
			for(int r = i + 1;r < height.size();i++){
				rHeight = max(rHeight,height[r]);
			}
			
			for(int l = i - 1;l >= 0;l--){
				lHeight = max(lHeight,height[l]);
			}
			
			int h = min(lHeight,rHeight) - height[i];
			if(h > 0)
				sum += h;
		}
		
		return sum;
	}
	
	int trapDualPointer(vector<int>& height) {
		if(height.size() <= 2)
			return 0;
		vector<int> maxLeft(height.size(),0);
		vector<int> maxRight(height.size(),0);
		int size = height.size();
		
		//记录每个柱子左边柱子的最大高度
		maxLeft[0] = height[0];
		for(int i = 1;i < size;i++){
			maxLeft[i] = max(height[i],maxLeft[i - 1]);
		}
		
		//记录每个柱子右边柱子的最大高度
		maxRight[size - 1] = height[size - 1];
		for(int i = size - 2;i >= 0;i--){
			maxRight[i] = max(height[i],maxRight[i + 1]);
		}
		
		//求和
		int sum = 0;
		for(int i = 0;i < size;i++){
			int count = min(maxLeft[i],maxRight[i]) - height[i];
			if(count > 0)
				sum += count;
		}
		
		return sum;
	}
	
	int trapDual2(vector<int>& height){
		if(height.size() <= 2)
			return 0;
		vector<int> maxLeft(height.size(),0);
		vector<int> maxRight(height.size(),0);
		
		int size = height.size();
		
		maxLeft[0] = height[0];
		for(int i = 1;i < size;i++){
			maxLeft[i] = max(maxLeft[i - 1],height[i]);
		}
		
		maxRight[size - 1] = height[size - 1];
		for(int i = size - 2;size >= 0;size--){
			maxRight[i] = max(maxRight[i + 1],height[i]);
		}
		
		int sum = 0;
		for(int i = 0;i < size;i++){
			int count = min(maxLeft[i],maxRight[i]) - height[i];
			if(count > 0)
				sum += count;
		}
		return sum;
	}
	
	/**
	 * 寻找任意一个元素其左边最大值和右边最大值，使用单调栈取寻找
	 */
	int trap(vector<int>& height) {
		if (height.size() <= 2)
			return 0;
		
		stack<int> st;
		st.push(0);
		
		int sum = 0;
		for (int i = 1; i < height.size(); i++) {
			if (height[i] < height[st.top()]) {
				st.push(i);
			} else if (height[i] == height[st.top()]) {
				//更新边界，相同柱子高度的时候及时更新最新的柱子下标
				st.pop();
				st.push(i);
			} else {
				while (!st.empty() && height[i] > height[st.top()]) {
					int mid = st.top();//获得了当前下标
					st.pop();//弹出，此时栈顶元素是左边界柱子的下标
					if (!st.empty()) {
						int leftHeight = st.empty()? 0 : height[st.top()];
						int h = min(leftHeight, height[i]) - height[mid];
						int w = i - st.top() - 1;
						sum += h * w;
					}
				}
				st.push(i);
			}
		}
		return sum;
	}
	
	int trap2(vector<int>& height){
		if(height.size() <= 2)
			return 0;
		
		stack<int> st;
		st.push(0);
		int sum = 0;
		
		for(int i = 1;i < height.size();i++){
			if(height[i] < height[st.top()]){
				st.push(i);
			} else if(height[i] == height[st.top()]){
				st.pop();
				st.push(i);
			} else{
				while(!st.empty() && height[i] > height[st.top()]){
					int mid = st.top();
					st.pop();
					if(!st.empty()){
						int leftHeight = height[st.top()];
						int h = min(height[st.top()],leftHeight) - height[mid];
						int w = i - st.top() - 1;
						sum += h * w;
					}
				}
			}
		}
		
		return sum;
	}
};
