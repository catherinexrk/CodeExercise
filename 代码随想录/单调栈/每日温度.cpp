#include <stdlib.h>
#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
#include <vector>

using namespace std;
//https://leetcode.cn/problems/daily-temperatures/

class Solution {
public:
	vector<int> dailyTemperaturesBF(vector<int>& temperatures) {
		vector<int> answer(temperatures.size(),0);
		
		for(int i = 0;i < temperatures.size();i++){
			for(int j = i + 1;j < temperatures.size();j++){
				if(temperatures[j] > temperatures[i]){
					int count = j - i;//记录间隔天数
					answer[i] = count;
					break;
				}
			}
		}
		
		return answer;
	}
	
	vector<int> dailyTemperatures(vector<int>& temperatures) {
		vector<int> answer(temperatures.size(),0);
		
		stack<int> monotonousStack;
		
		for(int i  = 0;i < temperatures.size();i++){
			if(monotonousStack.size() == 0){
				monotonousStack.push(i);//将下标塞入
			} else{
				if(temperatures[i] <= temperatures[monotonousStack.top()]){
					monotonousStack.push(i);
				} else{
					while(!monotonousStack.empty() && temperatures[i] > temperatures[monotonousStack.top()]){
						answer[monotonousStack.top()] = i - monotonousStack.top();
						monotonousStack.pop();
					}
					
					monotonousStack.push(i);
				}
			}
		}
		
		return answer;
	}
	
	vector<int> damn(vector<int>& temperatures){
		vector<int> result(temperatures.size(),0);
		stack<int> st;
		
		for(int i = 0;i < temperatures.size();i++){
			if(st.size() == 0){
				st.push(i);
			} else{
				if(temperatures[i] <= temperatures[st.top()]){
					st.push(i);
				} else{
					while(!st.empty() && temperatures[i] > temperatures[st.top()]){
						result[st.top()] = i - st.top();
						st.pop();
					}
					
					st.push(i);
				}
			}
		}
		
		return result;
	}
};

