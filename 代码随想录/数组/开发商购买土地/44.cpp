#include <stdlib.h>
#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;
//https://kamacoder.com/problempage.php?pid=1044

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
/**
 * 简单说下思路
 * 首先，我们要创建两个数组，分别保存行和列的前缀和
 * 然后进行横向和纵向的分割，对于每行的i，计算当前为止的横向总和，然后与之后的横向总和进行对比
 * 更新最小差异result
 * 
 * 同理，针对纵向，计算每列的j，得到最小差异result
 * 
 */
