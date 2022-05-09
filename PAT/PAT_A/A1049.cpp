/*
1049. Counting Ones (30)
时间限制
100 ms
内存限制
65536 kB
代码长度限制
16000 B
The task is simple: given any positive integer N, you are supposed to count the total number of 1's in 
the decimal form of the integers from 1 to N. For example, given N being 12, there are five 1's in 1, 
10, 11, and 12.

Input Specification:
Each input file contains one test case which gives the positive N (<=230).

Output Specification:
For each test case, print the number of 1's in one line.

Sample Input:
12

Sample Output:
5
*/


// abcdef
// c位出现1的次数:
// c > 1 : ab*1000 + 1*1000 
// c == 1 : ab*1000 + (def+1)
// c == 0 : ab*1000

#include <iostream>
using namespace std;

int main(){
    int n,sum = 0;
    cin >> n;
    for(int cnt=1,low=0,high=n; high > 0; cnt*=10, low=n%cnt, high=n/cnt){
        if(high%10 > 1) sum += cnt;
        else if(high%10 == 1) sum += low+1;
        sum += high/10*cnt;
    }
    printf("%d",sum);
    return 0;
}