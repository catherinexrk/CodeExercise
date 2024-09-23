#include <string>
#include <iostream>
#include <stdlib.h>
#include <stack>

using namespace std;
// https://leetcode.cn/problems/valid-parentheses/

class Solution {
public:
    // bool isValid(string s) {
    //     stack<char> storeStack;
    //     int flag = 0;
    //     for(char temp : s){
    //         if(temp == '(' || temp == '{' || temp == '['){
    //             storeStack.push(temp); 
    //         } else {
    //             char damn = storeStack.top();//获取栈顶元素
    //             storeStack.pop();//弹出栈顶元素
    //             if(temp == '}' && damn == '{'){
    //                 return true;
    //             } else if(temp == ']' && damn == '['){
    //                 return true;
    //             } else if(temp == ')' && temp == '('){
    //                 return true; 
    //             } else{
    //                 return false;
    //             }
    //         }
    //     }
    //     return true;
    // }

    bool isValid(string s){
        stack<char> storeStack;
        for(char character : s){
            if(character == '(' || character == '{' || character == '['){
                storeStack.push(character);//左括号一律进栈
            } else{
                //遇到了右括号
                //先判断栈是否为空 为空不进行后续操作
                if(storeStack.empty()){
                    return false;  
                }
                //比较top元素
                char temp = storeStack.top();
                storeStack.pop();

                if((character == '}' && temp != '{') || 
                (character == ')' && temp != '(') || 
                (character == ']' && temp != '[')) {
                    return false; // 不匹配
                }
            }
        }

        return storeStack.empty();//如果栈最终为空，说明true，反之false;
    }
};