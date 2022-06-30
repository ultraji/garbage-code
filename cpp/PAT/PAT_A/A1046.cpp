/*
1046. Shortest Distance (20)
时间限制
100 ms
内存限制
65536 kB
代码长度限制
16000 B
The task is really simple: given N exits on a highway which forms a simple cycle, you are supposed to 
tell the shortest distance between any pair of exits.

Input Specification:
Each input file contains one test case. For each case, the first line contains an integer N (in [3, 105]), 
followed by N integer distances D1 D2 ... DN, where Di is the distance between the i-th and the (i+1)-st 
exits, and DN is between the N-th and the 1st exits. All the numbers in a line are separated by a space. 
The second line gives a positive integer M (<=104), with M lines follow, each contains a pair of exit 
numbers, provided that the exits are numbered from 1 to N. It is guaranteed that the total round trip 
distance is no more than 107.

Output Specification:
For each test case, print your results in M lines, each contains the shortest distance between the 
corresponding given pair of exits.

Sample Input:
5 1 2 4 14 9
3
1 3
2 5
4 1

Sample Output:
3
10
7
*/

//dp[i] 存 i 到 1 的距离
#include <iostream>
#include <algorithm>
using namespace std;
int arr[100001],dp[100001];
int main(){
    int N,M,s,e,sum = 0,shun,ni;
    cin >> N;
    for(int i = 1; i <= N ; i++){
        cin >> arr[i];
        dp[i] = sum;
        sum += arr[i];
    }
    cin >> M;
    while(M--){
        cin >> s >> e;
        if(s > e) swap(s,e);
        shun = dp[e] - dp[s];
        ni = sum - shun;
        printf("%d\n",min(shun,ni));
    }
    return 0;
}