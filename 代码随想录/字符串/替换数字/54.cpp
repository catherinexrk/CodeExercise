#include <string.h>
#include <iostream>
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;
//https://kamacoder.com/problempage.php?pid=1064

class Solution{
public:
	string replaceString(string s){
		int count = 0;//表示多少个数字的字符
		for(auto temp : s){
			if(temp >= '0' and temp <= '9'){
				count++;
			}
		}
		int oldSize = s.length() - 1;
		s.resize(s.length() + count * 5);
		int newSize = s.length() - 1;
		while(oldSize >= 0){
			if(s[oldSize] >= '0' and s[oldSize] <= '9'){
				s[newSize--] = 'r';
				s[newSize--] = 'e';
				s[newSize--] = 'b';
				s[newSize--] = 'm';
				s[newSize--] = 'u';
				s[newSize--] = 'n';
			} else{
				s[newSize--] = s[oldSize];
			}
			oldSize--;
		}
		return s;
	}
};

int main(){
	Solution solution;
	string s;
	cin>>s;
	s = solution.replaceString(s);
	cout<<s;
	return 0;
	
}