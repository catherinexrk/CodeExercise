#include <stdlib.h>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

//https://leetcode.cn/problems/ransom-note/

class Solution {
public:
	bool canConstruct(string ransomNote, string magazine) {
		if(magazine.length() < ransomNote.length() ){
			return false;
		}
		vector<int> count(26,0);
	
//		for(int i = 0;i < magazine.size();i++){
//			count[magazine[i] - 'a']++;
//			count[ransomNote[i] - 'a']--;
//		}
		for(int i = 0;i < magazine.size();i++){
			count[magazine[i] - 'a']++;
		}
		for(int i = 0;i < ransomNote.length();i++){
			count[ransomNote[i] - 'a']--;
		}
		for(int i = 0;i < 26;i++){
			if(count[i] < 0){
				return false;
			}
		}
		
		return true;
	}
};
