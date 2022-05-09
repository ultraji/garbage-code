/*
1024. Palindromic Number (25)
时间限制
400 ms
内存限制
65536 kB
代码长度限制
16000 B
A number that will be the same when it is written forwards or backwards is known as a Palindromic Number. 
For example, 1234321 is a palindromic number. All single digit numbers are palindromic numbers.
Non-palindromic numbers can be paired with palindromic ones via a series of operations. First, the 
non-palindromic number is reversed and the result is added to the original number. If the result is not a 
palindromic number, this is repeated until it gives a palindromic number. For example, if we start from 67, 
we can obtain a palindromic number in 2 steps: 67 + 76 = 143, and 143 + 341 = 484.
Given any positive integer N, you are supposed to find its paired palindromic number and the number of 
steps taken to find it.

Input Specification:
Each input file contains one test case. Each case consists of two positive numbers N and K, where 
N (<= 1010) is the initial numer and K (<= 100) is the maximum number of steps. The numbers are separated 
by a space.

Output Specification:
For each test case, output two numbers, one in each line. The first number is the paired palindromic number 
of N, and the second number is the number of steps taken to find the palindromic number. If the palindromic 
number is not found after K steps, just output the number obtained at the Kth step and K instead.

Sample Input 1:
67 3
Sample Output 1:
484
2

Sample Input 2:
69 3
Sample Output 2:
1353
3
*/

#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

void add(char a[],char b[]){
    if(strlen(a) < 9){
        int num = atoi(a)+atoi(b);
        sprintf(a,"%d",num);
    }else{
        int c = 0,j = strlen(a);
        for(int i = 0; i < j; i++){
            a[i] = a[i]-'0'+b[i]-'0' + c;
            c = a[i]/10;
            a[i] = a[i]%10 + '0';
        }
        if(c != 0){
            a[j++] = c + '0';
            a[j] = '\0';
        }
        reverse(a,a+strlen(a));
    }
}

bool isPal(char a[]){
    for(int i = 0,j = strlen(a) - 1; i < j; i++,j--){
        if(a[i] != a[j]) return false;
    }
    return true;
}

int main(){
    char a[520],b[520];
    int n;
    //freopen("in/in.txt","r",stdin);
    scanf("%s %d",a,&n);
    int i = 0;
    for(; i < n && !isPal(a); i++){
        strcpy(b,a);
        reverse(b,b+strlen(b));
        add(a,b);
    }
    puts(a);
    printf("%d\n",i);
    return 0;
}