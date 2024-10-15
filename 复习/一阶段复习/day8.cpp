#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Node {
public:
	int val;
	vector<Node*> children;
	
	Node() {}
	
	Node(int _val) {
		val = _val;
	}
	
	Node(int _val, vector<Node*> _children) {
		val = _val;
		children = _children;
	}
};

class Solution1{
public:
	TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
		/**
		 * 思路：首先根据后序来确定总根
		 * 然后拿到根部元素之后去切割中序、后序，得到中左、中右，后左，后右
		 */
		
		if(postorder.size() == 0) return nullptr;
		//拿到后序的末尾元素
		int node = postorder[postorder.size() - 1];
		
		//找到中序的root的位置
		int index;
		for(int i = 0;i < inorder.size();i++){
			if(inorder[i] == node){
				index = i;//此时拿到了根节点在中序数组中的位置
				break;
			}
		}
		
		//创建一个新的节点
		TreeNode* root = new TreeNode(node);
		
		//切割中序数组
		//中左子树数组[begin,begin + index)  
		vector<int> inorderLeft(inorder.begin(),inorder.begin() + index);
		
		//中右子树数组[begin + index + 1,end)
		vector<int> inorderRight(inorder.begin() + index + 1,inorder.end());
		
		//切割后序数组
		//后左子树数组[begin,inorderLeft.size)
		vector<int> postOrderLeft(postorder.begin(),postorder.begin() + index);
		
		//后右子树数组(being + inorderLeft.size(),begin + inorderRight.size()]
		vector<int> postOrderRight(postorder.begin() + index,postorder.end() - 1);
		
		root->left = buildTree(inorderLeft,postOrderLeft);
		root->right = buildTree(inorderRight,postOrderRight);
		
		return root;
	}
};

class Solution2{
public:
	TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
		/**
		 * 找到最大值，然后左右分割
		 */
		
		if(nums.size() == 0) return nullptr;
		
		int max = INT_MIN;
		int index;
		for(int i = 0;i < nums.size();i++){
			if(nums[i] > max){
				max = nums[i];
				index = i;
			}
		}
		
		TreeNode * root = new TreeNode(max);//找到了根节点
		if(nums.size() == 1) return root;
		vector<int> left(nums.begin(),nums.begin() + index);
		vector<int> right(nums.begin() + index + 1,nums.end());
		
		root->left = constructMaximumBinaryTree(left);
		root->right = constructMaximumBinaryTree(right);
		return root;
	}
};

class Solution3{
public:
	TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
		//ok,直接返回root1就行
		if(root1 == nullptr) return root2;
		if(root2 == nullptr) return root1;
		
		root1->val += root2->val;
		
//		if(root1->left == nullptr && root2->left != nullptr){
//			root1->left = root2->left;
//		}
//		if(root1->right == nullptr && root2->right != nullptr){
//			root1->right = root2->right;
//		}
		
		root1->left = mergeTrees(root1->left,root2->left);
		root1->right = mergeTrees(root1->right,root2->right);
		
		return root1;
	}
};

class Solution4{
public:
	TreeNode* searchBST(TreeNode* root, int val) {
		if(root == nullptr) return nullptr;
		
		TreeNode * node = nullptr;
		
		if(root->val == val) return root;
		else if(root->val > val){
			node = searchBST(root->left,val);
		} else{
			node = searchBST(root->right,val);
		}
		
		return node;
	}
	
	
	TreeNode * searchBSTBFS(TreeNode * root,int val){
		if(root == nullptr || root->val == val) return root;
		while(root != nullptr){
			if(root->val > val) root = root->left;
			else if(root->val < val) root = root->right;
			else return root;
		}
		
		return nullptr;
	}
};

class Solution5{
public:
	
	TreeNode * pre = nullptr;//前一个节点
	bool isValidBST(TreeNode* root) {
		if(root == nullptr) return true;
		bool left = isValidBST(root->left);
		
		//首先判断pre是否为空，并且判断pre是否小于当前节点的数值，
		if(pre != nullptr && pre->val >= root->val) return false;
		
		pre = root;//记录前一个节点
		
		bool right = isValidBST(root->right);
		return left && right;
	}
	
	bool isValidBST1(TreeNode* root) {
		vector<int> result;
		traversal(root, result);
		for (int i = 1; i < result.size(); i++) {
			if(result[i - 1] >= result[i]) return false;
		}
		return true;
	}
	
	void traversal(TreeNode* node, vector<int>& result) {
		if (node != nullptr) {
			traversal(node->left, result);
			result.push_back(node->val);
			traversal(node->right, result);
		}
	}
};

class Solution6{
public:
	
