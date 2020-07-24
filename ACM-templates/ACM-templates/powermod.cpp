/*
Abstract	: Powermod to solve the (x**n) % m
Date		: 7/24/2020
Description	:
*/

#include"my_header.h"

typedef long long LL;   //  �����ݴ�С���������

using std::cout;
using std::endl;

class powermod {

public:
    LL powerMod(LL x, LL n, LL m)
    {
        LL res = 1;
        while (n > 0) {
            if (n & 1) //  �ж��Ƿ�Ϊ������������true
                res = (res * x) % m;
            x = (x * x) % m;
            n >>= 1;    //  �൱��n /= 2;
        }
        return res;
    }

    void show_result() {
        std::cout << powerMod(2, 4, 7)<<endl;
    }

};


int main() {
    powermod test;
    test.show_result();
    return 0;
}

