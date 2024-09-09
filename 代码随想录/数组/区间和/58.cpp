#include <stdlib.h>
#include <iostream>
#include <vector>

using namespace std;
//https://kamacoder.com/problempage.php?pid=1070

void func1(){
	int n;
	cin>>n;
//	vector<int> array(n);//容量n的数组
	vector<int> array;
	for(int i = 0;i < n;i++){
		int temp;
		cin>>temp;
		array.push_back(temp);
	}
	int left,right;
	long sum = 0;
	while(cin>>left>>right){
		for(int damn = left;damn <= right;damn++){
			sum += array[damn];
		}
		cout<<sum;
		sum = 0;
	}
}

void func2(){
	//前缀和操作
	int n;
	cin>>n;//告诉多少项，其实我觉得无所谓
	//使用前缀和，这样复杂度控制在O(1),不会超时
	/*
		思想是数组用来保存每次的累加和，然后输入指定区间时，用累加和的数组进行
		相减便可以得到区间和
	*/
	vector<int> sum(n);//表示从0到i的区间和
	int damn;
	cin>>damn;
	sum[0] = damn;
	for(int i = 1;i < n;i++){
		cin>>damn;
		sum[i] = sum[i - 1] + damn;
	}
	//此时完成了区间和数组的装配
	int left,right;//左右区间
	while(cin>>left>>right){
		if(left == 0){
			cout<<sum[right]<<endl;
		} else{
			cout<<sum[right] - sum[left - 1]<<endl;
		}
	}
}

int main(){
//	func1();
	func2();
	
	return 0;
}
