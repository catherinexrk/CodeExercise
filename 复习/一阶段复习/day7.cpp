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
	string removeDuplicates(string s) {
		stack<char> st;
		/**
		 * 我的思路是，创建一个栈去存储s的字符，存储之后进行比较，如果接下来的跟栈顶相同
		 * 栈顶元素弹出，同时对下一个进行操作
		 */
		st.push(s[0]);
		for(int i = 1;i < s.length();i++){
			char temp = s[i];
			if(st.empty()){
				st.push(temp);
			} else{
				char c = st.top();//栈顶元素
				if(c == temp){
					st.pop();//栈顶弹出
				} else{
					st.push(temp);
				}
			}
		}
		//此时栈st安全
		string str;
		while(!st.empty()){
			char temp = st.top();
			str += temp;
			st.pop();
		}
		
		reverse(str.begin(),str.end());
		return str;
	}
};

class Solution2{
public:
	int evalRPN(vector<string>& tokens) {
		stack<int> st;//存储数字
		int symbol;
		for(auto temp : tokens){
			if(temp == "+" || temp == "-" || temp == "*" || temp == "/"){
				int num2 = st.top();
				st.pop();
				int num1 = st.top();
				st.pop();
				if (temp == "+") {
					st.push(num1 + num2);
				} else if (temp == "-") {
					st.push(num1 - num2);
				} else if (temp == "*") {
					st.push(num1 * num2);
				} else if (temp == "/") {
					if (num2 == 0) return -1; // 或者抛出异常，因为除数不能为0
					st.push(num1 / num2);
				}
			} else{
				symbol = stoi(temp);
				st.push(symbol);//存入数字
			}
		}
		return st.top();
		
	}
};


class Solution3 {
private:
	class MyQueue {
	public:
		deque<int> que;
		
		// 修改了 pop 方法，增加了参数 value
		//每次弹出的时候，比较当前要弹出的数值是否等于队列出口元素的数值
		//如果相等则弹出，同时pop之前判断队列是否为空
		void pop(int value){
			if(!que.empty() && value == que.front()){
				que.pop_front();
			}
		}
		
		void pop1(int value){
			if(!que.empty() && value == que.front()){
				que.pop_front();
			}
		}
		
		// 保留了 push 方法，但是增加了循环中的 pop 操作
		//如果push的数值大于入口元素的数值，那么将队列后端的数值弹出
		//直到push的数值小于等于队列入口元素为止
		//这样就保持了队列里的数值是单调从大到小
		void push(int value){
			while(!que.empty() && value > que.back()){
				que.pop_back();
			}
			que.push_back(value);
		}
		
		// front 方法没有修改
		int front(){
			return que.front();
		}
	};
public:
	vector<int> maxSlidingWindow(vector<int>& nums, int k) {
		vector<int> result;
		MyQueue que;
		
		// 初始化滑动窗口的前 k 个元素
		for(int i = 0; i < k; i++){
			que.push(nums[i]);
		}
		
		result.push_back(que.front()); // 第一个窗口的最大值
		
		// 滑动窗口，移除不在窗口内的元素，添加新元素
		for(int i = k; i < nums.size(); i++){
			// 移除不在窗口内的元素
			que.pop(nums[i - k]);
			// 添加新元素
			que.push(nums[i]);
			// 添加当前窗口的最大值
			result.push_back(que.front());
		}
		return result;
	}
};



class Solution4{
public:
	vector<int> preorderTraversal(TreeNode* root) {
		vector<int> result;
		traversal(root,result);
		return result;
	}
	
	void traversal(TreeNode * root,vector<int>& vec){
		if(root != nullptr){
			vec.push_back(root->val);
			traversal(root->left,vec);
			traversal(root->right,vec);
		}
	}
};

class Solution5{
public:
	vector<int> preorderTraversal1(TreeNode* root){
		queue<TreeNode *> que;
		vector<int> result;
		if(root != nullptr){
			que.push(root);
		} else{
			return result;
		}
		while(!que.empty()){
			int size = que.size();
			for(int i = 0;i < size;i++){
				TreeNode * node = que.front();
				que.pop();
				result.push_back(node->val);
				if(node->left) que.push(node->left);
				if(node->right) que.push(node->right);
			}
		}
		return result;
	}
	
