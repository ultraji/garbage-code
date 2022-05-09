/*
1034 有理数四则运算 （20 分）
本题要求编写程序，计算 2 个有理数的和、差、积、商。

输入格式：
输入在一行中按照 a1/b1 a2/b2 的格式给出两个分数形式的有理数，其中分子和分母全是整型范围内的整数，负号只
可能出现在分子前，分母不为 0。

输出格式：
分别在 4 行中按照 有理数1 运算符 有理数2 = 结果 的格式顺序输出 2 个有理数的和、差、积、商。注意输出的每
个有理数必须是该有理数的最简形式 k a/b，其中 k 是整数部分，a/b 是最简分数部分；若为负数，则须加括号；若
除法分母为 0，则输出 Inf。题目保证正确的输出中没有超过整型范围的整数。

输入样例 1：
2/3 -4/2

输出样例 1：
2/3 + (-2) = (-1 1/3)
2/3 - (-2) = 2 2/3
2/3 * (-2) = (-1 1/3)
2/3 / (-2) = (-1/3)

输入样例 2：
5/3 0/6

输出样例 2：
1 2/3 + 0 = 1 2/3
1 2/3 - 0 = 1 2/3
1 2/3 * 0 = 0
1 2/3 / 0 = Inf
*/

#include <iostream>
#include <cstring>

// abs 是 int 的 !!!
#define ABS(x) ((x) < 0 ? (-x): (x))

char a[100], b[100], c[100];

long long gcd(long long a, long long b)
{
    long long r;
    if(b == 0){
        return a;
    }
    while(a % b != 0) {
        r = a % b;
        a = b;
        b = r;
    }
    return b;
}

char* tsf(long long a, long long b, char* num){
    long long t = 1, sign = 1;
    memset(num, 0, 100);
    if(a == 0){
        sprintf(num, "0");
        return num;
    }
    sign = a / ABS(a) * b / ABS(b);
    // 化成最简
    t = gcd(a, b);
    a = ABS(a / t);
    b = ABS(b / t);
    if(sign < 0){
        sprintf(num, "(-");
    }
    if(b == 1){
        sprintf(num + strlen(num), "%lld", a);
    }else{
        if(a / b != 0){
            sprintf(num + strlen(num), "%lld ", a / b);
        }
        sprintf(num + strlen(num), "%lld/%lld", a % b, b); 
    }
    if(sign < 0){
        sprintf(num + strlen(num), ")");
    }
    return num;
}

int main()
{
    long long a1, b1, a2, b2;
    scanf("%lld/%lld %lld/%lld", &a1, &b1, &a2, &b2);
    tsf(a1, b1, a);
    tsf(a2, b2, b);
    printf("%s + %s = %s\n", a, b, tsf(a1*b2+a2*b1, b1*b2, c));
    printf("%s - %s = %s\n", a, b, tsf(a1*b2-a2*b1, b1*b2, c));
    printf("%s * %s = %s\n", a, b, tsf(a1*a2, b1*b2, c));
    printf("%s / %s = %s\n", a, b, a2 == 0 ? "Inf" : tsf(a1*b2, b1*a2, c));
    return 0;
}
