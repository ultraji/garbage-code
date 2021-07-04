/*
1117. Eddington Number(25)
时间限制
250 ms
内存限制
65536 kB
代码长度限制
16000 B
British astronomer Eddington liked to ride a bike. It is said that in order to show off his skill, he has even defined an "Eddington number", 
E -- that is, the maximum integer E such that it is for E days that one rides more than E miles. Eddington's own E was 87.
Now given everyday's distances that one rides for N days, you are supposed to find the corresponding E (<=N).

Input Specification:
Each input file contains one test case. For each case, the first line gives a positive integer N(<=10^5), the days of continuous riding. Then 
N non-negative integers are given in the next line, being the riding distances of everyday.

Output Specification:
For each case, print in a line the Eddington number for these N days.

Sample Input:
10
6 7 6 9 3 10 8 2 7 8

Sample Output:
6
*/

#include <iostream>
#include <algorithm>
using namespace std;
bool cmp(int a,int b){
    return a > b;
}
int a[100001];
int main(){
    int n, i;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a,a+n,cmp);
    for(i = 0; i < n && a[i] > i+1; i++);
    printf("%d",i);
    return 0;
}