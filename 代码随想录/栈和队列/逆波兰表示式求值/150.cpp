#include <string>
#include <iostream>
#include <stdlib.h>
#include <stack>
#include <algorithm>

using namespace std;

// https://leetcode.cn/problems/evaluate-reverse-polish-notation/

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        /**
         * 逆波兰式 转化为中缀表达式思路
         * 从左到右遍历，遇到数字进行存储，遇到符号则出栈两个，进行数学运算，
         * 将结果入栈，直到遍历完
         */

        stack<int> storeStack;//存储tokens中的字符
        for(string temp : tokens){
            if(temp != "+" &&
            temp != "-" &&
            temp != "*" &&
            temp != "/"){
                int transition = stoi(temp);
                storeStack.push(transition);//数字入栈
            } else{
                //此时遇到了算术符号
                int topElementTail = storeStack.top();
                storeStack.pop();
                int topElementHead = storeStack.top();
                storeStack.pop();
                int result = 0;
                if(temp == "+") result = topElementHead + topElementTail;
                else if(temp == "-") result = topElementHead - topElementTail;
                else if(temp == "*") result = topElementHead * topElementTail;
                else result = topElementHead / topElementTail;
                storeStack.push(result);//将结果入栈
            }
        }
        int result = storeStack.top();
        return result;
    }
};
/**
 * 时间复杂度 o(n)
 * 空间复杂度 o(n)
 */