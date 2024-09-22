#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
// https://kamacoder.com/problempage.php?pid=1065

//使用substr进行分配额外空间
class Solution1
public:
    string rotateString(int len,string s){
        //直使使用substr
        int sLen = s.length();
        len %= sLen;

        if(sLen == 0)   return s;
        if(len == 0) return s;
        
        string tail = s.substr(sLen - len,len);
        string head = s.substr(0,sLen - len);
        string newString = tail + head;
        return newString;
    }
};

class Solution{
public:
    void reverse(string& s,int start,int end){
        for(int i = start,j = end;i < j;i++,j--){
            swap(s[i],s[j]);
        }
    }

    string rotateString(int len,string& s){
        //基本的判断
        int sLen = s.length();
        if(len == 0) return s;
        if(sLen == 0) return s;
        len %= sLen;//实际操作的长度

        //先是整体进行翻转
        reverse(s,0,s.length() - 1);//原先的字符串进行翻转
        //开始进行局部的翻转
        reverse(s,0,len);//翻转原先右边要翻转的部分
        reverse(s,len,sLen - len);
    }
}

int main(){
    string s;
    int len;
    cin>>s>>len;
    Solution temp;
    s = temp.rotateString(len,s);
    cout<<s;
    return 0;
}