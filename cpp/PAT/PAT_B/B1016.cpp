/*
1016. 部分A+B （15）
正整数 A 的“DA（为 1 位整数）部分”定义为由 A 中所有 DA组成的新整数 PA​​ 。
例如：给定 A=3862767，DA=6，则 A 的“6 部分”P​A是 66，因为 A 中有 2 个 6。
现给定 A、D​A、B、DB，请编写程序计算 PA+P​B​。

输入格式：
输入在一行中依次给出 A、D​A、B、D​B，中间以空格分隔，其中 0<A,B<10^10。

输出格式：
在一行中输出 PA+P​B 的值。

输入样例 1：
3862767 6 13530293 3

输出样例 1：
399

输入样例 2：
3862767 1 13530293 8

输出样例 2：
0
*/

#include <iostream>
#include <cstring>

int main(){
    char num[2][11], d[2];
    int p[2] = {0, 0};
    scanf("%s %c %s %c", num[0], &d[0], num[1], &d[1]);
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < strlen(num[i]); j++){
            if(num[i][j] == d[i]){
                p[i] = p[i] * 10 + (d[i]- '0');
            }
        }
    }
    printf("%d", p[0] + p[1]);

    return 0;
}