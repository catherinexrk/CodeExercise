#include <string>
#include <iostream>
#include <stdlib.h>
#include <stack>
#include <algorithm>

using namespace std;
// https://leetcode.cn/problems/remove-all-adjacent-duplicates-in-string/


class Solution {
public:

    string removeDuplicates(string s) {
        stack<char> stroeStack;
        /**
         * 我的思路是，创建一个栈，将s的字符依次入栈，在下一个字符入栈前，
         * 判断与栈顶元素是否相同，如果相同则跳过当前字符的入栈同时清空栈顶
         * 注意事项：检查栈是否为空，在每次字符入栈操作前
         */

        for(int i = 0;i < s.length();i++){
            if(stroeStack.empty()){
                //如果栈为空，则字符直接入栈
                stroeStack.push(s[i]);
            } else{
                char topElement = stroeStack.top();//获取栈顶元素
                //此时判断栈顶元素是否同当前字符相等
                if(topElement == s[i]){
                    //栈顶出栈
                    stroeStack.pop();
                } else{
                    stroeStack.push(s[i]);
                }
            }
        }
        //此时结束判断
        if(!stroeStack.empty()){
            string result;
            while(!stroeStack.empty()){
                char temp = stroeStack.top();
                result += temp;
                stroeStack.pop();
            }
            reverse(result.begin(),result.end());
            return result;
        } else{
            return "";//空字符串
        }
    }
};
/**
 * 时间复杂度 o(n) 最坏的情况下，遍历字符串的时候所有元素都进栈
 * 空间复杂度 o(n) 最坏的情况下，元素全部进栈，占用n个字符空间
 */