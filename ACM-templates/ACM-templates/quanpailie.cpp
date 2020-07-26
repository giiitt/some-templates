/*
    |求1到n的全排列, 有条件|
    |16/11/05ztx, thanks to wangqiqi|
*/

#include"my_header.h"

using namespace std;

class qpl {
public:
    void Pern(int list[], int k, int n) {   //  k表示前k个数不动仅移动后面n-k位数
        if (k == n - 1) {
            for (int i = 0; i < n; i++) {
                printf("%d", list[i]);
            }
            printf("\n");
        }
        else {
            for (int i = k; i < n; i++) {   //  输出的是满足移动条件所有全排列
                swap(list[k], list[i]);
                Pern(list, k + 1, n);
                swap(list[k], list[i]);
            }
        }
    }
};

//int main() {
//    qpl test;
//    int num = 5;
//    int start = 0;
//    int* list = new int[num];
//    for (int i = 0; i < num; i++) {
//        list[i] = i;
//    }
//    test.Pern(list, start, num);
//    delete[] list;
//    return 0;
//}