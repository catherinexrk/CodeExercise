#include <stdlib.h>
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;
//https://leetcode.cn/problems/find-mode-in-binary-search-tree/

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
	vector<int> findMode(TreeNode* root) {
		unordered_map<int,int> map;
		vector<int> result;
		inorder(root,result);
		for(auto temp : result){
			map[temp]++;
		}
		
		auto iter = map.begin();
		int maxNum = INT_MIN;
		int index;
		while(iter != map.end()){
			if(maxNum < iter->second){
				maxNum = iter->second;
				index = iter->first;
			}
			iter++;
		}
		return vector<int>{index};
	}
	
	void inorder(TreeNode* root,vector<int> &result){
		if(root != nullptr){
			inorder(root->left,result);
			result.push_back(root->val);
			inorder(root->right,result);
		}
	}
};

class Solution1 {
public:
	vector<int> findMode(TreeNode* root) {
		unordered_map<int,int> map;
		vector<int> result;//保存众数的数组
		int maxFreq = 0;
		inorder(root,map,maxFreq);
		for(auto temp : map){
			if(temp.second == maxFreq){
				result.push_back(temp.first);
			}
		}
		return result;
	}
	
	void inorder(TreeNode *root,unordered_map<int,int> &map,int &maxFreq){
		if(root != nullptr){
			inorder(root->left,map,maxFreq);
			
			map[root->val]++;
			maxFreq = max(maxFreq,map[root->val]);//maxFreq实时更新当前数值的出现频率
			
			inorder(root->right,map,maxFreq);
		}
	}
	
	bool static cmp(const pair<int,int> &a,const pair<int,int>&b){
		return a.second > b.second;
	}
};

class Solution2 {
private:
	int maxCount = 0;//最大频率
	int count = 0;//统计频率
	TreeNode * pre = nullptr;
	vector<int> result;
	
	void searchBST(TreeNode * cur){
		if(cur == nullptr) return;
		searchBST(cur->left); //左
		//中
		if(pre == nullptr){
			count = 1;
		} else if(pre->val == cur->val){
			count++;//与前一个节点数值相等
		} else{
			count = 1;//与前一个节点数值不同
		}
		
		pre = cur;//更新上一个节点
		
		if(count == maxCount){
			result.push_back(cur->val);
		}
		
		if(count > maxCount){
			maxCount = count;
			result.clear();//清空
			result.push_back(cur->val);
		}
		
		searchBST(cur->right);//右
		return;
	}
	
public:	
	vector<int> findMode(TreeNode* root){
		count = 0;
		maxCount = 0;
		pre = nullptr;
		result.clear();
		
		searchBST(root);
		return result;
	}
};
