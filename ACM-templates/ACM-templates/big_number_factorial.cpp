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
                tmp = tmp + num[i] * j;    //�����λ��ʼ���Ⱥ���ߵ�tmp��ʾ��ǰλ���ұߵ�tmp��ʾ��λ��֮ǰ����λ��
                num[i] = tmp % 10; //  �����ڶ�Ӧ������λ�ã���ȥ����λ���һλ��
                tmp = tmp / 10;    //  ȡ�������ٴ�ѭ��,��n����һ��λ�õĳ˻����
            }
            while (tmp) {    //  ֮��Ľ�λ����
                num[len++] = tmp % 10;
                tmp = tmp / 10;
            }
        }
    }
     
    void show_result() {
        for (LL i = len - 1; i >= 0; --i)
            printf("%d", int(num[i]));    //  �����λ�������,���ݱȽ϶����printf���
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