	vector<int> preorderTraversal(TreeNode* root){
		stack<TreeNode* > st;
		vector<int> result;
		if(root == nullptr) return result;
		while(!st.size()){
			int size = st.size();
			for(int i = 0;i < size;i++){
				TreeNode * node = st.top();
				st.pop();
				result.push_back(node->val);
				st.push(node->right);
				st.push(node->left);
			}
		}
		return result;
	}
};


class Solution6{
public:
	TreeNode* invertTree(TreeNode* root) {
		if(root == nullptr) return root;
		swap(root->left,root->right);
		invertTree(root->left);
		invertTree(root->right);
		return root;
	}
	
	TreeNode * func(TreeNode * root){
		stack<TreeNode* > st;
		if(root == nullptr) return root;
		st.push(root);
		while(!st.empty()){
			int size = st.size();
			for(int i = 0;i < size;i++){
				TreeNode * node = st.top();
				st.pop();
				swap(node->left,node->right);
				if(node->right) st.push(node->right);
				if(node->left) st.push(node->left);
			}
		}
		return root;
	}
	
	TreeNode * func2(TreeNode * root){
		queue<TreeNode* > st;
		if(root == nullptr) return root;
		st.push(root);
		while(!st.empty()){
			int size = st.size();
			for(int i = 0;i < size;i++){
				TreeNode * node = st.front();
				st.pop();
				swap(node->left,node->right);
				if(node->left) st.push(node->left);
				if(node->right) st.push(node->right);
				
			}
		}
		return root;
	}
};

class Solution7{
public:
	bool isSymmetric(TreeNode* root) {
		if(root == nullptr) return true;
		else return compare(root->left,root->right);
		
	}
	
	bool compare(TreeNode * left,TreeNode * right){
		if(left == nullptr && right != nullptr) return false;
		else if(left != nullptr && right == nullptr) return false;
		else if(left == nullptr && right != nullptr) return false;
		else if(left->val != right->val) return false;
		
		//剩下的都是左右节点不为空，并且数值相等的情况
		bool outside = compare(left->left,right->right);
		bool inside = compare(left->right,right->left);
		bool result = inside && outside;
		return result;
	}
};


class Solution8{
	
	bool isSameTree(TreeNode* p, TreeNode* q) {
		if(p == nullptr && q == nullptr) return true;
		else if(p != nullptr && q == nullptr) return false;
		else if(p == nullptr && q != nullptr) return false;
		else if(p->val != q->val) return false;
		
		bool left = isSameTree(p->left,q->right);
		bool right = isSameTree(p->right,q->right);
		return left && right;
	}
};

class Solution9{
public:
	bool compare(TreeNode * root,TreeNode * subRoot){
		if(root == nullptr && subRoot == nullptr) return true;
		if(root == nullptr || subRoot == nullptr || root->val != subRoot->val) return false;
		
		bool left = compare(root->left,subRoot->left);
		bool right = compare(root->right,subRoot->right);
		return left && right;
	}
	
	bool isSubtree(TreeNode* root, TreeNode* subRoot) {
		if(root == nullptr) return false;
		
		if(compare(root,subRoot)) return true;
		else return isSubtree(root->left,subRoot) || isSubtree(root->right,subRoot);
	}
};

class Solution10{
public:
	int maxDepth(TreeNode* root) {
		//左右中
		//空树的深度为0
		if(root == nullptr) return 0;
		int left = maxDepth(root->left);
		int right = maxDepth(root->right);
		return max(left,right) + 1;
	}
};


class Solution11{
public:
	int maxDepth(TreeNode* root) {
		if(root == nullptr) return 0;
		int left = maxDepth(root->left);
		int right = maxDepth(root->right);
		return max(left,right) + 1;
	}
	
