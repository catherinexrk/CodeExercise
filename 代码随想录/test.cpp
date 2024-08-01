////#include <stdio.h>
//
//#include <stdlib.h>
////#include <iostream>
////using namespace std;
//
//int main(){
////	cout<<"hello world";
//	printf("hello world");
//	return 0;
//}

#include <stdlib.h>
#include <iostream>
using namespace std;

void test_arr() {
	int array[2][3] = {
		{0, 1, 2},
		{3, 4, 5}
	};
	cout << &array[0][0] << " " << &array[0][1] << " " << &array[0][2] << endl;
	cout << &array[1][0] << " " << &array[1][1] << " " << &array[1][2] << endl;
}

int main() {
	test_arr();
}
