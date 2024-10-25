#include <stdlib.h>
#include <iostream>
#include <vector>
#include <string>

using namespace std;
//https://kamacoder.com/problempage.php?pid=1046


class Solution{
public:
	int maxValue(){
		int M,N;//M代表研究材料的种类、N代表小明的行李空间
		vector<int> capacity;
		vector<int> value;
		int num1,num2;
		while(cin>>num1){
			capacity.push_back(num1);
		}
		
		while(cin>>num2){
			value.push_back(num2);
		}
		
		//dp[i][j]表示：i为物品，j表示背包容量
	}
};
