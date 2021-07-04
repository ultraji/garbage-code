/*
1040. Longest Symmetric String (25)
时间限制
400 ms
内存限制
65536 kB
代码长度限制
16000 B
Given a string, you are supposed to output the length of the longest symmetric sub-string. For example, given "Is PAT&TAP 
symmetric?", the longest symmetric sub-string is "s PAT&TAP s", hence you must output 11.

Input Specification:
Each input file contains one test case which gives a non-empty string of length no more than 1000.

Output Specification:
For each test case, simply print the maximum length in a line.

Sample Input:
Is PAT&TAP symmetric?

Sample Output:
11
*/

#include <iostream>
#include <cstring>
using namespace std;
char str[1001];
int dp[1001][1001];
int main(){
    int n,maxlen = 0;
    gets(str);
    n = strlen(str);
    for(int i = 0; i < n; i++){     
        for(int j = i; j >= 0; j--){
            if(str[j] == str[i] && ( i-j < 2 || dp[j+1][i-1])){
                dp[j][i] = 1;
                maxlen =  max(maxlen,i-j+1);
            }
        }
    }
    printf("%d\n",maxlen);
    return 0;
}