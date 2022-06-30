/*
1015. Reversible Primes (20)
时间限制
400 ms
内存限制
65536 kB
代码长度限制
16000 B
A reversible prime in any number system is a prime whose "reverse" in that number system is also a 
prime. For example in the decimal system 73 is a reversible prime because its reverse 37 is also a 
prime.Now given any two positive integers N (< 105) and D (1 < D <= 10), you are supposed to tell if N 
is a reversible prime with radix D.

Input Specification:
The input file consists of several test cases. Each case occupies a line which contains two integers N 
and D. The input is finished by a negative N.

Output Specification:
For each test case, print in one line "Yes" if N is a reversible prime with radix D, or "No" if not.

Sample Input:
73 10
23 2
23 10
-2

Sample Output:
Yes
Yes
No
*/

#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

bool isPrime(int n){
    if(n < 2) return false;
    for(int i = 2; i <= sqrt(n); i++){
        if(n%i == 0) return false;
    }
    return true;
}

int string2num(char a[],int d){
    int sum = 0;
    for(int i = 0; i < strlen(a); i++){
        sum = sum*d+a[i]-'0';
    }
    return sum;
}

bool fun(int n,int d){
    char a[50];
    int i = 0,t = n;
    while(t > 0){
        a[i++] = t%d+'0';
        t /= d;
    }
    a[i] = '\0';
    int n1 = string2num(a,d);
    if(isPrime(n1) && isPrime(n)){
        return true;
    }else{
        return false;
    }
}

int main(){
    int n,d;
    //freopen("in/in.txt","r",stdin);
    while(scanf("%d",&n) && n >= 0){
        scanf("%d",&d);
        if(fun(n,d)){
            printf("Yes\n");
        }else{
            printf("No\n");
        }
    }
    return 0;
}