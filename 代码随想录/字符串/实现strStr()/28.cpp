#include <string.h>
#include <iostream>
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;
// https://leetcode.cn/problems/find-the-index-of-the-first-occurrence-in-a-string/

//滑动窗口
class Solution1 {
public:
    int strStr(string haystack, string needle) {
        //这道题首先我想到到的是滑动窗口去做
        int len1 = haystack.length();
        int len2 = needle.length();
        //长度不匹配
        if(len1 < len2) return -1;
        int windows = len2;
        string temp;//保存滑动区间里面的字符串
        for(int start = 0;start <= len1 - windows + 1;start++){
            temp = haystack.substr(start,windows);
            if(temp == needle){
                return start;
            }
        }
        return -1;

    }
};

//kmp算法
class Solution {
public:
    int strStr(string haystack, string needle) {

    }
};