	int func(TreeNode * root){
		queue<TreeNode *> que;
		if(root == nullptr) return 0;
		que.push(root);
		
		int depth = 0;
		while(!que.empty()){
			int size = que.size();
			for(int i = 0;i < size;i++){
				TreeNode * node = que.front();
				que.pop();
				if(node->left) que.push(node->left);
				if(node->right) que.push(node->right);
			}
			depth++;
		}
		
		return depth;
	}
};

class Solution12{
public:
	int maxDepth(Node* root) {
		if(root == nullptr) return 0;
		int depth = 0;
		for(auto temp : root->children){
			int damn = maxDepth(temp);
			depth = max(depth,damn);
		}
		return depth + 1;
	}
	
	int func(Node * root){
		if(root == nullptr) return 0;
		queue<Node*> que;
		que.push(root);
		int depth = 0;
		while(!que.empty()){
			int size = que.size();
			for(int i = 0;i < size;i++){
				Node * node = que.front();
				que.pop();
				for(auto damn : node->children){
					if(damn) que.push(damn);
				}
			}
			depth++;
		}
		
		return depth;
	}
};

class Solution13{
public:
	int minDepth(TreeNode* root) {
		if(root == nullptr) return 0;
		int leftDepth = minDepth(root->left);
		int rightDepth = minDepth(root->right);
		
		//当一个左子树为空，右不为空，此时说明这不是最低点
		if(root->left == nullptr && root->right != nullptr){
			return 1 + rightDepth;
		}
		
		if(root->left != nullptr && root->right == nullptr){
			return 1 + leftDepth;
		}
		
		int result = min(leftDepth , rightDepth) + 1;
		return result;
	}
	
	int func(TreeNode * root){
		queue<TreeNode *> que;
		if(root == nullptr) return 0;
		int depth = 0;
		que.push(root);
		while(!que.empty()){
			int size = que.size();
			depth++;
			
			for(int i = 0;i < size;i++){
				TreeNode * node = que.front();
				que.pop();
				if(node->left == nullptr && node->right == nullptr) return depth;
				if(node->left) que.push(node->left);
				if(node->right) que.push(node->right);
			}
		}
		return depth;
	}
};

class Solution14{
public:
	//迭代
	int countNodes1(TreeNode* root) {
		queue<TreeNode *> que;
		if(root == nullptr) return 0;
		que.push(root);
		int count = 0;
		while(!que.empty()){
			int size = que.size();
			for(int i = 0;i < size;i++){
				TreeNode * node = que.front();
				que.pop();
				count++;
				if(node->left) que.push(node->left);
				if(node->right) que.push(node->right);
			}
		}
		
		return count;
	}
	
	//递归
	int countNodes(TreeNode* root){
		if(root == nullptr) return 0;
		int leftCount = countNodes(root->left);
		int rightCount = countNodes(root->right);
		return leftCount + rightCount + 1;
	}
};

class Solution15{
public:
	int getHeight(TreeNode * node){
		if(node == nullptr) return 0;
		int leftHeight = getHeight(node->left);
		if(leftHeight == -1) return -1;//左
		
		int rightHeight = getHeight(node->right);
		if(rightHeight == -1) return -1;//右
		
		int result;
		if(abs(leftHeight - rightHeight) > 1){
			result = -1;
		}else{
			result = 1 + max(leftHeight,rightHeight);
		}
		
		return result;
	}
	
	int get(TreeNode * node){
		if(node == nullptr) return 0;
		int leftHeight = get(node->left);
		if(leftHeight == -1) return -1;
		
		int rightHeight = get(node->right);
		if(rightHeight == -1) return -1;
		
		if(abs(leftHeight - rightHeight) > 1) return -1;
		else return 1 + max(leftHeight,rightHeight);
	}
	
	bool isBalanced(TreeNode* root) {
		return (getHeight(root) == -1) ? false : true;
	}
};


