/*
1005. Spell It Right (20)
时间限制
400 ms
内存限制
65536 kB
代码长度限制
16000 B
Given a non-negative integer N, your task is to compute the sum of all the digits of N, and output every 
digit of the sum in English.

Input Specification:
Each input file contains one test case. Each case occupies one line which contains an N (<= 10100).

Output Specification:
For each test case, output in one line the digits of the sum in English words. There must be one space between two consecutive words, but no extra space at the end of a line.

Sample Input:
12345

Sample Output:
one five
*/

#include <iostream>
#include <cstring>
using namespace std;
const char num[10][8] = {"zero","one","two","three","four","five","six","seven","eight","nine"};
char str[110];
int a[110];

int main(){
    int n,sum = 0;
    gets(str);
    n = strlen(str);
    for(int i = 0; i < n; i++){
        sum += str[i]-'0';
    }
    int k = 0;
    while(sum > 0){
        a[k++] = sum%10;
        sum /= 10;
    }
    for(int i = k-1; i > 0; i--){
        printf("%s ",num[a[i]]);
    }
    printf("%s\n",num[a[0]]);
    return 0;
}