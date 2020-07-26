#include <iostream>

#include<stdio.h>

using namespace std;

class mydiv {
public:
	int my_div(const int x, const int y)
	{
		int left_num = x;
		int result = 0;
		while (left_num >= y)
		{
			int multi = 0;
			while ((y << multi) <= left_num >> 1)
			{
				multi++;
			}
			//cout << multi << endl;
			result += 1 << multi;
			left_num -= y << multi;
		}
		return result;
	}
};

//int main() {
//	mydiv test;
//	cout << test.my_div(184, 5) << endl << test.my_div(200, 20) << endl << test.my_div(18, 7) << endl;
//	return 0;
//}