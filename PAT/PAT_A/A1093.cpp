/*
1093. Count PAT's (25)
时间限制
120 ms
内存限制
65536 kB
代码长度限制
16000 B
The string APPAPT contains two PAT's as substrings. The first one is formed by the 2nd, the 4th, and the 6th characters, and the second one 
is formed by the 3rd, the 4th, and the 6th characters.
Now given any string, you are supposed to tell the number of PAT's contained in the string.

Input Specification:
Each input file contains one test case. For each case, there is only one line giving a string of no more than 105 characters containing 
only P, A, or T.

Output Specification:
For each test case, print in one line the number of PAT's contained in the string. Since the result may be a huge number, you only have to 
output the result moded by 1000000007.

Sample Input:
APPAPT

Sample Output:
2
*/

#include <iostream>
#include <cstring>
using namespace std;
const int MAXN = 1000000007;
char s[100005];
int dp_P[100001],dp_T[100001];
int main(){
    int n, cnt = 0;
    gets(s+1);
    n = strlen(s+1) + 1;
    for(int i = 1; i < n; i++){
        dp_P[i] = dp_P[i-1] + (s[i]=='P' ? 1 : 0);
    }
    for(int i = n-1; i >= 1; i--){
        dp_T[i] = dp_T[i+1] + (s[i]=='T' ? 1 : 0);
    }
    for(int i = 1; i < n; i++){
        if(s[i] == 'A') cnt += dp_P[i] * dp_T[i];
        if(cnt > MAXN) cnt %= MAXN;
    }
    printf("%d", cnt);
    return 0;
}