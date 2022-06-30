/*
1068. Find More Coins (30)
时间限制
150 ms
内存限制
65536 kB
代码长度限制
16000 B
Eva loves to collect coins from all over the universe, including some other planets like Mars. One day she visited a universal shopping mall 
which could accept all kinds of coins as payments. However, there was a special requirement of the payment: for each bill, she must pay the 
exact amount. Since she has as many as 10^4 coins with her, she definitely needs your help. You are supposed to tell her, for any given amount 
of money, whether or not she can find some coins to pay for it.

Input Specification:
Each input file contains one test case. For each case, the first line contains 2 positive numbers: N (<=10^4, the total number of coins) and 
M(<=10^2, the amount of money Eva has to pay). The second line contains N face values of the coins, which are all positive numbers. All the 
numbers in a line are separated by a space.

Output Specification:
For each test case, print in one line the face values V1 <= V2 <= ... <= Vk such that V1 + V2 + ... + Vk = M. All the numbers must be 
separated by a space, and there must be no extra space at the end of the line. If such a solution is not unique, output the smallest sequence. 
If there is no solution, output "No Solution" instead.
Note: sequence {A[1], A[2], ...} is said to be "smaller" than sequence {B[1], B[2], ...} if there exists k >= 1 such that A[i]=B[i] for all 
i < k, and A[k] < B[k].

Sample Input 1:
8 9
5 9 8 7 2 3 4 1
Sample Output 1:
1 3 5

Sample Input 2:
4 8
7 2 4 3

Sample Output 2:
No Solution
*/

#include <iostream>
#include <algorithm>
using namespace std;
int a[10001], dp[101],dpp[10001][101],r[10001];

bool cmp(int a, int b){
    return a > b;
}

int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }
    sort(a,a+n,cmp);
    for(int i = 0; i < n; i++){
        for(int j = m; j >= a[i]; j--){
            if(dp[j] <= dp[j-a[i]] + a[i]){
                dp[j] = dp[j-a[i]] + a[i];
                dpp[i][j] = 1;
            }
        }
    }
    if(dp[m] == m){
        int p = 0;
        for(int i = n, j = m ; j > 0; i--){
            if(dpp[i][j]){
                r[p++] = a[i];
                j -= a[i];
            }
        }
        for(int i = 0; i < p; i++){
            printf("%d%c", r[i], (i==p-1)?'\n':' ');
        }
    }else{
        printf("No Solution");
    }
    return 0;
}