#include <bits/stdc++.h>

using namespace std;

class Solutiob1{
	//242
	bool isAnagram(string s, string t) {
		/**
		 * 说下思路，可以创建一个map存储s中的字符出现的频率，然后遍历t，--处理字符的数量
		 * 然后判断整个map的元素是否都为0，如果是ok，反之，不ok
		 */
		unordered_map<char,int> countMap;
		for(char temp : s){
			countMap[temp]++;
		}
		for(char temp : t){
			countMap[temp]--;
		}
		for(auto it : countMap){
			if(it.second != 0){
				return false;
			}
		}
		return true;
	}
	
	bool func(string s,string t){
		if(s.length() != t.length()) return false;
		vector<int> count(26,0);
		for(int i = 0;i < s.length();i++){
			count[s[i] - 'a']++;
			count[t[i] - 'a']--;
		}
		for(auto temp : count){
			if(temp != 0) return false;
		}
		return true;
	}
};

class Solution2{
public:
	vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
		unordered_set<int> countSet;
		for(auto temp:nums1){
			for(int i = 0;i < nums2.size();i++){
				if(temp == nums2[i]) countSet.insert(temp);
			}
		}
		return vector<int>(countSet.begin(),countSet.end());
	}
	
	vector<int> intersection1(vector<int>& nums1, vector<int>& nums2){
		unordered_set<int> set1;
		unordered_set<int> result;
		
		for(auto temp : nums1){
			set1.insert(temp);
		}
		
		for(auto temp : nums2){
			if(set1.find(temp) != set1.end()){
				result.insert(temp);
			}
		}
		
		return vector<int>(result.begin(),result.end());
	}
};

class Solutiob3{
public:
	bool isHappy1(int n) {
		/**
		 * 简单说下思路好吧，他的意思是只要不是无限循环，最终都会变成1
		 * 创建一个set存储，如果find了，ok，return false
		 */
		
		unordered_set<int> array;
		int sum = 0;
		//1.一个循环，求n的不断变化
		while(sum != 1){
			sum = 0;
			
			while(n > 10){
				int temp = n % 10;
				sum += temp * temp;
				n /= 10;
			}
			//此时新的sum
			if(array.find(sum) != array.end()){
				return false;//出现重复元素
			}
			
			array.insert(sum);//更新新的元素
			if(sum == 1) return true;
			n = sum;
		}
		return false;
	}
	
	
	bool isHappy(int n){
		unordered_set<int> set;
		while(true){
			int sum = 0;
			while(n > 0){
				int temp = n % 10;
				sum += temp * temp;
				n /= 10;
			}
			if(set.find(sum) != set.end()) return false;
			set.insert(sum);
			if(sum == 1) return true;
			n = sum;
		}
	}
};


class Solutiob4{
public:
	vector<int> twoSum1(vector<int>& nums, int target) {
		unordered_set<int> result;
		for(int i = 0;i < nums.size();i++){
			for(int j = i + 1;j < nums.size();j++){
				if(nums[i] + nums[j] == target){
					result.insert(i);
					result.insert(j);
					break;
				}
			}
		}
		return vector<int>(result.begin(),result.end());
	}
	
	vector<int> twoSum(vector<int>& nums, int target) {
		unordered_map<int,int> map;
		for(int i = 0;i < nums.size();i++){
			auto iter = map.find(target - nums[i]);
			if(iter != map.end()){
				return {i,iter->second};
			}
			map.insert(pair<int,int>(nums[i],i));//存入键值对<数值,index>
		}
		return {};
	}
	
};

class Solutiob5{
public:
	int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
		//两两数组相结合
		unordered_map<int,int> map1;
		for(int n1 : nums1){
			for(int n2 : nums2){
				map1[n1 + n2]++;//存储n1和n2的之和出现的次数
			}
		}
		int count = 0;
		for(int n3 : nums3){
			for(int n4 : nums4){
				if(map1.find(0 - (n3 + n4)) != map1.end()){
					count += map1[0 - (n3 + n4)];
				}
			}
		}
		return count;
	}
};

class Solutiob6{
	bool canConstruct1(string ransomNote, string magazine) {
		unordered_map<int,int> map;//key是字符 value是出现的次数
		if(ransomNote.length() > magazine.length()) return false;
		for(char temp : magazine){
			map[temp - 'a']++;
		}
		for(char temp : ransomNote){
			map[temp - 'a']--;
		}
		for(auto temp : map){
			if(temp.second < 0) return false;
		}
		return true;
	}
	
	bool canConstruct(string ransomNote, string magazine){
		vector<int> result(26,0);
		if(ransomNote.length() > magazine.length() ) return false;
		for(auto temp : magazine){
			result[temp - 'a']++;
		}
		
		for(auto temp : ransomNote){
			result[temp - 'a']--;
		}
		
		for(auto temp : result){
			if(temp < 0) return false;
		}
		return true;
	}
};

class Solutiob7{
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		vector<vector<int>> result;
		sort(nums.begin(),nums.end());//按顺序排序一下
		for(int i =0;i < nums.size();i++){
			if(nums[i] > 0) return result; //排序好的首位元素都大于0，后序的更不可能组合成为0
			if(i > 0 and nums[i] == nums[i - 1]){
				continue;//阻止重复的元素出现
			}
			int left = i + 1;
			int right = nums.size() - 1;
			while(left < right){
				int sum = 0;
				sum = nums[i] + nums[left] + nums[right];
				if(sum == 0) {
					result.push_back({nums[i],nums[left],nums[right]});
					while(right > left and nums[left] == nums[left + 1]) left++;
					while(right > left and nums[right] == nums[right - 1]) right--;
					
					right--;
					left++;
				}
				else if(sum > 0) right--;
				else left++;
				
				
				
			}
		}
		
		return result;
	}
};

class Solution8{
public:
	vector<vector<int>> fourSum(vector<int>& nums, int target) {
		vector<vector<int>> result;
		sort(nums.begin(),nums.end());
		for(int i = 0;i < nums.size();i++){
//			if(nums[i] > target)  break;
			if(i > 0 && nums[i] == nums[i - 1]) continue;
			
			for(int j = i + 1;j < nums.size();j++){
//				if(nums[i] + nums[j] > target) break;
				if(j > i + 1 && nums[j] == nums[j - 1]) continue;
				int left = j + 1;
				int right = nums.size() - 1;
				while(left < right){
					long long sum = (long long)nums[i] + nums[j] + nums[left] + nums[right];
					if(sum < target) left++;
					else if(sum > target) right--;
					else{
						result.push_back({nums[i],nums[j],nums[left],nums[right]});
						
						while(right > left && nums[right] == nums[right - 1]) right--;
						while(right > left && nums[left] == nums[left + 1]) left++;
						
						right--;
						left++;
					}
				}
			}
		}
		
		return result;
	}
};
