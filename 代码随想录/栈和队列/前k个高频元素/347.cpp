#include <string>
#include <iostream>
#include <stdlib.h>
#include <stack>
#include <queue>
#include <algorithm>
#include <vector>
#include <deque>

using namespace std;
// https://leetcode.cn/problems/top-k-frequent-elements/

class Solution1 {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int> result;//first 对应nums[i] second对应出现频率
        for(int temp : nums){
            result[temp]++;
        }
        vector<pair<int,int>> vec(result.begin(),result.end());

        //按照second排序
        sort(vec.begin(),vec.end(),[](const auto& a,const auto& b){
            return a.second > b.second;
        });

        // sort(vec.begin(),vec.end(),[](const auto &a,const auto& b){
        //     return a.second > b.second;
        // });
        

        int count = 0;
        vector<int> damn;
        for(auto temp : vec){
            if(count < k){
                damn.push_back(temp.first);
                count++;
            } else{
                break;
            }
        }
        return damn;
    }
};
/**
 * 时间复杂度o(nlogn)
 */


class Solution {
public:
    //小顶堆
    class mycomparison{
        public:
        bool operator()(const pair<int,int>& lhs,const pair<int,int>& rhs){
            return lhs.second > rhs.second;
        }
    };

    vector<int> topKFrequent(vector<int>& nums, int k) {
        //统计元素出现的频率
        map<int,int> map;
        for(int i = 0;i < nums.size();i++){
            map[nums[i]]++;
        }

        //对频率排序
        //定义一个小顶堆 大小为k
        priority_queue<pair<int,int>,vector<pair<int,int>>,mycomparison> pri_que;
// 用固定大小为k的小顶堆，扫面所有频率的数值
        for (unordered_map<int, int>::iterator it = map.begin(); it != map.end(); it++) {
            pri_que.push(*it);
            if (pri_que.size() > k) { // 如果堆的大小大于了K，则队列弹出，保证堆的大小一直为k
                pri_que.pop();
            }
        }

        // 找出前K个高频元素，因为小顶堆先弹出的是最小的，所以倒序来输出到数组
        vector<int> result(k);
        for (int i = k - 1; i >= 0; i--) {
            result[i] = pri_que.top().first;
            pri_que.pop();
        }
        return result;
    }
};