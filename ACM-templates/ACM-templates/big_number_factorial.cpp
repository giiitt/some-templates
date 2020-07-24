/*
Abstract	: Powermod to solve the (x**n) % m
Date		: 7/24/2020
Description	:
*/

#include <iostream>
#include <cstdio>

using std::cout;
using std::endl;

typedef long long LL;

class bnf {
public:

    LL len = 1;
    LL* num = new LL(100010);

    void Init() {
        len = 1;
        num[0] = 1;
    }

    void mult(int n) {
        for (int j = 2; j <= n; ++j) {
            LL tmp = 0;
            for (LL i = 0; i < len; ++i) {
                tmp = tmp + num[i] * j;    //从最低位开始，等号左边的tmp表示当前位，右边的tmp表示进位（之前进的位）
                num[i] = tmp % 10; //  保存在对应的数组位置，即去掉进位后的一位数
                tmp = tmp / 10;    //  取整用于再次循环,与n和下一个位置的乘积相加
            }
            while (tmp) {    //  之后的进位处理
                num[len++] = tmp % 10;
                tmp = tmp / 10;
            }
        }
    }
     
    void show_result() {
        for (LL i = len - 1; i >= 0; --i)
            printf("%d", int(num[i]));    //  从最高位依次输出,数据比较多采用printf输出
        printf("\n");
        printf("%d", int(len));
    }
};


//int main() {
//    bnf test;
//    test.Init();
//    test.mult(10);
//    test.show_result();
//    return 0;
//}