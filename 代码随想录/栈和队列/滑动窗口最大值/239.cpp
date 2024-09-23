#include <string>
#include <iostream>
#include <stdlib.h>
#include <stack>
#include <queue>
#include <algorithm>
#include <vector>
#include <deque>

using namespace std;
// https://leetcode.cn/problems/sliding-window-maximum/


//bf
class Solution1 {
public:
    // int maxNumInQueue(queue<int> q){
    //     vector<int> result;
    //     while(!q.empty()){
    //         result.push_back(q.front());
    //         q.pop();
    //     }
    //     sort(result.begin(),result.end());
    //     return result.back();//返回最大值
    // }
    int maxNumInQueue(queue<int> q){
        int maxNum = q.front();
        while(!q.empty()){
            maxNum = max(maxNum,q.front());
            q.pop();
        }
        return maxNum;
    }

    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> result;

        for(int i = 0;i <= nums.size() - k;i++){
            queue<int> q;
            for(int count = 0;count < k;count++){
                q.push(nums[count + i]);
            }
            result.push_back(maxNumInQueue(q));
        }

        return result;
    }
};
/**
 * 时间复杂度 o(n*k)
 * 空间复杂度 o(k)
 */

class Solution {
private:
    class MyQueue{
    public:
        deque<int> que;//使用双向队列，便于首尾操作

        //每次弹出元素，查询队列是否为空，同时查看value与队头元素是否相等
        //相等则进行弹出
        void pop(int value){
            if(!que.empty() && value == que.front()){
                que.pop_front();
            }
        }

        /**
         * 每次塞入均要查看当前value和末尾元素关系
         * 如果当前队列不为空，则与末尾元素判断
         * 如果value 大于 末尾元素，弹出末尾元素，直到value前面的都是大于value的
         */
        void push(int value){
            while(!que.empty() && value > que.back()){
                que.pop_back();//弹出队尾元素
            }
            que.push_back(value);//此时保证了这个que按照从大到小排列在que队列中
        }

        int getMax(){
            return que.front();
        }
    };
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        MyQueue mq;
        vector<int> result;
        //先存储前k个元素
        for(int i = 0;i < k;i++){
            mq.push(nums[i]);
        }

        result.push_back(mq.getMax());//获得第一个k区间的最大值
        for(int i = k;i < nums.size();i++){
            mq.pop(nums[i - k]);//滑动窗口移除最前面的元素
            mq.push(nums[i]);//滑动窗口加入最后的元素
            result.push_back(mq.getMax());
        }
        return result;
    }
};
/**
 * 时间复杂度on
 * 空间复杂度ok
 */