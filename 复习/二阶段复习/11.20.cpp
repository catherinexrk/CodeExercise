#include <bits/stdc++.h>

using namespace std;

class Solution{
	int search(vector<int>& nums, int target){
		int left = 0,right = nums.size() - 1;
		while(left <= right){
			int mid = left + (right - left) / 2;
			
			if(nums[mid] == target){
				return mid;
			} else if(nums[mid] < target){
				left = mid + 1;
			} else {
				right = mid - 1;
			}
		} 
		return -1;
	}
	
	bool isPerfectSquare(int num) {
		for(int damn = 1;damn < num;damn++){
			if(damn * damn == num){
				return true;
			} else if(damn * damn > num){
				return false;
			} 
			
		}
		return false;
	}
	
	bool isPerfectSquareBinary(int num){
		int left = 0;
		int right = num;
		while(left <= right){
			int mid = left + (right - left) / 2;
			
			if(mid * mid == num){
				return true;
			} else if(mid * mid < num){
				left = mid + 1;
			} else{
				right = mid - 1;
			}
		}
		return false;
	}
	
	int mySqrt(int x) {
		int left = 0,right = x;
		while(left <= right){
			long long mid = left + (right - left)/2;
			
			if(mid * mid == x){
				return mid;
			} else if(mid * mid < x){
				left = mid + 1;
			} else{
				right = mid - 1;
			}
		}
		
		return right;
	}
	
	int removeElement(vector<int>& nums, int val) {
		int count = 0;
		
		int fast = 0,slow = 0;
		for(;fast < nums.size();fast++){
			if(nums[fast] != val){
				nums[slow++] = nums[fast];
			} else {
				count++;
			}
		}
		
		//去除val数值后的nums数组
		nums.resize(slow);
		
		return nums.size() - count;
	}
	
	int removeDuplicates(vector<int>& nums) {
		int count = 0;
		int fast = 1,slow = 0;
		
		while(fast < nums.size()){
			if(nums[slow] != nums[fast]){
				slow++;
				nums[slow] = nums[fast];
			}
			fast++;
		}
		
		return slow + 1;
	}
	
	void moveZeroes(vector<int>& nums) {
		int slow = 0,fast = 0;
		while(fast < nums.size()){
			if(nums[fast] != 0){
				nums[slow++] = nums[fast];
			}
			fast++;
		}
		
		while(slow < nums.size()){
			nums[slow++] = 0;
		}
	}
	
	vector<int> sortedSquares(vector<int>& nums) {
		for(int i = 0;i < nums.size();i++){
			nums[i] = nums[i] * nums[i];
		}
		
		sort(nums.begin(),nums.end());
		return nums;
	}
	
	vector<int> sortedSquaresGPT(vector<int>& nums){
		vector<int> newArray(nums.size());
		int left = 0,right = nums.size() - 1;
		int loc = nums.size() - 1;
		
		while(left <= right){
			int leftSquare = nums[left] * nums[left];
			int rightSquare = nums[right] * nums[right];
			
			if (leftSquare > rightSquare) {
				newArray[loc--] = leftSquare;
				left++;
			} else {
				newArray[loc--] = rightSquare;
				right--;
			}
		}
		
		return newArray;
	}
	
	string shearString(const string& str){
		stack<char> st;
		for(char temp : str){
			if(temp == '#'){
				if(!st.empty()){
					st.pop();
				}
			} else {
				st.push(temp);
			}
		}
		
		string shearStr;
		while(!st.empty()){
			shearStr += st.top();
			st.pop();
		}
		
		return shearStr;
	}
	
	bool backspaceCompare(string s, string t) {
		s = shearString(s);
		t = shearString(t);
		
		return s == t;
	}
};