	TreeNode * pre = nullptr;
	int result = INT_MAX;
	void travesal1(TreeNode * root){
		if(root == nullptr) return;
		
		travesal1(root->left);
		
		if(pre != nullptr){
			result = min(result,root->val - pre->val);
		}
		pre = root;
		
		travesal1(root->right);
	}
	
	int getMinimumDifference(TreeNode* root){
		travesal1(root);
		return result;
	}
	
	int getMinimumDifference1(TreeNode* root) {
		vector<int> result;
		traversal(root, result);
		int minNum = INT_MAX; // 初始化为最大整数值
		for (int i = 1; i < result.size(); i++) {
			int temp = abs(result[i] - result[i - 1]);
			minNum = min(minNum, temp);
		}
		return minNum;
	}
	
	void traversal(TreeNode* node, vector<int>& result) {
		if (node != nullptr) {
			traversal(node->left, result);
			result.push_back(node->val);
			traversal(node->right, result);
		}
	}
	
	
	
	
//	TreeNode * pre = null;
//	bool func(TreeNode * root){
//		if(root == nullptr) return true;
//		int left = func(root->left);
//		
//		if(pre != nullptr && pre->val >= root->val) return false;
//		pre = root;
//		
//		int right = func(root->right);
//		
//		return left && right;
//	}
	
//private:
//	int min = INT_MAX;
//	TreeNode * before = nullptr;
//	void traversal(TreeNode * root){
//		if(root == nullptr) return nullptr;
//		
//		traversal(root->left);
//		
//		if(before != nullptr){
//			result = min(result,root->val - before->val);
//		}
//		
//		traversal(root->right);
//	}
};

class Solution7{
public:
	vector<int> findMode1(TreeNode* root) {
		vector<int> result;
		traversal1(root,result);
		unordered_map<int,int> map;
		for(int num : result){
			map[num]++;
		}
		
		vector<int> arr;
		
		//根据value进行排序
		vector<pair<int,int>> vec(map.begin(),map.end());
		sort(vec.begin(),vec.end(),[](const pair<int,int> &a,const pair<int,int>& b){
			return a.second > b.second;
		});
		
//		vector<pair<int,int>> v(map.begin(),map.end());
//		sort(v.begin(),v.end(),[](const pair<int,int> &a,const pair<int,int>& b){
//			return a.second > b.second;
//		});
		
		int maxSum = vec[0].second;
		for(auto temp : vec){
			if(temp.second == maxSum) arr.push_back(temp.first);
		}
		
		return arr;
	}
	
	void traversal1(TreeNode * root,vector<int> &result){
		if(root != nullptr){
			traversal1(root->left,result);
			result.push_back(root->val);
			traversal1(root->right,result);
		}
	}
	
	TreeNode * pre = nullptr;
	int maxCount = 0;//最大频率
	int count = 0;//统计频率
	vector<int> result;
	void searchBST(TreeNode * root){
		if(root == nullptr) return;
		
		searchBST(root->left);
		
		if(pre == nullptr){ //第一个节点
			count = 1;
		} else if(pre->val == root->val){
			count++;
		} else{
			count = 1;
		}
		
		pre = root;//更新上一个节点
		
		if(count == maxCount){
			result.push_back(root->val);
		}
		
		if(count > maxCount){
			maxCount = count;
			result.clear();//清空result
			result.push_back(root->val);
		}
		
		searchBST(root->right);//右
	}
	
	vector<int> findMode(TreeNode* root){
		
	}
};

class Solution8{
	int maxCount = 0;
	int count = 0;
	vector<int> result;
	TreeNode * pre = nullptr;
	
	void traversal(TreeNode * root){
		if(root == nullptr) return;
		
		traversal(root->left);//左
		
		if(pre == nullptr){
			count = 1;//遇到空节点，说明遇到的是根节点，开始count计数
		} else if(pre->val == root->val){
			count++;
		} else{
			count = 1;
		}
		
		pre = root;
		
		if(count == maxCount){
			result.push_back(root->val);
		}
		
		if(count > maxCount){
			result.clear();
			maxCount = count;
			result.push_back(root->val);
		}
		
		traversal(root->right);
	}
	
	vector<int> findMode(TreeNode* root) {
		traversal(root);
		return result;
	}
};

class Solution9{
public:
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		//一个节点的左子树是节点p，右子树是节点q
		
		//p的子树包括q
		
		if(root == nullptr) return nullptr;
		if(root == q || root == p) return root;
		
		
		TreeNode * left = lowestCommonAncestor(root->left,p,q);
		TreeNode * right = lowestCommonAncestor(root->right,p,q);
		if(left != nullptr && right != nullptr) return root;
		
		if(left == nullptr && right != nullptr) return right;
		else if(left != nullptr && right == nullptr) return left;
		else return nullptr;
	}
};

class Solution10{
public:
	
};
