/*
1062 最简分数 （20 分）
一个分数一般写成两个整数相除的形式：N/M，其中 M 不为0。最简分数是指分子和分母没有公约数的分数表示形式。

现给定两个不相等的正分数 N1/M1 和 N2/M2，要求你按从小到大的顺序列出它们之间分母为 K 的最简分数。

输入格式：
输入在一行中按 N/M 的格式给出两个正分数，随后是一个正整数分母 K，其间以空格分隔。题目保证给出的所有整数都
不超过 1000。

输出格式：
在一行中按 N/M 的格式列出两个给定分数之间分母为 K 的所有最简分数，按从小到大的顺序，其间以 1 个空格分隔。
行首尾不得有多余空格。题目保证至少有 1 个输出。

输入样例：
7/18 13/20 12

输出样例：
5/12 7/12
*/

#include <iostream>
#include <vector>
using namespace std;

int gcd(int a, int b){
    return b == 0 ? a : gcd(b, a % b);
}

int main(){
    double a1, b1, a2, b2, s, e;
    int k;
    vector<int> v;
    scanf("%lf/%lf %lf/%lf %d", &a1, &b1, &a2, &b2, &k);
    if(a1/b1 < a2/b2){
        s = a1/b1;
        e = a2/b2;
    }else
    {
        e = a1/b1;
        s = a2/b2;
    }
    for(int i = 1; i <= k; i++){
        if(gcd(i, k) == 1 && 1.0*i/k > s && 1.0*i/k < e){
            v.push_back(i);
        }
    }
    for(int i = 0; i < v.size(); i++){
        printf("%d/%d%c", v[i], k, i==v.size()-1?'\n':' ');
    }
    return 0;
}