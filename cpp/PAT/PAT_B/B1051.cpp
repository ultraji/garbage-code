/*
1051 复数乘法 （15 分）
复数可以写成 (A+Bi) 的常规形式，其中 A 是实部，B 是虚部，i 是虚数单位，满足 i^2 =−1；也可以写成极坐
标下的指数形式 (R×e^(Pi))，其中 R 是复数模，P 是辐角，i 是虚数单位，其等价于三角形式 (R(cos(P)+isin(P))。

现给定两个复数的 R 和 P，要求输出两数乘积的常规形式。

输入格式：
输入在一行中依次给出两个复数的 R1, P1, R2, P2，数字间以空格分隔。

输出格式：
在一行中按照 A+Bi 的格式输出两数乘积的常规形式，实部和虚部均保留 2 位小数。注意：如果 B 是负数，则应该
写成 A-|B|i 的形式。

输入样例：
2.3 3.5 5.2 0.4

输出样例：
-8.68-8.23i
*/

// Tip: 比如说 -0.004 应该被四舍五入为 0.00
#include <iostream>
#include <iomanip>
#include <math.h>
#define IS_ZERO(x) ((x > -0.005 && x < 0.001) ? 0.001: x)
using namespace std;

int main()
{
    double r1, p1, r2, p2, r3, p3, a, b;
    cin >> r1 >> p1 >> r2 >> p2;
    r3 = r1 * r2;
    p3 = p1 + p2;
    a = IS_ZERO(r3 * cos(p3));
    b = IS_ZERO(r3 * sin(p3));
    if(b > 0){
        cout << fixed << setprecision(2) << a << '+' << b << 'i';
    }else{
        cout << fixed << setprecision(2) << a << b << 'i';
    }
    return 0;
}
