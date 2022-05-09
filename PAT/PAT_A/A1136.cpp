/*
1136. A Delayed Palindrome (20)
时间限制
400 ms
内存限制
65536 kB
代码长度限制
16000 B
Consider a positive integer N written in standard notation with k+1 digits ai as ak...a1a0 with 0 <= ai < 10 for all i and ak > 0. Then N is 
palindromic if and only if ai = ak-i for all i. Zero is written 0 and is also palindromic by definition.
Non-palindromic numbers can be paired with palindromic ones via a series of operations. First, the non-palindromic number is reversed and the 
result is added to the original number. If the result is not a palindromic number, this is repeated until it gives a palindromic number. Such 
number is called a delayed palindrome. (Quoted from https://en.wikipedia.org/wiki/Palindromic_number)
Given any positive integer, you are supposed to find its paired palindromic number.

Input Specification:
Each input file contains one test case which gives a positive integer no more than 1000 digits.

Output Specification:
For each test case, print line by line the process of finding the palindromic number. The format of each line is the following:
A + B = C
where A is the original number, B is the reversed A, and C is their sum. A starts being the input number, and this process ends until C 
becomes a palindromic number -- in this case we print in the last line "C is a palindromic number."; or if a palindromic number cannot be 
found in 10 iterations, print "Not found in 10 iterations." instead.

Sample Input 1:
97152
Sample Output 1:
97152 + 25179 = 122331
122331 + 133221 = 255552
255552 is a palindromic number.

Sample Input 2:
196
Sample Output 2:
196 + 691 = 887
887 + 788 = 1675
1675 + 5761 = 7436
7436 + 6347 = 13783
13783 + 38731 = 52514
52514 + 41525 = 94039
94039 + 93049 = 187088
187088 + 880781 = 1067869
1067869 + 9687601 = 10755470
10755470 + 07455701 = 18211171
Not found in 10 iterations.
*/

//特殊情况：输入 1, 直接输出 1 is a palindromic number.

#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
bool isPali(char c[]){
    for(int i = 0, j = strlen(c)-1; i < j; i++,j--){
        if(c[i] != c[j]) return false;
    }
    return true;
}

void add(char a[]){
    char b[2000];
    int c = 0, n = strlen(a),tmp;
    strcpy(b,a);
    reverse(a,a+n);
    printf("%s + %s = " , b, a);
    for(int i = 0; i < n; i++){
        tmp = a[i] + b[i] + c - '0' * 2;
        c = tmp / 10;
        a[i] = tmp % 10 + '0';
    }
    if(c != 0) a[n++] = c + '0';
    a[n] = '\0';
    reverse(a,a+n);
    printf("%s\n" ,a);
}

int main(){
    char a[2000];
    int i;
    gets(a);
    for(i = 0; i < 10 && !isPali(a); i++){
        add(a);
    }
    if(i != 10){
        printf("%s is a palindromic number.",a);
    }else{
        printf("Not found in 10 iterations.");
    }
    return 0;
}