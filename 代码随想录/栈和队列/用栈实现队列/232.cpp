#include <stack>
#include <stdlib.h>
#include <iostream>
#include <vector>

using namespace std;
// https://leetcode.cn/problems/implement-queue-using-stacks/
/**
 * stack的常用操作
 * stack.push(1) 无返回数值
 * stack.pop()弹出栈顶元素  没有返回值
 * stack.peek  top()返回栈顶元素 有返回值
 * stack.empty() true false返回
 */

class MyQueue {
public:

    stack<int> stkIn;
    stack<int> stkOut;

    MyQueue() {

    }
    
    void push(int x) {
        stkIn.push(x);
    }
    
    int pop() {
        if(!stkOut.empty()){
            int top = stkOut.top();
            stkOut.pop();
            return top;
        } else{
            while(!stkIn.empty()){
                stkOut.push(stkIn.top());
                stkIn.pop();
            }
            int top = stkOut.top();
            stkOut.pop();
            return top;
        }
    }
    
    int peek() {
        if(!stkOut.empty()){
            return stkOut.top();
        } else{
            while(!stkIn.empty()){
                stkOut.push(stkIn.top());
                stkIn.pop();
            }
            return stkOut.top();
        }
    }
    
    bool empty() {
        return stkIn.empty() && stkOut.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
