/*
1022. D进制的A+B (20)
输入两个非负 10 进制整数 A 和 B ( ≤ 2^30−1)，输出 A+B 的 D (1<D≤10)进制数。

输入格式：
输入在一行中依次给出 3 个整数 A、B 和 D。

输出格式：
输出 A+B 的 D 进制数。

输入样例：
123 456 8

输出样例：
1103

*/

#include <iostream>
using namespace std;

int num[32];

int main()
{
    int a, b, d, k = 0;
    cin >> a >> b >> d;
    a = a + b;
    do{
        num[k++] = a % d;
        a /= d;
    }while (a != 0);
    for(int i = k-1; i >= 0; i--){
        cout << num[i];
    }

    return 0;
}
