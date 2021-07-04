/*
1050 螺旋矩阵 （25 分）
本题要求将给定的 N 个正整数按非递增的顺序，填入“螺旋矩阵”。所谓“螺旋矩阵”，是指从左上角第 1 个格子开始，按顺时
针螺旋方向填充。要求矩阵的规模为 m 行 n 列，满足条件：m×n 等于 N；m≥n；且 m−n 取所有可能值中的最小值。

输入格式：
输入在第 1 行中给出一个正整数 N，第 2 行给出 N 个待填充的正整数。所有数字不超过 10^4，相邻数字以空格分隔。

输出格式：
输出螺旋矩阵。每行 n 个数字，共 m 行。相邻数字以 1 个空格分隔，行末不得有多余空格。

输入样例：
12
37 76 20 98 76 42 53 95 60 81 58 93

输出样例：
98 95 93
42 37 81
53 20 76
58 60 76
*/
#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(int a, int b){
    return a > b;
}

int num[10002];
int d[4][2] = {{0,+1}, {+1,0}, {0,-1}, {-1,0}};

int main(){
    int k, m, n, a, b;
    
    cin >> k;
    for(n = sqrt(k); k % n != 0; n--);
    m = k / n;   
    for(int i = 0; i < k; i++){
        scanf("%d", &num[i]);
    }
    sort(num, num+k, cmp);
    vector<vector<int> > mtx(m, vector<int>(n));
    int xs = 0, ys = 0, xe = n-1, ye = m-1;
    for(int i = 0, x = 0, y = 0, t = 0; i < k; i++, y += d[t][0], x += d[t][1] ){
        mtx[y][x] = num[i];
        if(x + d[t][1] > xe){
            ys ++;
        }else if(y + d[t][0] > ye){
            xe --;
        }else if(x + d[t][1] < xs){
            ye --;
        }else if(y + d[t][0] < ys){
            xs ++;
        }
        if(x + d[t][1] > xe || y + d[t][0] > ye || x + d[t][1] < xs || y + d[t][0] < ys){
            t = (t+1)%4;
        }
    }
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            printf("%d%c", mtx[i][j], j == n-1?'\n':' ');
        }
    }
    return 0;
}