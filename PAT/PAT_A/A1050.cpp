/*
1050. String Subtraction (20)
时间限制
100 ms
内存限制
65536 kB
代码长度限制
16000 B
Given two strings S1 and S2, S = S1 - S2 is defined to be the remaining string after taking all the 
characters in S2 from S1. Your task is simply to calculate S1 - S2 for any given strings. However, 
it might not be that simple to do it fast.

Input Specification:
Each input file contains one test case. Each case consists of two lines which gives S1 and S2, 
respectively. The string lengths of both strings are no more than 10^4. It is guaranteed that all 
the characters are visible ASCII codes and white space, and a new line character signals the end 
of a string.

Output Specification:
For each test case, print S1 - S2 in one line.

Sample Input:
They are students.
aeiou
Sample Output:
Thy r stdnts.
*/

#include <iostream>
#include <cstring>
int mp[128] = {0};
int main(){
    char a[10001],b[10001];
    gets(a);
    gets(b);
    for(int bl = strlen(b),i = 0; i < bl; i++){
        mp[b[i]] = 1;
    }
    for(int al =strlen(a),i = 0; i < al+1;i++){
        if(mp[a[i]] == 0) printf("%c",a[i]);
    }
    return 0;
}