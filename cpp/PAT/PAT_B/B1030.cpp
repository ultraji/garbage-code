/*
1030 完美数列 （25 分）
给定一个正整数数列，和正整数 p，设这个数列中的最大值是 M，最小值是 m，如果 M≤mp，则称这个数列是完美数列。

现在给定参数 p 和一些正整数，请你从中选择尽可能多的数构成一个完美数列。

输入格式：
输入第一行给出两个正整数 N 和 p，其中 N（≤10^5）是输入的正整数的个数，p（≤10^9）是给定的参数。第二行给
出 N 个正整数，每个数不超过 10^​9。

输出格式：
在一行中输出最多可以选择多少个数可以用它们组成一个完美数列。

输入样例：
10 8
2 3 20 4 5 1 6 7 8 9
输出样例：
8
*/

#include <iostream>
#include <algorithm>
using namespace std;

double num[100005];

int main()
{
    int n, p, len = 1;
    scanf("%d %d", &n, &p);
    for (int i = 0; i < n; i++){
        scanf("%lf", &num[i]);
    }
    sort(num, num+n);
    for (int i = 0; i < n; i++){
        int j = i + len;
        if(j == n){
            break;
        }
        for (; j < n && num[j] <=  num[i] * p; j++);
        if(len < j - i){
            len = j - i;
        }
    }
    printf("%d", len);
    return 0;
}
