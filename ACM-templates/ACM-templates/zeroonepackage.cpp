#include "my_header.h"

using namespace std;

class zop {
public:
    
    vector<int> dp;

    void showres(int s, int n, vector<vector<int>> list)
    {
        //s, n 背包容量和物品总数
        for (int i = 0; i <= s; i++) dp.push_back(0);//初始化二维数组
        for (int i = 0; i < n; i++)//循环每个物品，逆序遍历j执行状态转移方程
        {
            for (int j = s; j >= list[i][0]; j--)
            {
                dp[j] = max(dp[j], dp[j - list[i][0]] + list[i][1]);
            }
            for (int j = 0; j <= s; j++) cout << dp[j];
            cout << endl;   
        }
        cout << dp[s];
    }
};

//int main() {
//    zop test;
//    int s = 10;
//    int n = 3;
//    vector<vector<int>> list = { {5,1}, {6,2}, {4,1} };
//    test.showres(s, n, list);
//    return 0;
//}