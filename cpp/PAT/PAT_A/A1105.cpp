/*
1105. Spiral Matrix (25)
时间限制
150 ms
内存限制
65536 kB
代码长度限制
16000 B
This time your job is to fill a sequence of N positive integers into a spiral matrix in non-increasing order. A spiral matrix is filled in 
from the first element at the upper-left corner, then move in a clockwise spiral. The matrix has m rows and n columns, where m and n satisfy 
the following: m*n must be equal to N; m>=n; and m-n is the minimum of all the possible values.

Input Specification:
Each input file contains one test case. For each case, the first line gives a positive integer N. Then the next line contains N positive 
integers to be filled into the spiral matrix. All the numbers are no more than 10^4. The numbers in a line are separated by spaces.

Output Specification:
For each test case, output the resulting matrix in m lines, each contains n numbers. There must be exactly 1 space between two adjacent 
numbers, and no extra space at the end of each line.

Sample Input:
12
37 76 20 98 76 42 53 95 60 81 58 93

Sample Output:
98 95 93
42 37 81
53 20 76
58 60 76
*/

#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int mat[10000][10000], a[10000];
int dx[4] = {1,0,-1,0},dy[4] = {0,1,0,-1};
int main(){
    int n, cm, cn, xs = 0, ys = 0, xe, ye, x = 0, y = 0;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    sort(a,a+n);
    reverse(a,a+n);
    cn = sqrt(n);
    while(n % cn != 0) cn--;
    cm = n / cn;
    ye = cm - 1;
    xe = cn - 1;
    for(int i = 0, j = 0; i < n; i++){
        mat[y][x] = a[i];
        x = x + dx[j];
        y = y + dy[j];
        if(j == 0 && x > xe){
            j = (j+1)%4;
            ys ++;
            x = x-1;
            y = y+1;
        }
        if(j == 1 && y > ye){
            j = (j+1)%4;
            xe --;
            x = x-1;
            y = y-1;
        }
        if(j == 2 && x < xs){
            j = (j+1)%4;
            ye --;
            x = x+1;
            y = y-1;
        }
        if(j == 3 && y < ys){
            j = (j+1)%4;
            xs ++;
            x = x+1;
            y = y+1;
        }
    }
    for(int i = 0; i < cm; i++){
        for(int j = 0; j < cn; j++){
            printf("%d%c", mat[i][j], (j==cn-1)?'\n':' ');
        }
    }
    return 0;
}