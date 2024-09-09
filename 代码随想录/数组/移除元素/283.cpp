#include <stdlib.h>
#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
	void mozeZeroes(vector<int>& nums){
		int write = 0;//写
		for(int read = 0;read < nums.size();read++){
			if(nums[read] != 0){
				nums[write++] = nums[read];
			}
		}
		for(int damn = write;damn < nums.size();damn++){
			nums[damn] = 0;
		}
		for(int damn:nums){
			cout<<damn<<" ";
		}
	}
};
