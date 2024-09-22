#include <stack>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <deque>
#include <queue>

using namespace std;
// https://leetcode.cn/problems/implement-stack-using-queues/

class MyStack1 {
public:
    queue<int> q1;
    queue<int> q2;//辅助队列 备份q1

    MyStack() {
        //null
    }
    
    void push(int x) {
        q1.push(x);
    }
    
    int pop() {
        //先将q1的前size-1个元素依次出栈，暂存在q2
        int size = q1.size();
        while (size--){
            q2.push(q1.front());
            q1.pop();
        }
        int result = q1.front();
        q1.pop();

        swap(q1,q2);

        // while(!q2.empty()){
        //     q2.pop();
        // }

        return result;
    }
    
    int top() {
        int size = q1.size();
        while (size-- > 1){
            q2.push(q1.front());
            q1.pop();
        }

        int result = q1.front();//此时result是q1队列的最后一个元素，也是栈顶元素

        q2.push(result);
        q1.pop();

        swap(q1,q2);
        // while(!q2.empty()){
        //     q2.pop();
        // }
        return result;
        
    }
    
    bool empty() {
        return q1.empty();
    }
};

class MyStack {
public:
    queue<int> q1;
    queue<int> q2; // 辅助队列

    MyStack() {
        // 构造函数
    }
    
    void push(int x) {
        q1.push(x);
    }
    
    int pop() {
        // 先将 q1 的前 size-1 个元素依次出队，暂存在 q2
        int size = q1.size();
        while (size-- > 1) {
            q2.push(q1.front());
            q1.pop();
        }
        int result = q1.front(); // 获取栈顶元素
        q1.pop(); // 从 q1 中移除栈顶元素

        // 将 q2 的元素移回 q1
        swap(q1, q2); // 使用 swap，避免清空操作

        return result;
    }
    
    int top() {
        // 先将 q1 的前 size-1 个元素依次出队，暂存在 q2
        int size = q1.size();
        while (size-- > 1) {
            q2.push(q1.front());
            q1.pop();
        }
        int result = q1.front(); // 获取栈顶元素

        // 将栈顶元素放入 q2，保持队列顺序
        q2.push(result);
        q1.pop(); // 从 q1 中移除栈顶元素

        // 将 q2 的元素移回 q1
        swap(q1, q2); // 使用 swap，避免清空操作

        return result; // 返回栈顶元素
    }
    
    bool empty() {
        return q1.empty();
    }
};


/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */