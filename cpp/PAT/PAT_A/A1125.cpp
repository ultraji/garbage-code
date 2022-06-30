/*
1125. Chain the Ropes (25)
时间限制
200 ms
内存限制
65536 kB
代码长度限制
16000 B
Given some segments of rope, you are supposed to chain them into one rope. Each time you may only fold two segments into loops and chain them 
into one piece, as shown by the figure. The resulting chain will be treated as another segment of rope and can be folded again. After each 
chaining, the lengths of the original two segments will be halved.
Your job is to make the longest possible rope out of N given segments.

Input Specification:
Each input file contains one test case. For each case, the first line gives a positive integer N (2 <= N <= 10^4). Then N positive integer 
lengths of the segments are given in the next line, separated by spaces. All the integers are no more than 10^4.

Output Specification:
For each case, print in a line the length of the longest possible rope that can be made by the given segments. The result must be rounded 
to the nearest integer that is no greater than the maximum length.

Sample Input:
8
10 15 12 3 4 13 1 15

Sample Output:
14
*/

#include <iostream>
#include <algorithm>
using namespace std;
int a[10001];
int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a,a+n);
    for(int i = 0; i < n-1; i++){
        a[i+1] = (a[i]+a[i+1])/2;
    }
    printf("%d",a[n-1]);
    return 0;
}