class Solution16{
public:
	void search(TreeNode * root,vector<string>& result,vector<int>& path){
		path.push_back(root->val);
		
		if(root->left == nullptr && root->right == nullptr){
			string sPath;
			for(int i = 0;i < path.size();i){
				sPath += to_string(path[i]);
				if(i != path.size() - 1){
					sPath += "->";
				}
			}
			result.push_back(sPath);
			return;
		}		
		//左
		if(root->left){
			search(root->left,result,path);
			path.pop_back();//回溯
		}
		//右
		if(root->right){
			search(root->right,result,path);
			path.pop_back();//回溯
		}	
	}
	
	void search1(TreeNode * root,vector<string>& result,vector<int>& path){
		path.push_back(root->val);
		//终止条件
		if(root->left == nullptr && root->right == nullptr){
			string sPath;
			for(int i = 0;i < path.size();i++){
				sPath += to_string(path[i]);
				if(i < path.size() - 1){
					sPath += "->";
				}
			}
			result.push_back(sPath);
		} else{
			//左
			if(root->left){
				search1(root->left,result,path);
				path.pop_back();//回溯
			}
			
			//右
			if(root->right){
				search1(root->right,result,path);
				path.pop_back();//回溯
			}
		}
		
		
	}
	
	vector<string> binaryTreePaths(TreeNode* root) {
		vector<string> result;//存储所有路径
		vector<int> path;
		search(root,result,path);
		return result;
		
	}
};

class Solution17{
public:
	int traversal(TreeNode * root){
		if(root == nullptr) return 0;
		
		int leftValue = traversal(root->left);
		//当碰到左叶子节点的时候进行操作
		if(root->left && !root->left->left && !root->left->right){
			leftValue = root->left->val;
		}
		int rightValue = traversal(root->right);
		
		return leftValue + rightValue;
	}
	
	int func1(TreeNode * node){
		if(node == nullptr) return 0;
	
		int leftValue = func(node->left);
		if(node->left != nullptr && node->left->left == nullptr && node->left->right == nullptr){
			leftValue = node->left->val;
		}
		
		int rightValue = func(node->right);
		
		return leftValue + rightValue;
	}
	
	int func(TreeNode * node){
		queue<TreeNode*> que;
		if(node == nullptr) return 0;
		que.push(node);
		int result = 0;
		while(!que.empty()){
			int size = que.size();
			for(int i = 0;i < size;i++){
				TreeNode * temp = que.front();
				if(temp->left != nullptr && !temp->left->left && !temp->left->right){
					result += temp->left->val;
				}
				if(temp->left) que.push(temp->left);
				if(temp->right) que.push(temp->right);
			}
		}
		return result;
	}
	
	int sumOfLeftLeaves(TreeNode* root) {
		//终止条件
		return traversal(root);
		
	}
};

class Solution18{
public:
	int findBottomLeftValue(TreeNode* root) {
		if (root == nullptr) return 0; // 处理空树的情况
		queue<TreeNode*> que;
		que.push(root);
		int result = 0; // 用于存储最底层左值的变量
		
		while (!que.empty()) {
			int size = que.size();
			for (int i = 0; i < size; i++) {
				TreeNode* temp = que.front();
				que.pop();
				
				// 如果是第一层，记录这个节点的值
				if (i == 0) {
					result = temp->val;
				}
				
				if (temp->left) que.push(temp->left);
				if (temp->right) que.push(temp->right);
			}
		}
		return result; // 在循环结束后返回最底层的左值
	}
};

class Solution19{
public:
	int flag = false;
	vector<int> path;
	void traversal(TreeNode * root,int targetSum,vector<int>& path){
		path.push_back(root->val);
		//终止条件
		if(root->left == nullptr && root->right == nullptr){
			int sum = 0;
			for(int temp : path){
				sum += temp;
			}
			if(sum == targetSum){
				flag = true;
				return;
			}
		}
		
		//左
		if(root->left){
			traversal(root->left,targetSum,path);
			path.pop_back();
		}
		
		//右
		if(root->right){
			traversal(root->right,targetSum,path);
			path.pop_back();
		}
	}
	
	bool hasPathSum(TreeNode* root, int targetSum) {
		if(root == nullptr) return false;
		traversal(root,targetSum,path);
		return flag;
	}
};


class Solution20{
public:
	TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
		
	}
};
