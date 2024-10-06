#include <stdlib.h>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <limits.h>
#include <unordered_map>


using namespace std;

class Solution{
public:
	//27
	int removeElement(vector<int>& nums, int val) {
		int old = 0;
		int new1 = 0;
		int count = 0;
		for(;old < nums.size();old++){
			if(nums[old] != val){
				nums[new1++] = nums[old];
				count++;
			}
		}
		/**
		 * 时间复杂度o(n)
		 * 空间复杂度o(1)
		 */
		
		return count;
	}
	
	//977
	vector<int> sortedSquares1(vector<int>& nums) {
		vector<int> newArray(nums.size());
		for(int index = 0;index < nums.size();index++){
			newArray[index] = nums[index] * nums[index];
		}
		sort(newArray.begin(),newArray.end());
		return newArray;
	}
	vector<int> sortedSquares(vector<int>& nums){
		vector<int> result(nums.size());
		int head = 0;
		int tail = nums.size() - 1;
		int index = nums.size() - 1;
		for(;head <= tail;){
			if(nums[head] * nums[head] > nums[tail] * nums[tail]){
				result[index--] = nums[head] * nums[head];
				head++;
			} else{
				result[index--] = nums[tail] * nums[tail];
				tail--;
			}
		}
		return result;
	}
	
	//209
	int minSubArrayLen1(int target, vector<int>& nums) {
		//暴力做法
		int result = INT32_MAX;//记录最终的最小长度
		int sum = 0;//表示子区间之和
		for(int i = 0;i < nums.size();i++){
			sum = 0;
			for(int j = i;j < nums.size();j++){
				sum += nums[j];
				
				if(sum >= target){
					int subLen = j - i + 1;//子序列的长度
					result = result < subLen ? result : subLen;
					break;
				}
			}
		}
		
		return result == INT32_MAX ? 0 : result;
	}
	//滑动窗口
	int minSubArrayLen(int target, vector<int>& nums){
		int result = INT32_MAX;
		int sum = 0;
		for(int tail = 0,head = 0;tail < nums.size();tail++){
			sum += nums[tail];
			while(sum >= target){
				int subLen = tail - head + 1;//当前子序列的长度
				result = (result < subLen) ? result : subLen;
				sum -= nums[head];
				head++;
			}
		}
		return result == INT32_MAX ? 0 : result;
	}
	
	//904
	int totalFruit(vector<int>& fruits) {
		int result = INT32_MIN;
		unordered_map<int,int> fruit_map;
		for(int tail = 0,head = 0;tail < fruits.size();tail++){
			fruit_map[fruits[tail]]++;
			while(fruit_map.size() > 2){
				fruit_map[fruits[head]]--;//清楚左边界
				if(fruit_map[fruits[head]] == 0){
					fruit_map.erase(fruits[head]);//左边界水果数量为0，清楚出去
				}
				head++;
			}
			int subLen = tail - head + 1;
			result = result > subLen ? result : subLen;
		}
		return result;
	}
	
	//59
	vector<vector<int>> generateMatrix(int n) {
		if(n == 0) return {};
		
		int head = 0,tail = n - 1,left = 0,right = n - 1;
		vector<vector<int>> result(n,vector<int>(n));
		int i = 1;
		while(left <= right and head <= tail){
			for(int j = left;j <= right;j++){
				result[head][j] = i++;
			}
			head++;
			
			for(int j = head;j <= tail;j++){
				result[j][right] = i++;
			}
			right--;
			
			for(int j = right;j >= left;j--){
				result[tail][j] = i++;
			}
			tail--;
			
			for(int j = tail;j >= head;j--){
				result[j][left] = i++;
			}
			left++;
		}
		return result;
	}
	
	//58
	//bf
	void calculateSection(){
		int n;
		cin>>n;
		vector<int> nums(n);
		for(int i = 0;i < n;i++){
			int temp;
			cin>>temp;
			nums[i] = temp;
		}
		int left,right;
		cin>>left>>right;
		int sum = 0;
		for(int i = left;i <= right;i++){
			sum += nums[i];
		}
		cout<<sum;
	}
	/**
	 * o(n)时间复杂度
	 */
	
	//prefixSum
	void calculate2(){
		int n;
		cin>>n;
		vector<int> sum(n);
		int temp;
		cin>>temp;
		sum[0] = temp;
		for(int i = 1;i < n;i++){
			cin>>temp;
			sum[i] = temp + sum[i - 1];
		}
		int left,right;
		cin>>left>>right;
		cout<<sum[right] - sum[left - 1];
	}
	
	//44
	
};

int main(){
	int n,m;
	cin>>n>>m;
	int sum = 0;
	vector<vector<int>> vec(n,vector<int>(m,0));//n行m列
	for(int i = 0;i < n;i++){
		for(int j = 0;j < m;j++){
			cin>>vec[i][j];
			sum += vec[i][j];
		}
	}
	
	//统计横向
	vector<int> horizontal(n,0);
	for(int i = 0;i < n;i++){
		for(int j = 0;j < m;j++){
			horizontal[i] += vec[i][j];//统计每一行的元素之和
		}
	}
	
	//统计纵向
	vector<int> vertical(m,0);
	for(int j =0;j < m;j++){
		for(int i = 0;i < n;i++){
			vertical[j] += vec[i][j];
		}
	}
	
	int result = INT_MAX;
	//横向分割
	int horizontalCut = 0;
	for(int i = 0;i < n;i++){
		horizontalCut += horizontal[i];
		result = min(result,abs(sum - horizontalCut - horizontalCut));
	}
	
	int verticalCut = 0;
	for(int j = 0;j < m;j++){
		verticalCut += vertical[j];
		result = min(result,abs(sum - verticalCut - verticalCut));
	}
	
	cout<<result<<endl;
	
}
